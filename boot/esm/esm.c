/****************************************************
* @file         esm.h
 * @author      jschaller
 * @date        10.09.2025
 * @version     1.0
 * @brief       Module which handles alls ESM Bootloader functions
 ***************************************************/

#include <zephyr/kernel.h>

#include "bootutil/bootutil_log.h"

#include "base_pwr.h"
#include "sd_card.h"
#include "zephyr/fs/fs.h"
#include "zephyr/storage/flash_map.h"
#include <zephyr/dfu/flash_img.h>
#include <zephyr/dfu/mcuboot.h>

#include "src/bootutil_priv.h"


BOOT_LOG_MODULE_REGISTER(esm);

#define FW_FILE_PATH "/SD:/fw_update"

uint8_t img_buf[256];

bool boot_is_img_slot0_confirmed(void)
{
	struct boot_swap_state state;
	const struct flash_area *fa;
	int rc;

	rc = flash_area_open(FIXED_PARTITION_ID(slot0_partition), &fa);
	if (rc) {
		return false;
	}

	rc = boot_read_swap_state(fa, &state);
	if (rc != 0) {
		return false;
	}

	if (state.magic == BOOT_MAGIC_UNSET) {
		/* This is initial/preprogramed image.
		 * Such image can neither be reverted nor physically confirmed.
		 * Treat this image as confirmed which ensures consistency
		 * with `boot_write_img_confirmed...()` procedures.
		 */
		return true;
	}

	return state.image_ok == BOOT_FLAG_SET;
}

int boot_write_img_slot0_confirmed(void)
{
	const struct flash_area *fa;
	int rc = 0;

	if (flash_area_open(FIXED_PARTITION_ID(slot0_partition), &fa) != 0) {
		return -EIO;
	}

	rc = boot_set_next(fa, true, true);

	flash_area_close(fa);

	return rc;
}

int turn_on_pwr_p() {

	base_pwr_init();
	base_pwr_set(0, true);

	return 0;
}
SYS_INIT_NAMED(TURN_ON_PWR_P, turn_on_pwr_p, POST_KERNEL, 41);


void esm_boot_routine()
{
	if (!boot_is_img_slot0_confirmed()) {
		LOG_INF("Slot0 IMG Confirmed.");
		boot_write_img_slot0_confirmed();
	}

	util_sd_card_init();


	struct fs_dirent dirent;
	if (!fs_stat(FW_FILE_PATH, &dirent)) {
		LOG_INF("Detected Firmware to update...");

		// Update FW

		LOG_INF("Erasing slot1 image");
		int err = boot_erase_img_bank(FIXED_PARTITION_ID(slot1_partition));
		if (err) {
			LOG_ERR("Erasing old slot1 image failed: %d", err);
		}

		struct flash_img_context ctx;

		err = flash_img_init(&ctx);
		if (err) {
			LOG_ERR("flash_img_init_id failed: %d", err);
		}

		struct fs_file_t file;
		fs_file_t_init(&file);
		err = fs_open(&file, FW_FILE_PATH, FS_O_READ);
		if (err < 0) {
			LOG_ERR("Failed to open FW file (%d)", err);
		}

		LOG_INF("Moving Firmware Image from SD-Card to slot1");
		uint32_t size = 0;
		while (size = fs_read(&file, img_buf, sizeof(img_buf))) {
			// LOG_INF("Reading FW file %d bytes", size);

			err = flash_img_buffered_write(&ctx, img_buf, size, false);
			if (err) {
				LOG_ERR("flash_img_buffered_write failed: %d", err);
			}
		}

		err = flash_img_buffered_write(&ctx, NULL, 0, true);
		if (err) {
			LOG_ERR("flash_img_buffered_write FLUSH failed: %d", err);
		}

		if (fs_unlink(FW_FILE_PATH)) LOG_ERR("Can't delete old fw_update file");

		LOG_INF("Requested Firmware Upgrade");
		boot_request_upgrade(BOOT_UPGRADE_TEST);
	}
}

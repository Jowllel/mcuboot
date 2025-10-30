/****************************************************
 * @file        sd_card.c
 * @author      jschaller
 * @date        04.11.2024
 * @brief       Module which provides functions to init and control sd card.
 ***************************************************/

#include <zephyr/kernel.h>
#include <zephyr/storage/disk_access.h>
#include "bootutil/bootutil_log.h"
#include <zephyr/fs/fs.h>
#include <zephyr/logging/log_ctrl.h>
#include <ff.h>
// #include "utils/devices.h"

#include "sd_card.h"

#include "devices.h"
#include "esm.h"
#include "zephyr/drivers/rtc.h"


static FATFS fat_fs;

static struct fs_mount_t mp = {
    .type = FS_FATFS,
    .fs_data = &fat_fs,
};

static const char *disk_mount_pt = DISK_MOUNT_PT;

BOOT_LOG_MODULE_REGISTER(sd_card);

int  util_sd_card_init(void) {
    /* raw disk i/o */
    do {
        static const char *disk_pdrv = DISK_DRIVE_NAME;
        uint64_t memory_size_mb;
        uint32_t block_count;
        uint32_t block_size;

        if (disk_access_ioctl(disk_pdrv,
                              DISK_IOCTL_CTRL_INIT, NULL) != 0) {
            LOG_ERR("Storage init ERROR!");
            LOG_ERR("No SD-Card detected...");
            LOG_ERR("Shutting down");
            k_panic();
            break;
        }

        if (disk_access_ioctl(disk_pdrv,
                              DISK_IOCTL_GET_SECTOR_COUNT, &block_count)) {
            LOG_ERR("Unable to get sector count");
            break;
        }
        // LOG_INF("Block count %u", block_count);

        if (disk_access_ioctl(disk_pdrv,
                              DISK_IOCTL_GET_SECTOR_SIZE, &block_size)) {
            LOG_ERR("Unable to get sector size");
            break;
        }
        // LOG_INF("Sector size %u", block_size);

        memory_size_mb = (uint64_t) block_count * block_size;
        // LOG_INF("Memory Size(MB) %u", (uint32_t)(memory_size_mb >> 20));

        if (disk_access_ioctl(disk_pdrv,
                              DISK_IOCTL_CTRL_DEINIT, NULL) != 0) {
            LOG_ERR("Storage deinit ERROR!");
            break;
        }
    } while (0);

    mp.mnt_point = disk_mount_pt;

    if (fs_mount(&mp) != 0) {
        LOG_ERR("Mount ERROR!");
    }

    log_backend_enable(log_backend_get_by_name("log_backend_fs"), NULL, LOG_LEVEL_DBG);
    return 0;
}



uint32_t get_fattime (void)
{

    struct rtc_time rtctime;
    rtc_get_time(rtc, &rtctime);

    return (rtctime.tm_year - 80) << 25 |
           (rtctime.tm_mon + 1) << 21 |
           (rtctime.tm_mday) << 16 |
           (rtctime.tm_hour) << 11 |
           (rtctime.tm_min) << 5 |
           (rtctime.tm_sec) >> 1;
}

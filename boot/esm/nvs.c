/****************************************************
* @file         nvs.c
 * @author      jschaller
 * @date        10.09.2025
 * @version     1.0
 * @brief       Module which controls NVS Variables
 ***************************************************/

#include "nvs.h"

#include <zephyr/fs/nvs.h>
#include <zephyr/kernel.h>
#include "zephyr/drivers/flash.h"
#include "zephyr/logging/log.h"
#include <zephyr/storage/flash_map.h>
#include "devices.h"

LOG_MODULE_REGISTER(util_nvs, LOG_LEVEL_DBG);

static struct nvs_fs fs;

#define NVS_PARTITION		       storage_partition
#define NVS_PARTITION_DEVICE	 stmflash
#define NVS_PARTITION_OFFSET	 FIXED_PARTITION_OFFSET(NVS_PARTITION)
#define NVS_PARTITION_SIZE	   FIXED_PARTITION_SIZE(NVS_PARTITION)

uint8_t pwd[PASSWORD_SIZE];

int util_nvs_init(void) {
 struct flash_pages_info info;
 fs.flash_device = NVS_PARTITION_DEVICE;
 if (!device_is_ready(fs.flash_device)) {
  LOG_ERR("Flash device %s is not ready", fs.flash_device->name);
  return -1;
 }
 fs.offset = NVS_PARTITION_OFFSET;
 int rc = flash_get_page_info_by_offs(fs.flash_device, fs.offset, &info);
 if (rc) {
  LOG_ERR("Unable to get page info, rc=%d", rc);
  return -1;
 }
 fs.sector_size = info.size;
 fs.sector_count = NVS_PARTITION_SIZE / fs.sector_size;

 // LOG_INF("Flash Device: %s, Flash Offset: 0x%X, Sector Size: 0x%X, Sector count: %d", fs.flash_device->name, fs.offset, fs.sector_size, fs.sector_count);

 rc = nvs_mount(&fs);
 if (rc) {
  LOG_ERR("Flash Init failed, rc=%d", rc);
  return -1;
 }

 return 0;
}

void util_nvs_low_power_state_set(uint8_t state) {
 int err = nvs_write(&fs, LOW_POWER_ID, &state, LOW_POWER_SIZE);
 if (err < 0) {
   LOG_ERR("Unable to set low power state, err %d", err);
 }
}

uint8_t util_nvs_low_power_state_get() {
 uint8_t state;
 int err = nvs_read(&fs, LOW_POWER_ID, &state, LOW_POWER_SIZE);
 if (err <= 0) {
  LOG_ERR("Unable to get low power state, err %d", err);
  return -1;
 } else {
  return state;
 }
}

int util_nvs_password_set(uint8_t *pwdd) {
 if (strlen(pwdd) > PASSWORD_SIZE)
 {
  return -1;
 }
 int err = nvs_write(&fs, PASSWORD_ID, pwdd, strlen(pwdd));
 if (err < 0) {
  LOG_ERR("Unable to set password, err %d", err);
  return -1;
 }
 return 0;
}

void util_nvs_password_get() {
 int err = nvs_read(&fs, PASSWORD_ID, pwd, PASSWORD_SIZE);
 if (err <= 0)
 {
  LOG_ERR("Unable to get password, err %d", err);
 }
}

void util_nvs_image_check_state_set(uint8_t state) {
 int err = nvs_write(&fs, IMAGE_CHECK_ID, &state, IMAGE_CHECK_SIZE);
 if (err < 0) {
  LOG_ERR("Unable to set image check state, err %d", err);
 }
}

uint8_t util_nvs_image_check_state_get() {
 uint8_t state;
 int err = nvs_read(&fs, IMAGE_CHECK_ID, &state, IMAGE_CHECK_SIZE);
 if (err <= 0) {
  LOG_ERR("Unable to get image check state, err %d", err);
  return -1;
 } else {
  return state;
 }
}
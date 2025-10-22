/****************************************************
 * @file        sd_card.h
 * @author      jschaller
 * @date        04.11.2024
 * @brief       Module which provides functions to init and control sd card.
 ***************************************************/

#ifndef SD_CARD_H
#define SD_CARD_H

int util_sd_card_init(void);

uint32_t get_fattime (void);

#define DISK_DRIVE_NAME "SD"
#define DISK_MOUNT_PT "/"DISK_DRIVE_NAME":"
#define MAX_PATH 128

#endif //SD_CARD_H

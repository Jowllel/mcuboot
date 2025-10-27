/****************************************************
* @file         nvs.h
 * @author      jschaller
 * @date        10.09.2025
 * @version     1.0
 * @brief       Module which controls NVS Variables
 ***************************************************/

#ifndef NVS_H
#define NVS_H

#include "zephyr/kernel.h"
#include "zephyr/fs/nvs.h"

#define LOW_POWER_STATE_NORMAL 0
#define LOW_POWER_STATE_TRIG 1
#define LOW_POWER_STATE_ON 2

#define LOW_POWER_ID 1
#define LOW_POWER_SIZE 1

#define PASSWORD_ID 2
#define PASSWORD_SIZE 32

#define IMAGE_CHECK_STATE_TEST 0
#define IMAGE_CHECK_STATE_TESTED_OK 1
#define IMAGE_CHECK_STATE_CONFIRMED 2
#define IMAGE_CHECK_STATE_UNKNOWN 3

#define IMAGE_CHECK_ID 3
#define IMAGE_CHECK_SIZE 1

extern uint8_t pwd[PASSWORD_SIZE];

int util_nvs_init(void);

void util_nvs_low_power_state_set(uint8_t state);
uint8_t util_nvs_low_power_state_get();

int util_nvs_password_set(uint8_t *pwd);
void util_nvs_password_get();

void util_nvs_image_check_state_set(uint8_t state);
uint8_t util_nvs_image_check_state_get();

#endif //NVS_H

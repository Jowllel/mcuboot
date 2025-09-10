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

#define LOW_POWER_STATE_OFF 0
#define LOW_POWER_STATE_TRIG 1

void util_nvs_init(void);
void util_nvs_low_power_state_set(uint8_t state);
uint8_t util_nvs_low_power_state_get();

#endif //NVS_H

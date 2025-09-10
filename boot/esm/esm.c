/****************************************************
* @file         esm.h
 * @author      jschaller
 * @date        10.09.2025
 * @version     1.0
 * @brief       Module which handles alls ESM Bootloader functions
 ***************************************************/

#include <zephyr/kernel.h>

#include "bootutil/bootutil_log.h"

#include "nvs.h"

BOOT_LOG_MODULE_REGISTER(esm);

void esm_boot_routine()
{
	util_nvs_init();

	if(util_nvs_low_power_state_get())
	{
		LOG_INF("Entering Low Power Mode !!!!");
		util_nvs_low_power_state_set(LOW_POWER_STATE_OFF);
	}
}
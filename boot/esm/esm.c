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


BOOT_LOG_MODULE_REGISTER(esm);


void esm_boot_routine()
{
	base_pwr_init();
	base_pwr_set(0, true);
}

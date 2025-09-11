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
#include "base_pwr.h"

BOOT_LOG_MODULE_REGISTER(esm);


void esm_boot_routine()
{
	util_nvs_init();
	base_pwr_init();

	switch(util_nvs_low_power_state_get())
	{
		case LOW_POWER_STATE_TRIG:
			LOG_INF("Entering Low Power Mode !!!!");
			util_nvs_low_power_state_set(LOW_POWER_STATE_ON);

			base_pwr_set(1, false);
			base_pwr_set(2, false);
			base_pwr_set(3, false);
			
			base_pwr_set(0, false);
			
			//Enter Standby Mode
			SET_BIT(PWR->PMCR, PWR_PMCR_LPMS);
			SET_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));
			__DSB();
			__ISB();
			__WFI();
			
			break;
			
		case LOW_POWER_STATE_ON:
			base_pwr_set(0, true);
			break;
	}
}

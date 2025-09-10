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


void HAL_PWR_EnterSTANDBYMode(void)
{
 /* Select STANDBY mode */
 SET_BIT(PWR->PMCR, PWR_PMCR_LPMS);

 /* Set SLEEPDEEP bit of Cortex System Control Register */
 SET_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));

 /* Wait For all memory accesses to complete before continuing */
 __DSB();

 /* Ensure that the processor pipeline is flushed */
 __ISB();

 /* Wait For Interrupt Request */
 __WFI();
}

void esm_boot_routine()
{
	util_nvs_init();

	if(util_nvs_low_power_state_get())
	{
		LOG_INF("Entering Low Power Mode !!!!");
		util_nvs_low_power_state_set(LOW_POWER_STATE_OFF);
		
		base_pwr_init();

		base_pwr_set(1, false);
		base_pwr_set(2, false);
		base_pwr_set(3, false);
		
		base_pwr_set(0, false);
		
		HAL_PWR_EnterSTANDBYMode();
	}
}
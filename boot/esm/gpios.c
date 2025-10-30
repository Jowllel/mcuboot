/****************************************************
 * @file        gpios.c
 * @author      jschaller
 * @date        15.10.2025
 * @brief       Module which controls the GPIOs
 ***************************************************/

#include "gpios.h"
#include <zephyr/drivers/gpio.h>
#include "devices.h"
#include <zephyr/logging/log.h>

#include "devices.h"

LOG_MODULE_REGISTER(gpios, LOG_LEVEL_DBG);

int gpios_init(void) {

    /* LEDs */
    if (!gpio_is_ready_dt(&ledpwrr)) {
        LOG_ERR("ledpwrr GPIO port is not ready.");
    }
    if (gpio_pin_configure_dt(&ledpwrr, GPIO_OUTPUT_INACTIVE)) {
        LOG_ERR("ledpwrr configure Error.");
    }

    if (!gpio_is_ready_dt(&ledpwrg)) {
        LOG_ERR("ledpwrg GPIO port is not ready.");
    }
    if (gpio_pin_configure_dt(&ledpwrg, GPIO_OUTPUT_INACTIVE)) {
        LOG_ERR("ledpwrg configure Error.");
    }

    if (!gpio_is_ready_dt(&ledstater)) {
        LOG_ERR("ledstater GPIO port is not ready.");
    }
    if (gpio_pin_configure_dt(&ledstater, GPIO_OUTPUT_INACTIVE)) {
        LOG_ERR("ledstater configure Error.");
    }

    if (!gpio_is_ready_dt(&ledstateg)) {
        LOG_ERR("ledstateg GPIO port is not ready.");
    }
    if (gpio_pin_configure_dt(&ledstateg, GPIO_OUTPUT_INACTIVE)) {
        LOG_ERR("ledstateg configure Error.");
    }

    if (!gpio_is_ready_dt(&ledserialr)) {
        LOG_ERR("ledserialr GPIO port is not ready.");
    }
    if (gpio_pin_configure_dt(&ledserialr, GPIO_OUTPUT_INACTIVE)) {
        LOG_ERR("ledserialr configure Error.");
    }

    if (!gpio_is_ready_dt(&ledserialg)) {
        LOG_ERR("ledserialg GPIO port is not ready.");
    }
    if (gpio_pin_configure_dt(&ledserialg, GPIO_OUTPUT_INACTIVE)) {
        LOG_ERR("ledserialg configure Error.");
    }

    if (!gpio_is_ready_dt(&ledusbr)) {
        LOG_ERR("ledusbr GPIO port is not ready.");
    }
    if (gpio_pin_configure_dt(&ledusbr, GPIO_OUTPUT_INACTIVE)) {
        LOG_ERR("ledusbr configure Error.");
    }

    if (!gpio_is_ready_dt(&ledusbg)) {
        LOG_ERR("ledusbg GPIO port is not ready.");
    }
    if (gpio_pin_configure_dt(&ledusbg, GPIO_OUTPUT_INACTIVE)) {
        LOG_ERR("ledusbg configure Error.");
    }

    if (!gpio_is_ready_dt(&ledsdr)) {
        LOG_ERR("ledsdr GPIO port is not ready.");
    }
    if (gpio_pin_configure_dt(&ledsdr, GPIO_OUTPUT_INACTIVE)) {
        LOG_ERR("ledsdr configure Error.");
    }

    if (!gpio_is_ready_dt(&ledsdg)) {
        LOG_ERR("ledsdg GPIO port is not ready.");
    }
    if (gpio_pin_configure_dt(&ledsdg, GPIO_OUTPUT_INACTIVE)) {
        LOG_ERR("ledsdg configure Error.");
    }

    if (!gpio_is_ready_dt(&enpwrpclk)) {
        LOG_ERR("enpwrpclk GPIO port is not ready.");
    }
    if (gpio_pin_configure_dt(&enpwrpclk, GPIO_OUTPUT_INACTIVE)) {
        LOG_ERR("enpwrpclk configure Error.");
    }

    if (!gpio_is_ready_dt(&enpwrpdat)) {
        LOG_ERR("enpwrpdat GPIO port is not ready.");
    }
    if (gpio_pin_configure_dt(&enpwrpdat, GPIO_OUTPUT_INACTIVE)) {
        LOG_ERR("enpwrpdat configure Error.");
    }

    if (!gpio_is_ready_dt(&enpwr1clk)) {
        LOG_ERR("enpwr1clk GPIO port is not ready.");
    }
    if (gpio_pin_configure_dt(&enpwr1clk, GPIO_OUTPUT_INACTIVE)) {
        LOG_ERR("enpwr1clk configure Error.");
    }

    if (!gpio_is_ready_dt(&enpwr1dat)) {
        LOG_ERR("enpwr1dat GPIO port is not ready.");
    }
    if (gpio_pin_configure_dt(&enpwr1dat, GPIO_OUTPUT_INACTIVE)) {
        LOG_ERR("enpwr1dat configure Error.");
    }

    if (!gpio_is_ready_dt(&enpwr2clk)) {
        LOG_ERR("enpwr2clk GPIO port is not ready.");
    }
    if (gpio_pin_configure_dt(&enpwr2clk, GPIO_OUTPUT_INACTIVE)) {
        LOG_ERR("enpwr2clk configure Error.");
    }

    if (!gpio_is_ready_dt(&enpwr2dat)) {
        LOG_ERR("enpwr2dat GPIO port is not ready.");
    }
    if (gpio_pin_configure_dt(&enpwr2dat, GPIO_OUTPUT_INACTIVE)) {
        LOG_ERR("enpwr2dat configure Error.");
    }

    if (!gpio_is_ready_dt(&enpwr3clk)) {
        LOG_ERR("enpwr3clk GPIO port is not ready.");
    }
    if (gpio_pin_configure_dt(&enpwr3clk, GPIO_OUTPUT_INACTIVE)) {
        LOG_ERR("enpwr3clk configure Error.");
    }

    if (!gpio_is_ready_dt(&enpwr3dat)) {
        LOG_ERR("enpwr3dat GPIO port is not ready.");
    }
    if (gpio_pin_configure_dt(&enpwr3dat, GPIO_OUTPUT_INACTIVE)) {
        LOG_ERR("enpwr3dat configure Error.");
    }

    return 0;
}
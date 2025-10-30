/****************************************************
* @file         base_pwr.c
 * @author      jschaller
 * @date        07.11.2024
 * @version     1.0
 * @brief       Module which provides functions to init and control power lines for esm base.
 ***************************************************/

#include "base_pwr.h"

#include <zephyr/logging/log.h>
#include "zephyr/drivers/gpio.h"
#include "devices.h"

LOG_MODULE_REGISTER(base_pwr, LOG_LEVEL_DBG);

int base_pwr_init(void) {
    base_pwr_set(1, true);
    base_pwr_set(2, true);
    base_pwr_set(3, true);
    return 0;
}

void base_pwr_set(int id, bool state) {
    int err = 0;
    switch (id) {
        case 0:
            err = gpio_pin_set_dt(&enpwrpdat, state);
            if (err != 0) {
                LOG_ERR("Setting GPIO pin level failed: %d\n", err);
            }
            k_usleep(1);

            err = gpio_pin_set_dt(&enpwrpclk, 1);
            if (err != 0) {
                LOG_ERR("Setting GPIO pin level failed: %d\n", err);
            }
            k_usleep(1);

            err = gpio_pin_set_dt(&enpwrpclk, 0);
            if (err != 0) {
                LOG_ERR("Setting GPIO pin level failed: %d\n", err);
            }
            break;
        case 1:
            err = gpio_pin_set_dt(&enpwr1dat, state);
            if (err != 0) {
                LOG_ERR("Setting GPIO pin level failed: %d\n", err);
            }
            k_usleep(1);

            err = gpio_pin_set_dt(&enpwr1clk, 1);
            if (err != 0) {
                LOG_ERR("Setting GPIO pin level failed: %d\n", err);
            }
            k_usleep(1);

            err = gpio_pin_set_dt(&enpwr1clk, 0);
            if (err != 0) {
                LOG_ERR("Setting GPIO pin level failed: %d\n", err);
            }
            break;
        case 2:
            err = gpio_pin_set_dt(&enpwr2dat, state);
            if (err != 0) {
                LOG_ERR("Setting GPIO pin level failed: %d\n", err);
            }
            k_usleep(1);

            err = gpio_pin_set_dt(&enpwr2clk, 1);
            if (err != 0) {
                LOG_ERR("Setting GPIO pin level failed: %d\n", err);
            }
            k_usleep(1);

            err = gpio_pin_set_dt(&enpwr2clk, 0);
            if (err != 0) {
                LOG_ERR("Setting GPIO pin level failed: %d\n", err);
            }
            break;
        case 3:
            err = gpio_pin_set_dt(&enpwr3dat, state);
            if (err != 0) {
                LOG_ERR("Setting GPIO pin level failed: %d\n", err);
            }
            k_usleep(1);

            err = gpio_pin_set_dt(&enpwr3clk, 1);
            if (err != 0) {
                LOG_ERR("Setting GPIO pin level failed: %d\n", err);
            }
            k_usleep(1);

            err = gpio_pin_set_dt(&enpwr3clk, 0);
            if (err != 0) {
                LOG_ERR("Setting GPIO pin level failed: %d\n", err);
            }
            break;
    }
}

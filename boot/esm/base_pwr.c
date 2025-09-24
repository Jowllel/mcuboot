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

LOG_MODULE_REGISTER(base_pwr, LOG_LEVEL_DBG);

static const struct gpio_dt_spec en_pwr1_dat =
    GPIO_DT_SPEC_GET_OR(DT_ALIAS(enpwr1dat), gpios, {0});
static const struct gpio_dt_spec en_pwr1_clk =
    GPIO_DT_SPEC_GET_OR(DT_ALIAS(enpwr1clk), gpios, {0});

static const struct gpio_dt_spec en_pwr2_dat =
    GPIO_DT_SPEC_GET_OR(DT_ALIAS(enpwr2dat), gpios, {0});
static const struct gpio_dt_spec en_pwr2_clk =
    GPIO_DT_SPEC_GET_OR(DT_ALIAS(enpwr2clk), gpios, {0});

static const struct gpio_dt_spec en_pwr3_dat =
    GPIO_DT_SPEC_GET_OR(DT_ALIAS(enpwr3dat), gpios, {0});
static const struct gpio_dt_spec en_pwr3_clk =
    GPIO_DT_SPEC_GET_OR(DT_ALIAS(enpwr3clk), gpios, {0});

static const struct gpio_dt_spec en_pwr_p_dat =
    GPIO_DT_SPEC_GET_OR(DT_ALIAS(enpwrpdat), gpios, {0});
static const struct gpio_dt_spec en_pwr_p_clk =
    GPIO_DT_SPEC_GET_OR(DT_ALIAS(enpwrpclk), gpios, {0});


void base_pwr_set(int id, bool state) {
    int err = 0;
    switch (id) {
        case 0:
            err = gpio_pin_set_dt(&en_pwr_p_dat, state);
            if (err != 0) {
                LOG_ERR("Setting GPIO pin level failed: %d\n", err);
            }
            k_usleep(1);

            err = gpio_pin_set_dt(&en_pwr_p_clk, 1);
            if (err != 0) {
                LOG_ERR("Setting GPIO pin level failed: %d\n", err);
            }
            k_usleep(1);

            err = gpio_pin_set_dt(&en_pwr_p_clk, 0);
            if (err != 0) {
                LOG_ERR("Setting GPIO pin level failed: %d\n", err);
            }
            break;
        case 1:
            err = gpio_pin_set_dt(&en_pwr1_dat, state);
            if (err != 0) {
                LOG_ERR("Setting GPIO pin level failed: %d\n", err);
            }
            k_usleep(1);

            err = gpio_pin_set_dt(&en_pwr1_clk, 1);
            if (err != 0) {
                LOG_ERR("Setting GPIO pin level failed: %d\n", err);
            }
            k_usleep(1);

            err = gpio_pin_set_dt(&en_pwr1_clk, 0);
            if (err != 0) {
                LOG_ERR("Setting GPIO pin level failed: %d\n", err);
            }
            break;
        case 2:
            err = gpio_pin_set_dt(&en_pwr2_dat, state);
            if (err != 0) {
                LOG_ERR("Setting GPIO pin level failed: %d\n", err);
            }
            k_usleep(1);

            err = gpio_pin_set_dt(&en_pwr2_clk, 1);
            if (err != 0) {
                LOG_ERR("Setting GPIO pin level failed: %d\n", err);
            }
            k_usleep(1);

            err = gpio_pin_set_dt(&en_pwr2_clk, 0);
            if (err != 0) {
                LOG_ERR("Setting GPIO pin level failed: %d\n", err);
            }
            break;
        case 3:
            err = gpio_pin_set_dt(&en_pwr3_dat, state);
            if (err != 0) {
                LOG_ERR("Setting GPIO pin level failed: %d\n", err);
            }
            k_usleep(1);

            err = gpio_pin_set_dt(&en_pwr3_clk, 1);
            if (err != 0) {
                LOG_ERR("Setting GPIO pin level failed: %d\n", err);
            }
            k_usleep(1);

            err = gpio_pin_set_dt(&en_pwr3_clk, 0);
            if (err != 0) {
                LOG_ERR("Setting GPIO pin level failed: %d\n", err);
            }
            break;
    }
}

void base_pwr_init(void) {

    if (!gpio_is_ready_dt(&en_pwr1_dat)) {
        LOG_ERR("The load switch pin GPIO port is not ready.\n");
    }

    int err = gpio_pin_configure_dt(&en_pwr1_dat, GPIO_OUTPUT_INACTIVE);
    if (err != 0) {
        LOG_ERR("Configuring GPIO pin failed: %d\n", err);
    }

    if (!gpio_is_ready_dt(&en_pwr1_clk)) {
        LOG_ERR("The load switch pin GPIO port is not ready.\n");
    }

    err = gpio_pin_configure_dt(&en_pwr1_clk, GPIO_OUTPUT_INACTIVE);
    if (err != 0) {
        LOG_ERR("Configuring GPIO pin failed: %d\n", err);
    }

    if (!gpio_is_ready_dt(&en_pwr2_dat)) {
        LOG_ERR("The load switch pin GPIO port is not ready.\n");
    }

    err = gpio_pin_configure_dt(&en_pwr2_dat, GPIO_OUTPUT_INACTIVE);
    if (err != 0) {
        LOG_ERR("Configuring GPIO pin failed: %d\n", err);
    }

    if (!gpio_is_ready_dt(&en_pwr2_clk)) {
        LOG_ERR("The load switch pin GPIO port is not ready.\n");
    }

    err = gpio_pin_configure_dt(&en_pwr2_clk, GPIO_OUTPUT_INACTIVE);
    if (err != 0) {
        LOG_ERR("Configuring GPIO pin failed: %d\n", err);
    }

    if (!gpio_is_ready_dt(&en_pwr3_dat)) {
        LOG_ERR("The load switch pin GPIO port is not ready.\n");
    }

    err = gpio_pin_configure_dt(&en_pwr3_dat, GPIO_OUTPUT_INACTIVE);
    if (err != 0) {
        LOG_ERR("Configuring GPIO pin failed: %d\n", err);
    }

    if (!gpio_is_ready_dt(&en_pwr3_clk)) {
        LOG_ERR("The load switch pin GPIO port is not ready.\n");
    }

    err = gpio_pin_configure_dt(&en_pwr3_clk, GPIO_OUTPUT_INACTIVE);
    if (err != 0) {
        LOG_ERR("Configuring GPIO pin failed: %d\n", err);
    }

    err = gpio_pin_configure_dt(&en_pwr_p_dat, GPIO_OUTPUT_INACTIVE);
    if (err != 0) {
        LOG_ERR("Configuring GPIO pin failed: %d\n", err);
    }

    if (!gpio_is_ready_dt(&en_pwr_p_clk)) {
        LOG_ERR("The load switch pin GPIO port is not ready.\n");
    }

    err = gpio_pin_configure_dt(&en_pwr_p_clk, GPIO_OUTPUT_INACTIVE);
    if (err != 0) {
        LOG_ERR("Configuring GPIO pin failed: %d\n", err);
    }
}
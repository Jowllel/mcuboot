/****************************************************
 * @file        led.c
 * @author      jschaller
 * @date        13.02.2025
 * @brief       functions to control and init the leds
 ***************************************************/

#include "led.h"

#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/logging/log.h>
#include "devices.h"

LOG_MODULE_REGISTER(util_led, LOG_LEVEL_INF);


void util_led_state_set(led_color color) {
    switch (color) {
        case LED_RED:
            gpio_pin_set_dt(&ledstater, 1);
            gpio_pin_set_dt(&ledstateg, 0);
            break;
        case LED_GREEN:
            gpio_pin_set_dt(&ledstater, 0);
            gpio_pin_set_dt(&ledstateg, 1);
            break;
        case LED_ORANGE:
            gpio_pin_set_dt(&ledstater, 1);
            gpio_pin_set_dt(&ledstateg, 1);
            break;
        default:
            gpio_pin_set_dt(&ledstater, 0);
            gpio_pin_set_dt(&ledstateg, 0);
    }
}

void util_led_power_set(led_color color) {
    switch (color) {
        case LED_RED:
            gpio_pin_set_dt(&ledpwrr, 1);
            gpio_pin_set_dt(&ledpwrg, 0);
            break;
        case LED_GREEN:
            gpio_pin_set_dt(&ledpwrr, 0);
            gpio_pin_set_dt(&ledpwrg, 1);
            break;
        case LED_ORANGE:
            gpio_pin_set_dt(&ledpwrr, 1);
            gpio_pin_set_dt(&ledpwrg, 1);
            break;
        default:
            gpio_pin_set_dt(&ledpwrr, 0);
            gpio_pin_set_dt(&ledpwrg, 0);
    }
}

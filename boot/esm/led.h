/****************************************************
 * @file        led.h
 * @author      jschaller
 * @date        13.02.2025
 * @brief       functions to control and init the leds
 ***************************************************/

#ifndef LED_H
#define LED_H

typedef enum _led_color {
    LED_OFF = 0,
    LED_RED = 1,
    LED_GREEN = 2,
    LED_ORANGE = 3,
} led_color;

void util_led_state_set(led_color color);
void util_led_power_set(led_color color);

#endif //LED_H

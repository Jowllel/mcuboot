/****************************************************
 * @file        devices.c
 * @author      jschaller
 * @date        15.10.2025
 * @brief       This file stores all device pointers and GPIO specs of the devicetree devices.
 ***************************************************/

#include "devices.h"

/* LEDs */
const struct gpio_dt_spec ledpwrr    = GPIO_DT_SPEC_GET(DT_ALIAS(ledpwrr), gpios);
const struct gpio_dt_spec ledpwrg    = GPIO_DT_SPEC_GET(DT_ALIAS(ledpwrg), gpios);
const struct gpio_dt_spec ledstater  = GPIO_DT_SPEC_GET(DT_ALIAS(ledstater), gpios);
const struct gpio_dt_spec ledstateg  = GPIO_DT_SPEC_GET(DT_ALIAS(ledstateg), gpios);
const struct gpio_dt_spec ledserialr = GPIO_DT_SPEC_GET(DT_ALIAS(ledserialr), gpios);
const struct gpio_dt_spec ledserialg = GPIO_DT_SPEC_GET(DT_ALIAS(ledserialg), gpios);
const struct gpio_dt_spec ledusbr    = GPIO_DT_SPEC_GET(DT_ALIAS(ledusbr), gpios);
const struct gpio_dt_spec ledusbg    = GPIO_DT_SPEC_GET(DT_ALIAS(ledusbg), gpios);
const struct gpio_dt_spec ledsdr     = GPIO_DT_SPEC_GET(DT_ALIAS(ledsdr), gpios);
const struct gpio_dt_spec ledsdg     = GPIO_DT_SPEC_GET(DT_ALIAS(ledsdg), gpios);

/* Buttons / Switches */
const struct device *const buttonuser  = DEVICE_DT_GET(DT_ALIAS(buttonuser));
const struct device *const switchboot1 = DEVICE_DT_GET(DT_ALIAS(switchboot1));

/* GPIOs */
const struct gpio_dt_spec pgood        = GPIO_DT_SPEC_GET(DT_ALIAS(pgood), gpios);
const struct gpio_dt_spec i2csensorint = GPIO_DT_SPEC_GET(DT_ALIAS(i2csensorint), gpios);
const struct gpio_dt_spec dbgpb8       = GPIO_DT_SPEC_GET(DT_ALIAS(dbgpb8), gpios);
const struct gpio_dt_spec dbgpb9       = GPIO_DT_SPEC_GET(DT_ALIAS(dbgpb9), gpios);
const struct gpio_dt_spec dbgpe0       = GPIO_DT_SPEC_GET(DT_ALIAS(dbgpe0), gpios);
const struct gpio_dt_spec dbgpe1       = GPIO_DT_SPEC_GET(DT_ALIAS(dbgpe1), gpios);
const struct gpio_dt_spec dbgpe2       = GPIO_DT_SPEC_GET(DT_ALIAS(dbgpe2), gpios);
const struct gpio_dt_spec dbgpe3       = GPIO_DT_SPEC_GET(DT_ALIAS(dbgpe3), gpios);
const struct gpio_dt_spec dbgpe4       = GPIO_DT_SPEC_GET(DT_ALIAS(dbgpe4), gpios);
const struct gpio_dt_spec dbgpe5       = GPIO_DT_SPEC_GET(DT_ALIAS(dbgpe5), gpios);
const struct gpio_dt_spec dbgpe6       = GPIO_DT_SPEC_GET(DT_ALIAS(dbgpe6), gpios);
const struct gpio_dt_spec enpwrpclk    = GPIO_DT_SPEC_GET(DT_ALIAS(enpwrpclk), gpios);
const struct gpio_dt_spec enpwrpdat    = GPIO_DT_SPEC_GET(DT_ALIAS(enpwrpdat), gpios);
const struct gpio_dt_spec enpwr1clk    = GPIO_DT_SPEC_GET(DT_ALIAS(enpwr1clk), gpios);
const struct gpio_dt_spec enpwr1dat    = GPIO_DT_SPEC_GET(DT_ALIAS(enpwr1dat), gpios);
const struct gpio_dt_spec enpwr2clk    = GPIO_DT_SPEC_GET(DT_ALIAS(enpwr2clk), gpios);
const struct gpio_dt_spec enpwr2dat    = GPIO_DT_SPEC_GET(DT_ALIAS(enpwr2dat), gpios);
const struct gpio_dt_spec enpwr3clk    = GPIO_DT_SPEC_GET(DT_ALIAS(enpwr3clk), gpios);
const struct gpio_dt_spec enpwr3dat    = GPIO_DT_SPEC_GET(DT_ALIAS(enpwr3dat), gpios);
const struct gpio_dt_spec i2csrst      = GPIO_DT_SPEC_GET(DT_ALIAS(i2csrst), gpios);
const struct gpio_dt_spec i2csint      = GPIO_DT_SPEC_GET(DT_ALIAS(i2csint), gpios);
const struct gpio_dt_spec i2cfrst      = GPIO_DT_SPEC_GET(DT_ALIAS(i2cfrst), gpios);
const struct gpio_dt_spec i2cfint      = GPIO_DT_SPEC_GET(DT_ALIAS(i2cfint), gpios);
const struct gpio_dt_spec io1          = GPIO_DT_SPEC_GET(DT_ALIAS(io1), gpios);
const struct gpio_dt_spec io2          = GPIO_DT_SPEC_GET(DT_ALIAS(io2), gpios);
const struct gpio_dt_spec io3          = GPIO_DT_SPEC_GET(DT_ALIAS(io3), gpios);
const struct gpio_dt_spec io4          = GPIO_DT_SPEC_GET(DT_ALIAS(io4), gpios);
const struct gpio_dt_spec hwvar        = GPIO_DT_SPEC_GET(DT_ALIAS(hwvar), gpios);

/* UARTs */
const struct device *const uartserial = DEVICE_DT_GET(DT_ALIAS(uartserial));

/* Other peripherals */
const struct device *const rtc      = DEVICE_DT_GET(DT_ALIAS(rtc));

/* Communication */
const struct device *const mdio    = DEVICE_DT_GET(DT_ALIAS(mdio));
const struct device *const ethphy    = DEVICE_DT_GET(DT_ALIAS(ethphy));

/* Flash */
const struct device *const stmflash  = DEVICE_DT_GET(DT_ALIAS(stmflash));
const struct device *const norflash  = DEVICE_DT_GET(DT_ALIAS(norflash));

/****************************************************
 * @file        devices.h
 * @author      jschaller
 * @date        15.10.2025
 * @brief       This file stores all device pointers and GPIO specs of the devicetree devices.
 ***************************************************/

#ifndef DEVICES_H
#define DEVICES_H

#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

/* LEDs */
extern const struct gpio_dt_spec ledpwrr;
extern const struct gpio_dt_spec ledpwrg;
extern const struct gpio_dt_spec ledstater;
extern const struct gpio_dt_spec ledstateg;
extern const struct gpio_dt_spec ledserialr;
extern const struct gpio_dt_spec ledserialg;
extern const struct gpio_dt_spec ledusbr;
extern const struct gpio_dt_spec ledusbg;
extern const struct gpio_dt_spec ledsdr;
extern const struct gpio_dt_spec ledsdg;

/* Buttons / Switches */
extern const struct device *const buttonuser;
extern const struct device *const switchboot1;

/* GPIOs */
extern const struct gpio_dt_spec pgood;
extern const struct gpio_dt_spec i2csensorint;
extern const struct gpio_dt_spec dbgpb8;
extern const struct gpio_dt_spec dbgpb9;
extern const struct gpio_dt_spec dbgpe0;
extern const struct gpio_dt_spec dbgpe1;
extern const struct gpio_dt_spec dbgpe2;
extern const struct gpio_dt_spec dbgpe3;
extern const struct gpio_dt_spec dbgpe4;
extern const struct gpio_dt_spec dbgpe5;
extern const struct gpio_dt_spec dbgpe6;
extern const struct gpio_dt_spec enpwrpclk;
extern const struct gpio_dt_spec enpwrpdat;
extern const struct gpio_dt_spec enpwr1clk;
extern const struct gpio_dt_spec enpwr1dat;
extern const struct gpio_dt_spec enpwr2clk;
extern const struct gpio_dt_spec enpwr2dat;
extern const struct gpio_dt_spec enpwr3clk;
extern const struct gpio_dt_spec enpwr3dat;
extern const struct gpio_dt_spec i2csrst;
extern const struct gpio_dt_spec i2csint;
extern const struct gpio_dt_spec i2cfrst;
extern const struct gpio_dt_spec i2cfint;
extern const struct gpio_dt_spec io1;
extern const struct gpio_dt_spec io2;
extern const struct gpio_dt_spec io3;
extern const struct gpio_dt_spec io4;
extern const struct gpio_dt_spec hwvar;

/* I2C Peripherals */
extern const struct device *const i2cperi;
extern const struct device *const eeprom;
extern const struct device *const ilps;
extern const struct device *const sht;
extern const struct device *const i2csensor;
extern const struct device *const bi2cf;
extern const struct device *const bi2cs;

/* UARTs */
extern const struct device *const uartserial;
extern const struct device *const uartusb;

/* Other peripherals */
extern const struct device *const rtc;
extern const struct device *const watchdog;

/* Analog / Sensors */
extern const struct device *const vbat;
extern const struct device *const vin;
extern const struct device *const vbus;
extern const struct device *const vref;
extern const struct device *const dietemp;
extern const struct device *const vcore;
extern const struct device *const io1analog;
extern const struct device *const io2analog;
extern const struct device *const io3analog;
extern const struct device *const io4analog;
extern const struct device *const hwver;

/* Communication */
extern const struct device *const mdio;
extern const struct device *const ethphy;

/* Flash */
extern const struct device *const stmflash;
extern const struct device *const norflash;

#endif // DEVICES_H

/****************************************************
* @file         esm.h
 * @author      jschaller
 * @date        10.09.2025
 * @version     1.0
 * @brief       Module which handles alls ESM Bootloader functions
 ***************************************************/

#ifndef ESM_H
#define ESM_H

void esm_boot_routine();
extern const struct device *const rtc;

#endif //ESM_H

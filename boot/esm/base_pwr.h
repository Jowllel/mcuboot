/****************************************************
* @file         base_pwr.h
 * @author      jschaller
 * @date        07.11.2024
 * @version     1.0
 * @brief       Module which provides functions to init and control power lines for esm base.
 ***************************************************/

#ifndef BASE_PWR_H
#define BASE_PWR_H

#include "zephyr/kernel.h"

int base_pwr_init(void);

void base_pwr_set(int id, bool state);

#endif //BASE_PWR_H

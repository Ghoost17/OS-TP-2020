/*
 * Copyright (C) 2016 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License v2.1. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @ingroup     tests
 * @{
 *
 * @file
 * @brief       Test for the on-board LED macros
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 *
 * @}
 */

#include <stdio.h>
#include <stdint.h>

#include "periph/gpio.h"
#include "board.h"
#include "periph_conf.h"



#ifdef CLOCK_CORECLOCK
#define DELAY_SHORT         (CLOCK_CORECLOCK / 25)
#else
#define DELAY_SHORT         (1000UL)
#endif
#define DELAY_LONG          (DELAY_SHORT * 2)



#ifndef BTN0_INT_FLANK
#define BTN0_INT_FLANK  GPIO_BOTH
#endif


static void cb(void *arg)
{
    printf("Pressed BTN%d\n", (int)arg);
    LED0_TOGGLE;
    LED1_TOGGLE;
    
}


void dumb_delay(uint32_t delay)
{
    for (uint32_t i = 0; i < delay; i++) {
        __asm__("nop");
    }
}


int main(void)
{
int cnt = 0;
    gpio_init_int(BTN0_PIN, BTN0_MODE, BTN0_INT_FLANK, cb, (void *)cnt);



   
    while (1)
     {
      


        LED0_ON;
        dumb_delay(DELAY_LONG);
        LED0_OFF;
        dumb_delay(DELAY_LONG);
        LED0_TOGGLE;
        dumb_delay(DELAY_SHORT);
        LED0_TOGGLE;
        dumb_delay(DELAY_SHORT);
        LED0_TOGGLE;
        dumb_delay(DELAY_SHORT);
        LED0_TOGGLE;
        dumb_delay(DELAY_LONG);

        LED1_ON;
        dumb_delay(DELAY_LONG);
        LED1_OFF;
        dumb_delay(DELAY_LONG);
        LED1_TOGGLE;
        dumb_delay(DELAY_SHORT);
        LED1_TOGGLE;
        dumb_delay(DELAY_SHORT);
        LED1_TOGGLE;
        dumb_delay(DELAY_SHORT);
        LED1_TOGGLE;
        dumb_delay(DELAY_LONG);

    }

    

    return 0;
}
//LED1 - bl
//LED0 - gr
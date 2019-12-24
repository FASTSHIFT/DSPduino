#ifndef __DELAY_H
#define __DELAY_H

#ifdef __cplusplus
extern "C" {
#endif

#include "mcu_type.h"

void Delay_Init(void);
uint32_t millis(void);
uint32_t micros(void);
void delay_ms(uint32_t ms);
#define delay_us(us) DSP28x_usDelay(us)

#ifdef __cplusplus
}
#endif

#endif

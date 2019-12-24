#ifndef __GPIO_H
#define __GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "mcu_type.h"

typedef struct{
    uint32_t* GPxAT;
}PinInfo_TypeDef;

#define PIN_MAX 64

#define IS_PIN(Pin) ((Pin)<PIN_MAX)

typedef enum{
    INPUT,
    INPUT_PULLUP,
    OUTPUT,
    OUTPUT_OPEN_DRAIN,
}pinMode_Type;

#ifdef __cplusplus
}
#endif

#endif

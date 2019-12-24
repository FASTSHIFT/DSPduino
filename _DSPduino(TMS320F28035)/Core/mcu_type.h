#ifndef __MCU_TYPE_H
#define __MCU_TYPE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "DSP2803x_Device.h"
#include "DSP2803x_Examples.h"
#include <stdint.h>


#define __TMS320F28035__
#define __DSP2803x__
#define F_CPU 60000000U
#define CYCLES_PER_MICROSECOND (F_CPU / 1000000U)

#ifdef __cplusplus
}
#endif

#endif

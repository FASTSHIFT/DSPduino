/*
 * MIT License
 * Copyright (c) 2019 _VIFEXTech
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef __ARDUINO_H
#define __ARDUINO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "libmaple_types.h"
#include <stdbool.h>
#include "binary.h"
#include "avr/pgmspace.h"

#include "delay.h"
#include "gpio.h"


#define __DSP__
#define ARDUINO 111

#define PI 3.1415926535897932384626433832795f
#define HALF_PI 1.5707963267948966192313216916398f
#define TWO_PI 6.283185307179586476925286766559f
#define DEG_TO_RAD 0.017453292519943295769236907684886f
#define RAD_TO_DEG 57.295779513082320876798154814105f
#define EULER 2.718281828459045235360287471352f

#define SERIAL  0x0
#define DISPLAY 0x1

#define LSBFIRST 0x0
#define MSBFIRST 0x1

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define ABS(x)  (((x)>0)?(x):-(x))//abs(x) is define in stdlib.h
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) ((deg)*DEG_TO_RAD)
#define degrees(rad) ((rad)*RAD_TO_DEG)
#define sq(x)        ((x)*(x))

#define lowByte(w)  ((uint8_t) ((w) & 0xff))
#define highByte(w) ((uint8_t) ((w) >> 8))

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit)  ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))

#define _BV(bit) (1<<(bit))

#define delay(ms)             delay_ms(ms)
#define delayMicroseconds(us) delay_us(us)

#define sei()          EINT
#define cli()          DINT
#define interrupts()   sei()
#define noInterrupts() cli()

#define analogInPinToBit(Pin)       (Pin)
#define digitalPinToInterrupt(Pin)  (Pin)
#define digitalPinToPort(Pin)       (Pin)
#define digitalPinToBitMask(Pin)    ((uint32_t)(1<<((Pin)%32)))
#define portInputRegister(Port)     (volatile uint32_t*)(Port < 32 ? (&GpioDataRegs.GPADAT.all) : (&GpioDataRegs.GPBDAT.all))
#define portOutputRegister(Port)    (volatile uint32_t*)(Port < 32 ? (&GpioDataRegs.GPADAT.all) : (&GpioDataRegs.GPBDAT.all))

#define NOT_A_PIN 0
#define NOT_A_PORT 0
#define NOT_AN_INTERRUPT -1

typedef bool boolean;
typedef unsigned char byte;

typedef enum {LOW = 0, HIGH = !LOW} GPIO_State_Type;
typedef enum {Off = 0, On = !Off} _Switch_Type;
typedef enum {OFF = 0, ON = !OFF} _SWITCH_Type;

void pinMode(uint8_t Pin, pinMode_Type Mode);
void digitalWrite(uint8_t Pin, uint8_t val);
uint8_t digitalRead(uint8_t Pin);
uint16_t analogWrite(uint8_t Pin, uint16_t val);
uint16_t analogRead(uint8_t Pin);
uint16_t analogRead_DMA(uint8_t Pin);
void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t value);
uint32_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint32_t bitOrder);
uint32_t pulseIn(uint32_t Pin, uint32_t State, uint32_t Timeout);

long map(long x, long in_min, long in_max, long out_min, long out_max);
double fmap(double x, double in_min, double in_max, double out_min, double out_max);
void yield(void);

#ifdef __cplusplus
}// extern "C"
#endif

#ifdef __cplusplus
#include "WCharacter.h"
#include "WString.h"
#include "HardwareSerial.h"
#endif

#endif

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
#include "Arduino.h"

#define REG_SET_MASK(REG,MASK) (*REG |= MASK)
#define REG_CLR_MASK(REG,MASK) (*REG &= ~MASK)
#define REG_READ_MASK(REG,MASK) ((*REG & MASK)!=0)

void pinMode(uint8_t Pin, pinMode_Type Mode)
{
    if(!IS_PIN(Pin))
        return;

    volatile uint32_t* GPxMUXx;
    volatile uint32_t* GPxDIR;
    volatile uint32_t* GPxPUD;
    if(Pin < 32)
    {
        GPxMUXx = Pin < 16 ? (uint32_t*)&GpioCtrlRegs.GPAMUX1 : (uint32_t*)&GpioCtrlRegs.GPAMUX2;
        GPxDIR = (uint32_t*)&GpioCtrlRegs.GPADIR;
        GPxPUD = (uint32_t*)&GpioCtrlRegs.GPAPUD;
    }

    uint32_t pinmask = digitalPinToBitMask(Pin);
    uint32_t muxmask = 1 << ((Pin % 16) * 2);

    EALLOW;
    if(Mode == INPUT)
    {

    }
    else if(Mode == INPUT_PULLUP)
    {

    }
    else if(Mode == OUTPUT)
    {
        REG_CLR_MASK(GPxMUXx,muxmask);// All GPIO
        REG_SET_MASK(GPxDIR, pinmask);// outputs
    }
    EDIS;
}

void digitalWrite(uint8_t Pin, uint8_t val)
{
    volatile uint32_t *port = portOutputRegister((digitalPinToPort(Pin)));
    volatile uint32_t pinmask = digitalPinToBitMask(Pin);
    val ? REG_SET_MASK(port, pinmask) : REG_CLR_MASK(port, pinmask);
}

uint8_t digitalRead(uint8_t Pin)
{
    volatile uint32_t *port = portInputRegister((digitalPinToPort(Pin)));
    volatile uint32_t pinmask = digitalPinToBitMask(Pin);
    return REG_READ_MASK(port, pinmask);
}

uint16_t analogWrite(uint8_t Pin, uint16_t val)
{
    return 0;
}

uint16_t analogRead(uint8_t Pin)
{
    return 0;
}

uint16_t analogRead_DMA(uint8_t Pin)
{
    return 0;
}

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t value)
{
    
}

uint32_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint32_t bitOrder)
{
    return 0 ;
}

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


double fmap(double x, double in_min, double in_max, double out_min, double out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

uint32_t pulseIn(uint32_t pin, uint32_t state, uint32_t timeout )
{
   return 0;
}

void yield(void)
{
}

#include "delay.h"

#define SysTick_LoadValue (F_CPU / 1000U)
static volatile uint32_t SysTick_Ms = 0;

interrupt void cpu_timer0_isr(void)
{
    SysTick_Ms++;
    CpuTimer0.InterruptCount = SysTick_Ms;
   // Acknowledge this interrupt to receive more interrupts from group 1
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}


/**
  * @brief  ϵͳ�δ�ʱ����ʼ������ʱ1ms
  * @param  ��
  * @retval ��
  */
void Delay_Init(void)
{
    // Interrupts that are used in this example are re-mapped to
    // ISR functions found within this file.
    EALLOW;  // This is needed to write to EALLOW protected registers
    PieVectTable.TINT0 = &cpu_timer0_isr;
    EDIS;    // This is needed to disable write to EALLOW protected registers

    // Step 4. Initialize the Device Peripheral. This function can be
    //         found in DSP2803x_CpuTimers.c
    InitCpuTimers();   // For this example, only initialize the Cpu Timers
    // Configure CPU-Timer 0 to interrupt every 1 milliseconds:
    // 60MHz CPU Freq, 50 millisecond Period (in uSeconds)
    ConfigCpuTimer(&CpuTimer0, 60, 1000);


    // To ensure precise timing, use write-only instructions to write to the entire register. Therefore, if any
    // of the configuration bits are changed in ConfigCpuTimer and InitCpuTimers (in DSP2803x_CpuTimers.h), the
    // below settings must also be updated.

    CpuTimer0Regs.TCR.all = 0x4001; // Use write-only instruction to set TSS bit = 0

    // Enable CPU INT1 which is connected to CPU-Timer 0:
    IER |= M_INT1;

    // Enable TINT0 in the PIE: Group 1 interrupt 7
    PieCtrlRegs.PIEIER1.bit.INTx7 = 1;

    // Enable global Interrupts and higher priority real-time debug events:
    EINT;   // Enable Global interrupt INTM
    ERTM;   // Enable Global realtime interrupt DBGM
}

/**
  * @brief  ��ȡ��Ƭ�����ϵ����������ĺ�����
  * @param  ��
  * @retval ��ǰϵͳʱ�Ӻ�����
  */
uint32_t millis(void)
{
    return SysTick_Ms;
}

/**
  * @brief  ��ȡ��Ƭ�����ϵ�����������΢����
  * @param  ��
  * @retval ��ǰϵͳʱ��΢����
  */
uint32_t micros(void)
{
    return 0;
}

/**
  * @brief  ���뼶��ʱ
  * @param  ms: Ҫ��ʱ�ĺ�����
  * @retval ��
  */
void delay_ms(uint32_t ms)
{
    volatile uint32_t Stop_TimePoint = SysTick_Ms + ms;
    while(SysTick_Ms < Stop_TimePoint);
}

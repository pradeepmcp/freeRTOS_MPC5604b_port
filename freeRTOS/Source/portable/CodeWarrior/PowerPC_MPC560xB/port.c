/*==================================================================================================
*
*   (c) Copyright 2015 Freescale Semiconductor Inc.
*   
*   This program is free software; you can redistribute it and/or modify it under
*   the terms of the GNU General Public License (version 2) as published by the
*   Free Software Foundation >>>> AND MODIFIED BY <<<< the FreeRTOS exception.
*
*   ***************************************************************************
*   >>!   NOTE: The modification to the GPL is included to allow you to     !<<
*   >>!   distribute a combined work that includes FreeRTOS without being   !<<
*   >>!   obliged to provide the source code for proprietary components     !<<
*   >>!   outside of the FreeRTOS kernel.                                   !<<
*   ***************************************************************************
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*   
*   You should have received a copy of the GNU General Public License
*   along with this program; if not, write to the Free Software
*   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*
==================================================================================================*/


#include "FreeRTOS.h"
#include "task.h"

/*-----------------------------------------------------------*/
#define TICK_INTERVAL  ((configCPU_CLOCK_HZ / configTICK_RATE_HZ ) - 1UL)

/* Definitions to set the initial MSR of each task. */
#define portCRITICAL_INTERRUPT_ENABLE    ( 1UL << 17UL )
#define portEXTERNAL_INTERRUPT_ENABLE    ( 1UL << 15UL )
#define portMACHINE_CHECK_ENABLE         ( 1UL << 12UL )
#define portSPE_PRESENT                  ( 1UL << 25UL )


#if configUSE_FPU
#define portINITIAL_MSR        ( portCRITICAL_INTERRUPT_ENABLE | portEXTERNAL_INTERRUPT_ENABLE | portMACHINE_CHECK_ENABLE | portSPE_PRESENT )
#else
#define portINITIAL_MSR        ( portCRITICAL_INTERRUPT_ENABLE | portEXTERNAL_INTERRUPT_ENABLE | portMACHINE_CHECK_ENABLE )
#endif


//--------------------------------------------------------------------------
// SPR access macros.
#define MTSPR(_spr_, _v_)  asm volatile ("mtspr %0, %1;" :: "I" (_spr_), "r" (_v_));
#define MFSPR(_spr_, _v_)  asm volatile ("mfspr %0, %1;" : "=r" (_v_) : "I" (_spr_));
#define MFMSR(_v_)         asm volatile ("mfmsr %0" : "=r" (_v_) : );

/*
 * The handler for the yield function
 */
 

/*
 * Function to start the scheduler running by starting the highest
 * priority task that has thus far been created.
 */
extern void vPortStartFirstTask( void );

extern void pit_ch0_isr(void);

/*
 * Setup the system timer to generate the tick interrupt.
 */
void prvPortTimerSetup( void );

void vPortTickISR(void);

extern  volatile void *  pxCurrentTCB;
/*-----------------------------------------------------------*/

/*    
 * Initialise the stack of a task to look exactly as if the task had been
 * interrupted.
 * 
 * See the header file portable.h.
 */
portSTACK_TYPE *pxPortInitialiseStack( portSTACK_TYPE *pxTopOfStack, TaskFunction_t pxCode, void *pvParameters )
{
    register portSTACK_TYPE msr, srr1;
    portSTACK_TYPE *pxBackchain;

    MFMSR(msr);
    srr1 = portINITIAL_MSR | msr;

    /* Place a known value at the bottom of the stack for debugging */
	*pxTopOfStack = 0xDEADBEEF;
    pxTopOfStack--;

    /* Create a root frame header */
    *pxTopOfStack = 0x0L; /* Root lr save word */
    pxTopOfStack--;
    *pxTopOfStack = 0x0L; /* Root backchain */
    pxTopOfStack--;

    pxBackchain = pxTopOfStack;

    *pxTopOfStack = 0x1FL;                                                    /* r31  - 0x94 */
    pxTopOfStack--;
    *pxTopOfStack = 0x1EL;                                                    /* r30  - 0x90 */
    pxTopOfStack--;
    *pxTopOfStack = 0x1DL;                                                    /* r29  - 0x8C */
    pxTopOfStack--;
    *pxTopOfStack = 0x1CL;                                                    /* r28  - 0x88 */
    pxTopOfStack--;
    *pxTopOfStack = 0x1BL;                                                    /* r27  - 0x84 */
    pxTopOfStack--;
    *pxTopOfStack = 0x1AL;                                                    /* r26  - 0x80 */
    pxTopOfStack--;
    *pxTopOfStack = 0x19L;                                                    /* r25  - 0x7C */
    pxTopOfStack--;
    *pxTopOfStack = 0x18L;                                                    /* r24  - 0x78 */
    pxTopOfStack--;
    *pxTopOfStack = 0x17L;                                                    /* r23  - 0x74 */
    pxTopOfStack--;
    *pxTopOfStack = 0x16L;                                                    /* r22  - 0x70 */
    pxTopOfStack--;
    *pxTopOfStack = 0x15L;                                                    /* r21  - 0x6C */
    pxTopOfStack--;
    *pxTopOfStack = 0x14L;                                                    /* r20  - 0x68 */
    pxTopOfStack--;
    *pxTopOfStack = 0x13L;                                                    /* r19  - 0x64 */
    pxTopOfStack--;
    *pxTopOfStack = 0x12L;                                                    /* r18  - 0x60 */
    pxTopOfStack--;
    *pxTopOfStack = 0x11L;                                                    /* r17  - 0x5C */
    pxTopOfStack--;
    *pxTopOfStack = 0x10L;                                                    /* r16  - 0x58 */
    pxTopOfStack--;
    *pxTopOfStack = 0xFL;                                                     /* r15  - 0x54 */
    pxTopOfStack--;
    *pxTopOfStack = 0xEL;                                                     /* r14  - 0x50 */
    pxTopOfStack--;
    *pxTopOfStack = 0xCL;                                                     /* r12  - 0x4C */
    pxTopOfStack--;
    *pxTopOfStack = 0xBL;                                                     /* r11  - 0x48 */
    pxTopOfStack--;
    *pxTopOfStack = 0xAL;                                                     /* r10  - 0x44 */
    pxTopOfStack--;
    *pxTopOfStack = 0x9L;                                                     /* r09  - 0x40 */
    pxTopOfStack--;
    *pxTopOfStack = 0x8L;                                                     /* r08  - 0x3C */
    pxTopOfStack--;
    *pxTopOfStack = 0x7L;                                                     /* r07  - 0x38 */
    pxTopOfStack--;
    *pxTopOfStack = 0x6L;                                                     /* r06  - 0x34 */
    pxTopOfStack--;
    *pxTopOfStack = 0x5L;                                                     /* r05  - 0x30 */
    pxTopOfStack--;
    *pxTopOfStack = 0x4L;                                                     /* r04  - 0x2C */
    pxTopOfStack--;
    *pxTopOfStack = ( portSTACK_TYPE ) pvParameters;                          /* r03  - 0x28 */
    pxTopOfStack--;
    *pxTopOfStack = 0x0L;                                                     /* r00  - 0x24 */
    pxTopOfStack--;

    *pxTopOfStack = 0x0L;                                                     /* XER  - 0x20 */
    pxTopOfStack--;

    *pxTopOfStack = 0x0L;                                                     /* CTR  - 0x1C */
    pxTopOfStack--;

    *pxTopOfStack = ( portSTACK_TYPE ) pxCode;                                /* LR   - 0x18 */
    pxTopOfStack--;

    *pxTopOfStack = 0x0L;                                                     /* CR   - 0x14 */
    pxTopOfStack--;

    *pxTopOfStack = srr1;                                                     /* SRR1 - 0x10 */
    pxTopOfStack--;

    *pxTopOfStack = ( portSTACK_TYPE ) pxCode;                                /* SRR0 - 0x0C */
    pxTopOfStack--;

    *pxTopOfStack = 0x0L;                                                     /* Pad - 0x08 */
    pxTopOfStack--;

    *pxTopOfStack = 0x0L;                                                     /* LR save word - 0x04 */
    pxTopOfStack--;

    *pxTopOfStack = ( portSTACK_TYPE ) pxBackchain;                           /* SP(r1) - 0x00 */

    return pxTopOfStack;
}
/*-----------------------------------------------------------*/

portBASE_TYPE xPortStartScheduler( void )
{ 
    prvPortTimerSetup();

    vPortStartFirstTask();

    /* Should not get here as the tasks are now running! */
    return pdFALSE;
}
/*-----------------------------------------------------------*/

void vPortEndScheduler( void )
{
    for(;;)
      {
        portNOP();
      }
}

void vPortTickISR(void)
{
    PIT.CH[TICK_PIT_CHANNEL].TFLG.R = 0x00000001;
    if (xTaskIncrementTick() != pdFALSE)
	{
		#if (configUSE_PREEMPTION == 1)
		vTaskSwitchContext();
		// ISR epilog will pop and restore the new task's context. 
		#endif
	}
}


void prvPortTimerSetup(void)
{
	uint32_t interrupt_enable;
	uint16_t priority;
	uint32_t ld_val;
	
  	interrupt_enable = 1;
	priority = TICK_INTERRUPT_PRIOROTY;
  	ld_val = TICK_INTERVAL;
  	
  	pit_config(vPortTickISR, TICK_PIT_CHANNEL,
  			interrupt_enable, priority, ld_val);
  	PIT_START_TIMER(TICK_PIT_CHANNEL);
}

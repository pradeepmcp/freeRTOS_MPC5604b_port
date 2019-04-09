#ifndef PORTMACRO_H
#define PORTMACRO_H

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

#ifdef __cplusplus
extern "C" {
#endif

/*-----------------------------------------------------------
 * Port specific definitions.  
 *
 * The settings in this file configure FreeRTOS correctly for the
 * given hardware and compiler.
 *
 * These settings should not be altered.
 *-----------------------------------------------------------
 */

#include "pit.h"

/* Type definitions. */
#define portCHAR             char
#define portFLOAT            float
#define portDOUBLE           double
#define portLONG             long
#define portSHORT            short
#define portSTACK_TYPE       unsigned portLONG
#define portBASE_TYPE        portLONG

typedef portSTACK_TYPE StackType_t;
typedef long BaseType_t;
typedef unsigned long UBaseType_t;

#if( configUSE_16_BIT_TICKS == 1 )
    typedef uint16_t TickType_t;
    #define portMAX_DELAY ( TickType_t ) 0xFFFFU
#else
    typedef uint32_t TickType_t;
    #define portMAX_DELAY ( TickType_t ) 0xFFFFFFFFUL

    /* 32-bit tick type on a 32-bit architecture, so reads of the tick count do
    not need to be guarded with a critical section. */
    #define portTICK_TYPE_IS_ATOMIC 1
#endif

/*-----------------------------------------------------------*/

/* Architecture specifics. */

#define portSTACK_GROWTH            ( -1 )
#define portTICK_PERIOD_MS          ((TickType_t)1000 / configTICK_RATE_HZ )        
#define portBYTE_ALIGNMENT          8 /**< PPC EABI requires 8 byte alignment for stack */
#define portNOP()                   asm volatile ( "se_nop" )
/*-----------------------------------------------------------*/    

/* Scheduler utilities. */
#define portYIELD() asm volatile ( "se_sc \n\t se_nop" )

void vPortYield( void );

#define portYIELD_FROM_ISR()                portYIELD()



/*-----------------------------------------------------------*/

/* Interrupt control macros. */
#define portDISABLE_INTERRUPTS()           asm volatile ("wrteei 0 \n msync"); /**< msync ensures we don't execute any instruction until interrupts are disabled */
#define portENABLE_INTERRUPTS()            asm volatile ("msync \n wrteei 1"); /**< msync ensures that all previous instructions completed before we enable the interrupts */

/*-----------------------------------------------------------*/

/* This port uses the critical nesting count from the TCB rather than
maintaining a separate value and then saving this value in the task stack. */
#define portCRITICAL_NESTING_IN_TCB        1

/* Critical section macros. */
void vTaskEnterCritical( void );
void vTaskExitCritical( void );
#define portENTER_CRITICAL()               vTaskEnterCritical()
#define portEXIT_CRITICAL()                vTaskExitCritical()

/*-----------------------------------------------------------*/



/* Task function macros as described on the FreeRTOS.org WEB site. */
#define portTASK_FUNCTION_PROTO( vFunction, pvParameters ) void vFunction( void *pvParameters )
#define portTASK_FUNCTION( vFunction, pvParameters )       void vFunction( void *pvParameters )

#if 0 // Use the definitions in portasm.s
/* Macro to put task stack pointer into the TCB  (r3 used as scratch register) */
#define portPUSH_TASK() {											\
	__asm ("e_lis     r3, pxCurrentTCB@ha");						\
	__asm ("e_lwz     r3, pxCurrentTCB@l(r3)");						\
	__asm ("e_stw    r1, 0x00 (r3)");   /* store stack pointer */	\
}

 /* Macro to get the task stack pointer from the TCB (r3 used as scratch register)*/
#define portPOP_TASK() {											\
	__asm ("e_lis    r3, pxCurrentTCB@ha"); 						\
	__asm ("e_lwz    r3, pxCurrentTCB@l(r3)"); 						\
	__asm ("e_lwz    r1, 0x00 (r3)"); 	/* load stack pointer */	\
}

/* Restores context from task stack */
#define portRESTORE_CONTEXT() {														\
	__asm (" e_lwz     r0,  0x0C (r1) ");    /* Restore SRR0 */						\
	__asm (" mtsrr0    r0 ");														\
	__asm (" e_lwz     r0,  0x10 (r1) ");      /* Restore SRR1 */					\
	__asm (" mtsrr1    r0 ");														\
	__asm (" e_lwz     r0,  0x14 (r1) ");      /* Restore LR */						\
	__asm (" mtlr      r0 ");														\
	__asm (" e_lwz     r0,  0x18 (r1) ");      /* Restore CTR */					\
	__asm (" mtctr     r0 ");														\
	__asm (" e_lwz     r0,  0x1C (r1) ");      /* Restore XER */					\
	__asm (" mtxer     r0 ");														\
	__asm (" e_lwz     r0,  0x20 (r1) ");      /* Restore CR */						\
	__asm (" mtcrf     0xff, r0 ");													\
	__asm (" e_lwz     r5,  0x30 (r1) ");      /* Restore r5 */						\
	__asm (" e_lwz     r6,  0x34 (r1) ");      /* Restore r6 */						\
	__asm (" e_lwz     r7,  0x38 (r1) ");      /* Restore r7 */						\
	__asm (" e_lwz     r8,  0x3C (r1) ");      /* Restore r8 */						\
	__asm (" e_lwz     r9,  0x40 (r1) ");      /* Restore r9 */						\
	__asm (" e_lwz     r10, 0x44 (r1) ");      /* Restore r10 */					\
	__asm (" e_lwz     r11, 0x48 (r1) ");      /* Restore r11 */					\
	__asm (" e_lwz     r12, 0x4C (r1) ");      /* Restore r12 */					\
	__asm (" e_lwz     r3,  0x28 (r1) ");      /* Restore r3 */						\
	__asm (" e_lwz     r4,  0x2C (r1) ");      /* Restore r4 */						\
	__asm (" e_lmw     r14, 0x50 (r1) ");      /* load word multiple r14-r31 */		\
	__asm (" e_lwz     r0,  0x24 (r1) ");      /* Restore r0 */						\
		/* Restore space on stack */												\
	__asm ( "e_add16i  r1, r1, 0x98 ");												\
}

/* Saves context to task stack */
#define portSAVE_CONTEXT() {																			\
	__asm ("  	e_stw     r1,-0x98 (r1) ");			/* store backchain 	*/								\
	__asm ("	e_add16i  r1,r1, -0x98 ");     		/* allocate stack 	*/								\
	__asm ("    e_stw	  r0,  0x24 (r1) ");		/* Store r0 working register  */					\
	__asm ("    e_stw     r3,  0x28 (r1) ");   		/* Store r3 */										\
		/* Save rest of context required by EABI */														\
	__asm ("    e_stw     r12, 0x4C (r1) ");      	/* Store r12 */										\
	__asm ("    e_stw     r11, 0x48 (r1) ");      	/* Store r11 */										\
	__asm ("    e_stw     r10, 0x44 (r1) ");      	/* Store r10 */										\
	__asm ("    e_stw     r9,  0x40 (r1) ");      	/* Store r9 */										\
	__asm ("    e_stw     r8,  0x3C (r1) ");      	/* Store r8 */										\
	__asm ("    e_stw     r7,  0x38 (r1) ");      	/* Store r7 */										\
	__asm ("    e_stw     r6,  0x34 (r1) ");      	/* Store r6 */										\
	__asm ("    e_stw     r5,  0x30 (r1) ");      	/* Store r5 */										\
	__asm ("    e_stw     r4,  0x2C (r1) ");      	/* Store r4 */										\
	__asm ("    mfcr      r0 ");                 	/* Store CR */										\
	__asm ("    e_stw     r0,  0x20 (r1) ");															\
	__asm ("    mfxer     r0 ");                  	/* Store XER */										\
	__asm ("    e_stw     r0,  0x1C (r1) ");															\
	__asm ("    mfctr     r0 ");                  	/* Store CTR */										\
	__asm ("    e_stw     r0,  0x18 (r1) ");															\
	__asm ("    mflr      r0 ");                  	/* Store LR */										\
	__asm ("    e_stw     r0,  0x14 (r1) ");															\
	__asm ("    mfsrr1    r0 ");                	/* Store SRR1 (must be done before enabling EE) */	\
	__asm ("    e_stw     r0,  0x10 (r1) ");															\
	__asm ("    mfsrr0    r0 ");                	/* Store SRR0 (must be done before enabling EE) */	\
	__asm ("    e_stw     r0,  0x0C (r1) ");															\
	__asm ("  	e_stmw    r14, 0x50 (r1) ");        /* save r14-r31 by store word multiple */			\
}

#endif

#ifdef __cplusplus
}
#endif

#endif /* PORTMACRO_H */


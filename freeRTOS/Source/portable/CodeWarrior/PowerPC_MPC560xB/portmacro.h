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


#ifdef __cplusplus
}
#endif

#endif /* PORTMACRO_H */


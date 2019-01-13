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

/*
#include <sys/stat.h>

#include <stdarg.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
*/


#include "sys_init.h"
#include "MPC5604B.h"
#include "FreeRTOS.h"
#include "task.h"

// MCP
//#define DEBUG

void vLEDTask( void *pvParameters );
#define mainLED_TASK_PRIORITY                ( tskIDLE_PRIORITY + 2 )

#if configUSE_TICK_HOOK > 0
void vApplicationTickHook(void);

volatile uint32_t ui32_ms_cnt = 0;

void vApplicationTickHook(void)
{
  // increments every 1ms if configCPU_CLOCK_HZ is set correctly
  ui32_ms_cnt++;   
}
#endif

#define TOGGLE_LED1(void) {				\
		SIU.PGPDO[2].R ^= 0x08000000;	\
}

#define TOGGLE_LED2(void) {				\
		SIU.PGPDO[2].R ^= 0x04000000;	\
}


extern int global_count;

TaskHandle_t * task1 = NULL;
TaskHandle_t * task2 = NULL;

void vLEDTask1 (void *pvParameters)
{
	unsigned int ID = (unsigned int)pvParameters;
	SIU.PGPDO[2].R |= 0x08000000;

	for(;;){
		if (!(global_count % configTICK_RATE_HZ)) {
			TOGGLE_LED1();
		}
	}
}

void vLEDTask2 (void *pvParameters)
{
	unsigned int ID = (unsigned int)pvParameters;
	SIU.PGPDO[2].R |= 0x04000000;		/* Disable LEDs*/

	for(;;){
		if (!(global_count % configTICK_RATE_HZ)) {
			TOGGLE_LED2();
		}
	}
}

int main( void )
{
	uint32_t mode;

#ifdef DEBUG
	uint8_t channel;
	uint32_t interrupt_enable;
	uint16_t priority;
#endif
	
	//init_sys();
	sys_init_fnc();
	
	mode = 0x4; /* RUN0 mode */
	mode_entry_change_mode(mode);

#ifdef DEBUG
	SIU.PCR[68].R = 0x0200;				/* Program the drive enable pin of LED1 (PE4) as output*/
	SIU.PGPDO[2].R |= 0x0f000000;		/* Disable LEDs*/
	SIU.PGPDO[2].R &= 0x07000000;		/* Enable LED1*/
	
	// start timer
	
	channel = 0;
	interrupt_enable = 1;
	priority = 15;
	pit_config(pit_ch0_isr, channel,interrupt_enable, priority,0x03D09000);
	PIT_START_TIMER(channel);
	portYIELD();
	
	//xTaskCreate( vLEDTask, ( const char * const ) "LedTask", configMINIMAL_STACK_SIZE, (void*)0x0, mainLED_TASK_PRIORITY, NULL );
	//vTaskStartScheduler();
	
	while (1)
	{
		
	}
#endif
	
	SIU.PCR[68].R = 0x0200;				/* Program the drive enable pin of LED1 (PE4) as output*/
	SIU.PCR[69].R = 0x0200;				/* Program the drive enable pin of LED2 (PE5) as output*/
	SIU.PGPDO[2].R |= 0x0f000000;	
		
	
	xTaskCreate( vLEDTask2, ( const char * const ) "LedTask2", configMINIMAL_STACK_SIZE, (void*)0x0, mainLED_TASK_PRIORITY, task2 );
	xTaskCreate( vLEDTask1, ( const char * const ) "LedTask1", configMINIMAL_STACK_SIZE, (void*)0x0, mainLED_TASK_PRIORITY, task1 );
	vTaskStartScheduler();
	
	for(;;);
}


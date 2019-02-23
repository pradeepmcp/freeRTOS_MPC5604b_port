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

#define TOGGLE_LED3(void) {				\
		SIU.PGPDO[2].R ^= 0x02000000;	\
}

#define TOGGLE_LED4(void) {				\
		SIU.PGPDO[2].R ^= 0x01000000;	\
}


extern int global_count;

TaskHandle_t  task1 = NULL;
TaskHandle_t  task2 = NULL;

void led1ToggleTask1 (void *pvParameters)
{
	unsigned int ID = (unsigned int)pvParameters;
	TickType_t xLastWakeTime;
	const TickType_t xFrequency = configTICK_RATE_HZ;
	uint8_t count = 0;
	UBaseType_t curr_prio;

	
	SIU.PGPDO[2].R |= 0x08000000;
	xLastWakeTime = xTaskGetTickCount();

	for(;;){
		TOGGLE_LED1();
		vTaskDelayUntil( &xLastWakeTime, xFrequency );

		if(count == 10) {
			curr_prio = uxTaskPriorityGet(task2);
			vTaskPrioritySet(task2, curr_prio+2);
		}
		count ++;
	}
}

void emptyTask (void *pvParameters)
{
	unsigned int ID = (unsigned int)pvParameters;
	TickType_t xLastWakeTime;
	const TickType_t xFrequency = configTICK_RATE_HZ/2;
	
	SIU.PGPDO[2].R |= 0x08000000;
	xLastWakeTime = xTaskGetTickCount();

	for(;;){
	}
}


void vLEDTask1 (void *pvParameters)
{
	unsigned int ID = (unsigned int)pvParameters;
	TickType_t xLastWakeTime;
	const TickType_t xFrequency = configTICK_RATE_HZ;
	
	SIU.PGPDO[2].R |= 0x08000000;
	xLastWakeTime = xTaskGetTickCount();

	for(;;){
		TOGGLE_LED1();
		vTaskDelayUntil( &xLastWakeTime, xFrequency );
	}
}

void vLEDTask2 (void *pvParameters)
{
	unsigned int ID = (unsigned int)pvParameters;
	TickType_t xLastWakeTime;
	const TickType_t xFrequency = 100;
	
	SIU.PGPDO[2].R |= 0x04000000;		/* Disable LEDs*/
	xLastWakeTime = xTaskGetTickCount();

	for(;;){
		TOGGLE_LED2();
		vTaskDelayUntil( &xLastWakeTime, xFrequency );
	}
}

void vLEDTask3 (void *pvParameters)
{
	unsigned int ID = (unsigned int)pvParameters;
	
	TickType_t xLastWakeTime;
	const TickType_t xFrequency = 10;
	
	SIU.PGPDO[2].R |= 0x02000000;		/* Disable LEDs*/
	
	xLastWakeTime = xTaskGetTickCount();
	
	for(;;){
		TOGGLE_LED3();
		vTaskDelayUntil( &xLastWakeTime, xFrequency );
	}
}

void vLEDTask4 (void *pvParameters)
{
	unsigned int ID = (unsigned int)pvParameters;
	
	TickType_t xLastWakeTime;
	const TickType_t xFrequency = 50;
	
	SIU.PGPDO[2].R |= 0x01000000;		/* Disable LEDs*/
	
	xLastWakeTime = xTaskGetTickCount();
	for(;;){
		TOGGLE_LED4();
		vTaskDelayUntil( &xLastWakeTime, xFrequency );

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
	SIU.PCR[70].R = 0x0200;				/* Program the drive enable pin of LED3 (PE6) as output*/
	SIU.PCR[71].R = 0x0200;				/* Program the drive enable pin of LED4 (PE7) as output*/
	SIU.PGPDO[2].R |= 0x0f000000;	

#if 0 //Enable this code to check multiple task switching 
	xTaskCreate( vLEDTask4, ( const char * const ) "LedTask4", configMINIMAL_STACK_SIZE, (void*)0x0, mainLED_TASK_PRIORITY, NULL );
	xTaskCreate( vLEDTask3, ( const char * const ) "LedTask3", configMINIMAL_STACK_SIZE, (void*)0x0, mainLED_TASK_PRIORITY, NULL );
	xTaskCreate( vLEDTask2, ( const char * const ) "LedTask2", configMINIMAL_STACK_SIZE, (void*)0x0, mainLED_TASK_PRIORITY, NULL );
	xTaskCreate( vLEDTask1, ( const char * const ) "LedTask1", configMINIMAL_STACK_SIZE, (void*)0x0, mainLED_TASK_PRIORITY, NULL );
#endif
	
#if 1 //Enable this code to test vTaskPrioritySet()
	/*
	 * led1ToggleTask1() runs initially. 
	 * Toggles LED1 for 10 times.
	 * Changes the priority of emptyTask to  mainLED_TASK_PRIORITY+2 from mainLED_TASK_PRIORITY.
	 * emptyTask never yields since it is of higher priority now and the LED stops blinking. 
	 */
	xTaskCreate( led1ToggleTask1, ( const char * const ) "LedTask1", configMINIMAL_STACK_SIZE, (void*)0x0, mainLED_TASK_PRIORITY+1, &task1 );
	xTaskCreate( emptyTask, ( const char * const ) "empty task", configMINIMAL_STACK_SIZE, (void*)0x0, mainLED_TASK_PRIORITY, &task2 );
#endif
	
	vTaskStartScheduler();
	
	for(;;){}
}


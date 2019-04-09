/*
 *######################################################################
 *                                RAppIDJDP
 *           Rapid Application Initialization and Documentation Tool
 *                         Freescale Semiconductor Inc.
 *
 *######################################################################
 *
 * Project Name           : freertos_pit
 *
 * Project File           : freertos_pit.rsp
 *
 * Revision Number        : 1.0
 *
 * Tool Version           : 1.2.1.5
 *
 * file                   : pit_init.h
 *
 * Target Compiler        : Diab
 *
 * Target Part            : MPC5606B
 *
 * Part Errata Fixes      : none
 *
 * Project Last Save Date : 09-May-2018 21:34:49
 *
 * Created on Date        : 09-May-2018 21:35:39
 *
 * Brief Description      : File contains declaration for Periodic Interrupt Timer(PIT)
 *                          initialization function.
 *
 *
 *######################################################################
*/

#ifndef  _PIT_INIT_H
#define  _PIT_INIT_H
/********************  Dependent Include files here **********************/

#include "MPC5604B.h"
#include "IntcInterrupts.h"

/************************* Constant definitions **************************/
#define PIT_PSR_BASE 59

/************************* Macro definitions  ****************************/
#define PIT_START_TIMER(channel) 			\
{											\
	PIT.CH[channel].TCTRL.B.TEN = 1; 		\
	PIT.PITMCR.B.MDIS = 0;					\
}

/**********************  Function Prototype here *************************/

void pit_init_fnc (void);
void pit_config (INTCInterruptFn handler_fn, uint8_t channel, uint32_t interrupt_enable, uint16_t priority, uint32_t ld_val);

#endif  /*_PIT_INIT_H*/

/*
 *######################################################################
 *                           End of File
 *######################################################################
*/


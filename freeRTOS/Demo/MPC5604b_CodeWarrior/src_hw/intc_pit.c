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
 * file                   : intc_pit.c
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
 * Brief Description      : This  file contains  the interrupt service routine  for the Periodic Interrupt Timer
 *
 ******************************************************************************** 
 *
 * Detail Description     : This file is generated when PIT(Periodic Interrupt
 *                         Timer) function is defined in INTC peripheral.This
 *                         file contains the Interrupt handlers routines for PIT.
 *                         In Interrupt handlers routine respective flags are cleared.
 *
 ******************************************************************************** 
 *
 *######################################################################
*/

 
 
/********************  Dependent Include files here **********************/

#include "intc_pit.h"


/************************* INTERRUPT HANDLERS ************************/

void pit_ch0_interrupt_handler (void)
{
    PIT.CH[0].TFLG.R = 0x00000001;

}


 
/*
 *######################################################################
 *                           End of File
 *######################################################################
*/


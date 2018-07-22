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
 * file                   : intc_pit.h
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
 *
 *######################################################################
*/

#ifndef  _INTC_PIT_H
#define  _INTC_PIT_H
/********************  Dependent Include files here **********************/

#include "MPC5604B.h"

/**********************  Function Prototype here *************************/
#pragma section RX ".__exception_handlers"
__declspec (section ".__exception_handlers") void pit_ch0_interrupt_handler(void);


#endif  /*_INTC_PIT_H*/

/*
 *######################################################################
 *                           End of File
 *######################################################################
*/


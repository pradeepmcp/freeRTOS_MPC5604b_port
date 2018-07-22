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
 * file                   : swt_init.h
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
 * Brief Description      : File contains declarations for Watchdog initialization function
 *                          and Service Routine.
 *
 *
 *######################################################################
*/

#ifndef  _SWT_INIT_H
#define  _SWT_INIT_H
/********************  Dependent Include files here **********************/

#include "MPC5604B.h"

/**********************  Function Prototype here *************************/

void swt_init_fnc (void);
void swt_srvc_seq_fnc (void);


#endif  /*_SWT_INIT_H*/

/*
 *######################################################################
 *                           End of File
 *######################################################################
*/


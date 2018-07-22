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
 * file                   : sys_init.h
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
 * Brief Description      : This file contains system initialization code
 *
 *
 *######################################################################
*/

#ifndef  _SYS_INIT_H
#define  _SYS_INIT_H
/********************  Dependent Include files here **********************/

#include "intc_init.h"
#include "sysclk.h"
//#include "linflex_init.h"
//#include "adc_init.h"
//#include "msr_init.h"
#include "swt_init.h"
//#include "edma_init.h"
//#include "i2c_init.h"
//#include "flexcan_init.h"
//#include "cansp_init.h"
//#include "emios_init.h"
//#include "dspi_init.h"
#include "siu_init.h"
//#include "mpu_init.h"
//#include "rgm_init.h"
#include "pit.h"
#include "stm_init.h"
//#include "rtc_init.h"
//#include "flash_init.h"

/**********************  Function Prototype here *************************/

void sys_init_fnc (void);
extern void IVPRInitialize(void);


#endif  /*_SYS_INIT_H*/

/*
 *######################################################################
 *                           End of File
 *######################################################################
*/


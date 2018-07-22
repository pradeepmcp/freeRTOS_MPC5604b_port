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
 * file                   : sys_init.c
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
 ******************************************************************************** 
 *
 * Detail Description     : This file contains function which calls respective
 *                         peripheral initialization functions
 *
 ******************************************************************************** 
 *
 *######################################################################
*/

 
 
/********************  Dependent Include files here **********************/

#include "sys_init.h"


/*********************  Initialization Function(s) ************************/

void sys_init_fnc (void)
{

/* ----------------------------------------------------------- */
/*	               System Initialization Functions              */
/* ----------------------------------------------------------- */

/* ----------------------------------------------------------- */
/*                  Reset Determination Goes Here             */
/* ----------------------------------------------------------- */

/* ----------------------------------------------------------- */
/*	           FlexCAN Initialization Status Flag                 */
/* Variable is provided to contains the status of the FlexCAN     */
/* initialization. This variable can be used by user to determine */
/* if FlexCAN initialization was successfully done                */
/* ----------------------------------------------------------- */
   uint8_t fci_status;

/* ----------------------------------------------------------- */
/*	        Initialize the Interrupt Controller (INTC)             */
/* ----------------------------------------------------------- */
    intc_init_fnc();
    //IVPRInitialize();

/* ----------------------------------------------------------- */
/*	        Initialize the Reset Generation Module (RGM)             */
/* ----------------------------------------------------------- */
    //rgm_init_fnc();

/* ----------------------------------------------------------- */
/*	        Initialize the Software Watchdog (SWT)             */
/* ----------------------------------------------------------- */
    //swt_init_fnc();

/* ----------------------------------------------------------- */
/*	        Initialize the Main Status Register (MSR)             */
/* ----------------------------------------------------------- */
    //msr_init_fnc();

/* ----------------------------------------------------------- */
/*	        Initialize the System Clock, Mode Entry (ME) & CMU             */
/* ----------------------------------------------------------- */
    sysclk_module_init_fnc();

/* ----------------------------------------------------------- */
/*	        Initialize the Real Time Clock (RTC)             */
/* ----------------------------------------------------------- */
    //rtc_init_fnc();

/* ----------------------------------------------------------- */
/*	        Initialize the System Timer Module (STM)             */
/* ----------------------------------------------------------- */
    //stm_init_fnc();

/* ----------------------------------------------------------- */
/*	        Initialize the Periodic Interrupt Timer (PIT)             */
/* ----------------------------------------------------------- */
    pit_init_fnc();

/* ----------------------------------------------------------- */
/*	        Initialize the Flash Bus Interface Unit (BIU)             */
/* ----------------------------------------------------------- */
    //flash_init_fnc();

/* ----------------------------------------------------------- */
/*	        Initialize the Memory Protection Unit (MPU)             */
/* ----------------------------------------------------------- */
    //mpu_init_fnc();

/* ----------------------------------------------------------- */
/*	        Initialize the Enhanced Direct Memory Access (eDMA)             */
/* ----------------------------------------------------------- */
    //edma_init_fnc();

/* ----------------------------------------------------------- */
/*	        Initialize the FlexCAN             */
/* ----------------------------------------------------------- */
    //fci_status = flexcan_init_fnc();

/* ----------------------------------------------------------- */
/*	        Initialize the CAN Sampler             */
/* ----------------------------------------------------------- */
    //cansp_init_fnc();

/* ----------------------------------------------------------- */
/*	        Initialize the Analog to Digital Converter (ADC)             */
/* ----------------------------------------------------------- */
    //adc_init_fnc();

/* ----------------------------------------------------------- */
/*	        Initialize the Enhanced Modular I/O (eMIOS)             */
/* ----------------------------------------------------------- */
    //emios_init_fnc();

/* ----------------------------------------------------------- */
/*	        Initialize the Deserial Serial Peripheral Interface (DSPI)             */
/* ----------------------------------------------------------- */
   // dspi_init_fnc();

/* ----------------------------------------------------------- */
/*	        Initialize the Inter-Integrated Circuit Bus (I2C)             */
/* ----------------------------------------------------------- */
    //i2c_0_init_fnc();

/* ----------------------------------------------------------- */
/*	        Initialize the LINFlex             */
/* ----------------------------------------------------------- */
    //linflex_init_fnc();

/* ----------------------------------------------------------- */
/*	        Initialize the Mode Entry Post Configuration             */
/* ----------------------------------------------------------- */
    mode_entry_post_config_fnc();

/* ----------------------------------------------------------- */
/*	        Initialize the System Integration Unit (SIU)             */
/* ----------------------------------------------------------- */
    //siu_init_fnc();


}

 
/*
 *######################################################################
 *                           End of File
 *######################################################################
*/


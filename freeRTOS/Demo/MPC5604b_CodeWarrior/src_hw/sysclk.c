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
 * file                   : sysclk_init.c
 *
 * Target Compiler        : Diab
 *
 * Target Part            : MPC5606B
 *
 * Part Errata Fixes      : none
 *
 * Project Last Save Date : 15-May-2018 23:11:43
 *
 * Created on Date        : 15-May-2018 23:11:44
 *
 * Brief Description      : Mode Entry, System Clock, CMU initialization file.
 *
 ******************************************************************************** 
 *
 * Detail Description     : This file contains definitions for initialization
 *                         functions of Mode Entry, System Clock and CMU module.
 *                         Mode Entry function will configure the system SoC for
 *                         different operating modes. In System Clock function the
 *                         Clock Generation Module parameters are initialized for
 *                         DRUN mode. CMU function is initialized to monitor the
 *                         system clock parameters and report the failures.
 *
 ******************************************************************************** 
 *
 *######################################################################
*/

 
 
/********************  Dependent Include files here **********************/

#include "sysclk.h"


/*********************  Initialization Function(s) ************************/

void sysclk_module_init_fnc(void)
{
    mode_entry_init_fnc();
        /* Mode Entry Initialization Function */
    sysclk_init_fnc();
        /* System Clock Initialization Function */
    cmu_init_fnc();
        /* CMU Initialization Function */
}


void mode_entry_init_fnc(void)
{

/* ----------------------------------------------------------- */
/*              Operating Modes Initialization - Start            */
/* ----------------------------------------------------------- */

/* ----------------------------------------------------------- */
/*              Mode Entry Setup            */
/* ----------------------------------------------------------- */

    ME.MER.R = 0x0000001D;
        /* STANDBY0 Mode : Disabled    */
        /* STOP0 Mode : Disabled    */
        /* HALT0 Mode : Disabled    */
        /* RUN3 Mode : Disabled    */
        /* RUN2 Mode : Disabled    */
        /* RUN1 Mode : Disabled    */
        /* RUN0 Mode : Enabled    */
        /* DRUN Mode : Enabled    */
        /* SAFE Mode : Enabled    */
        /* TEST Mode : Disabled    */
        /* RESET Mode : Enabled    */
/*---------------------------TEST Mode--------------------------------*/
    ME.TEST.R = 0x001F0010;
        /* I/O Power Down Control: Disabled    */
        /* Main Voltage Regulator Control: ON    */
        /* Data Flash Power Down Control: Normal    */
        /* Code Flash Power Down Control: Normal    */
        /* System PLL: OFF    */
        /* Crystal Oscillator: OFF    */
        /* 16MHz IRC:  ON    */
        /* System Clock Source: 16MHz internal RC oscillator     */
/*---------------------------SAFE Mode--------------------------------*/
    ME.SAFE.R  = 0x009F0010;
        /* I/O Power Down Control: Enabled    */
        /* Main Voltage Regulator Control: ON    */
        /* Data Flash Power Down Control: Normal    */
        /* Code Flash Power Down Control: Normal    */
        /* System PLL: OFF    */
        /* Crystal Oscillator: OFF    */
        /* 16MHz IRC:  ON    */
        /* System Clock Source: 16MHz internal RC oscillator     */
/*---------------------------RUN0 Mode--------------------------------*/
    ME.RUN[0].R = 0x001F0074;
        /* I/O Power Down Control: Disabled    */
        /* Main Voltage Regulator Control: ON    */
        /* Data Flash Power Down Control: Normal    */
        /* Code Flash Power Down Control: Normal    */
        /* System PLL: ON    */
        /* Crystal Oscillator: ON    */
        /* 16MHz IRC:  ON    */
        /* System Clock Source: System PLL    */
/*---------------------------RUN1 Mode--------------------------------*/
    ME.RUN[1].R = 0x001F0010;
        /* I/O Power Down Control: Disabled    */
        /* Main Voltage Regulator Control: ON    */
        /* Data Flash Power Down Control: Normal    */
        /* Code Flash Power Down Control: Normal    */
        /* System PLL: OFF    */
        /* Crystal Oscillator: OFF    */
        /* 16MHz IRC:  ON    */
        /* System Clock Source: 16MHz internal RC oscillator     */
/*---------------------------RUN2 Mode--------------------------------*/
    ME.RUN[2].R = 0x001F0010;
        /* I/O Power Down Control: Disabled    */
        /* Main Voltage Regulator Control: ON    */
        /* Data Flash Power Down Control: Normal    */
        /* Code Flash Power Down Control: Normal    */
        /* System PLL: OFF    */
        /* Crystal Oscillator: OFF    */
        /* 16MHz IRC:  ON    */
        /* System Clock Source: 16MHz internal RC oscillator     */
/*---------------------------RUN3 Mode--------------------------------*/
    ME.RUN[3].R = 0x001F0010;
        /* I/O Power Down Control: Disabled    */
        /* Main Voltage Regulator Control: ON    */
        /* Data Flash Power Down Control: Normal    */
        /* Code Flash Power Down Control: Normal    */
        /* System PLL: OFF    */
        /* Crystal Oscillator: OFF    */
        /* 16MHz IRC:  ON    */
        /* System Clock Source: 16MHz internal RC oscillator     */
/*---------------------------HALT0 Mode--------------------------------*/
    ME.HALT0.R = 0x001F0010;
        /* I/O Power Down Control: Disabled    */
        /* Main Voltage Regulator Control: ON    */
        /* Data Flash Power Down Control: Normal    */
        /* Code Flash Power Down Control: Normal    */
        /* System PLL: OFF    */
        /* Crystal Oscillator: OFF    */
        /* 16MHz IRC:  ON    */
        /* System Clock Source: 16MHz internal RC oscillator     */
/*---------------------------STOP0 Mode--------------------------------*/
    ME.STOP0.R = 0x00150010;
        /* I/O Power Down Control: Disabled    */
        /* Main Voltage Regulator Control: ON    */
        /* Data Flash Power Down Control: Power Down    */
        /* Code Flash Power Down Control: Power Down    */
        /* System PLL: OFF    */
        /* Crystal Oscillator: OFF    */
        /* 16MHz IRC:  ON    */
        /* System Clock Source: 16MHz internal RC oscillator     */
/*---------------------------STANDBY0 Mode--------------------------------*/
    ME.STANDBY0.R = 0x0085001F;
        /* I/O Power Down Control: Enabled    */
        /* Main Voltage Regulator Control: OFF    */
        /* Data Flash Power Down Control: Power Down    */
        /* Code Flash Power Down Control: Power Down    */
        /* System PLL: OFF    */
        /* Crystal Oscillator: OFF    */
        /* 16MHz IRC:  ON    */
        /* System Clock Source: Disable System Clock    */

/* ----------------------------------------------------------- */
/*              Peripheral RUN Mode Configuration            */
/* ----------------------------------------------------------- */

    ME.RUNPC[0].R = 0x000000FE;
        /* Peripheral Operation in RUN3  mode: Enabled    */
        /* Peripheral Operation in RUN2  mode: Enabled    */
        /* Peripheral Operation in RUN1  mode: Enabled    */
        /* Peripheral Operation in RUN0  mode: Enabled    */
        /* Peripheral Operation in DRUN  mode: Enabled    */
        /* Peripheral Operation in SAFE  mode: Enabled    */
        /* Peripheral Operation in TEST  mode: Enabled    */
        /* Peripheral Operation in RESET  mode: Disabled    */

    ME.RUNPC[1].R = 0x000000FE;
        /* Peripheral Operation in RUN3  mode: Enabled    */
        /* Peripheral Operation in RUN2  mode: Enabled    */
        /* Peripheral Operation in RUN1  mode: Enabled    */
        /* Peripheral Operation in RUN0  mode: Enabled    */
        /* Peripheral Operation in DRUN  mode: Enabled    */
        /* Peripheral Operation in SAFE  mode: Enabled    */
        /* Peripheral Operation in TEST  mode: Enabled    */
        /* Peripheral Operation in RESET  mode: Disabled    */

    ME.RUNPC[2].R = 0x00000008;
        /* Peripheral Operation in RUN3  mode: Disabled    */
        /* Peripheral Operation in RUN2  mode: Disabled    */
        /* Peripheral Operation in RUN1  mode: Disabled    */
        /* Peripheral Operation in RUN0  mode: Disabled    */
        /* Peripheral Operation in DRUN  mode: Enabled    */
        /* Peripheral Operation in SAFE  mode: Disabled    */
        /* Peripheral Operation in TEST  mode: Disabled    */
        /* Peripheral Operation in RESET  mode: Disabled    */

    ME.RUNPC[3].R = 0x00000008;
        /* Peripheral Operation in RUN3  mode: Disabled    */
        /* Peripheral Operation in RUN2  mode: Disabled    */
        /* Peripheral Operation in RUN1  mode: Disabled    */
        /* Peripheral Operation in RUN0  mode: Disabled    */
        /* Peripheral Operation in DRUN  mode: Enabled    */
        /* Peripheral Operation in SAFE  mode: Disabled    */
        /* Peripheral Operation in TEST  mode: Disabled    */
        /* Peripheral Operation in RESET  mode: Disabled    */

    ME.RUNPC[4].R = 0x00000008;
        /* Peripheral Operation in RUN3  mode: Disabled    */
        /* Peripheral Operation in RUN2  mode: Disabled    */
        /* Peripheral Operation in RUN1  mode: Disabled    */
        /* Peripheral Operation in RUN0  mode: Disabled    */
        /* Peripheral Operation in DRUN  mode: Enabled    */
        /* Peripheral Operation in SAFE  mode: Disabled    */
        /* Peripheral Operation in TEST  mode: Disabled    */
        /* Peripheral Operation in RESET  mode: Disabled    */

    ME.RUNPC[5].R = 0x00000008;
        /* Peripheral Operation in RUN3  mode: Disabled    */
        /* Peripheral Operation in RUN2  mode: Disabled    */
        /* Peripheral Operation in RUN1  mode: Disabled    */
        /* Peripheral Operation in RUN0  mode: Disabled    */
        /* Peripheral Operation in DRUN  mode: Enabled    */
        /* Peripheral Operation in SAFE  mode: Disabled    */
        /* Peripheral Operation in TEST  mode: Disabled    */
        /* Peripheral Operation in RESET  mode: Disabled    */

    ME.RUNPC[6].R = 0x00000008;
        /* Peripheral Operation in RUN3  mode: Disabled    */
        /* Peripheral Operation in RUN2  mode: Disabled    */
        /* Peripheral Operation in RUN1  mode: Disabled    */
        /* Peripheral Operation in RUN0  mode: Disabled    */
        /* Peripheral Operation in DRUN  mode: Enabled    */
        /* Peripheral Operation in SAFE  mode: Disabled    */
        /* Peripheral Operation in TEST  mode: Disabled    */
        /* Peripheral Operation in RESET  mode: Disabled    */

    ME.RUNPC[7].R = 0x00000008;
        /* Peripheral Operation in RUN3  mode: Disabled    */
        /* Peripheral Operation in RUN2  mode: Disabled    */
        /* Peripheral Operation in RUN1  mode: Disabled    */
        /* Peripheral Operation in RUN0  mode: Disabled    */
        /* Peripheral Operation in DRUN  mode: Enabled    */
        /* Peripheral Operation in SAFE  mode: Disabled    */
        /* Peripheral Operation in TEST  mode: Disabled    */
        /* Peripheral Operation in RESET  mode: Disabled    */


/* ----------------------------------------------------------- */
/*              Peripheral Low-Power Mode Configuration            */
/* ----------------------------------------------------------- */

    ME.LPPC[0].R = 0x00002500;
        /* Peripheral Operation in STANDBY0 mode: Enabled    */
        /* Peripheral Operation in STOP0 mode: Enabled    */
        /* Peripheral Operation in HALT0 mode: Enabled    */

    ME.LPPC[1].R = 0x00000000;
        /* Peripheral Operation in STANDBY0 mode: Disabled    */
        /* Peripheral Operation in STOP0 mode: Disabled    */
        /* Peripheral Operation in HALT0 mode: Disabled    */

    ME.LPPC[2].R = 0x00000000;
        /* Peripheral Operation in STANDBY0 mode: Disabled    */
        /* Peripheral Operation in STOP0 mode: Disabled    */
        /* Peripheral Operation in HALT0 mode: Disabled    */

    ME.LPPC[3].R = 0x00000000;
        /* Peripheral Operation in STANDBY0 mode: Disabled    */
        /* Peripheral Operation in STOP0 mode: Disabled    */
        /* Peripheral Operation in HALT0 mode: Disabled    */

    ME.LPPC[4].R = 0x00000000;
        /* Peripheral Operation in STANDBY0 mode: Disabled    */
        /* Peripheral Operation in STOP0 mode: Disabled    */
        /* Peripheral Operation in HALT0 mode: Disabled    */

    ME.LPPC[5].R = 0x00000000;
        /* Peripheral Operation in STANDBY0 mode: Disabled    */
        /* Peripheral Operation in STOP0 mode: Disabled    */
        /* Peripheral Operation in HALT0 mode: Disabled    */

    ME.LPPC[6].R = 0x00000000;
        /* Peripheral Operation in STANDBY0 mode: Disabled    */
        /* Peripheral Operation in STOP0 mode: Disabled    */
        /* Peripheral Operation in HALT0 mode: Disabled    */

    ME.LPPC[7].R = 0x00000000;
        /* Peripheral Operation in STANDBY0 mode: Disabled    */
        /* Peripheral Operation in STOP0 mode: Disabled    */
        /* Peripheral Operation in HALT0 mode: Disabled    */


/* ----------------------------------------------------------- */
/*              Peripheral Mode Control Setup            */
/* ----------------------------------------------------------- */

    /* DSPI_0 Control */
    ME.PCTL[4].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* DSPI_1 Control */
    ME.PCTL[5].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* DSPI_2 Control */
    ME.PCTL[6].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* DSPI_3 Control */
    ME.PCTL[7].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* DSPI_4 Control */
    ME.PCTL[8].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* DSPI_5 Control */
    ME.PCTL[9].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* FlexCAN_0 Control */
    ME.PCTL[16].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* FlexCAN_1 Control */
    ME.PCTL[17].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* FlexCAN_2 Control */
    ME.PCTL[18].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* FlexCAN_3 Control */
    ME.PCTL[19].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* FlexCAN_4 Control */
    ME.PCTL[20].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* FlexCAN_5 Control */
    ME.PCTL[21].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* ADC_0 Control */
    ME.PCTL[32].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* ADC_1 Control */
    ME.PCTL[33].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* I2C Control */
    ME.PCTL[44].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* LINFlex_0 Control */
    ME.PCTL[48].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* LINFlex_1 Control */
    ME.PCTL[49].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* LINFlex_2 Control */
    ME.PCTL[50].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* LINFlex_3 Control */
    ME.PCTL[51].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* LINFlex_4 Control */
    ME.PCTL[52].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* LINFlex_5 Control */
    ME.PCTL[53].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* LINFlex_6 Control */
    ME.PCTL[54].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* LINFlex_7 Control */
    ME.PCTL[55].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* CTU Control */
    ME.PCTL[57].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* CANSampler Control */
    ME.PCTL[60].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* SIUL Control */
    ME.PCTL[68].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* WKPU Control */
    ME.PCTL[69].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* eMIOS_0 Control */
    ME.PCTL[72].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* eMIOS_1 Control */
    ME.PCTL[73].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* RTC/API Control */
    ME.PCTL[91].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* PIT Control */
    ME.PCTL[92].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* CMU Control */
    ME.PCTL[104].R = 0x00;
        /* Peripheral Operation in Debug mode: Disabled    */
        /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
        /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */


/* ----------------------------------------------------------- */
/*              Interrupt Setup            */
/* ----------------------------------------------------------- */

    ME.IM.R = 0x00000000;
        /* Invalid Mode Configuration Interrupt: Disabled    */
        /* Invalid Mode Interrupt: Disabled    */
        /* SAFE Mode Interrupt: Disabled    */
        /* Mode Transition Complete Interrupt: Disabled    */

/* ----------------------------------------------------------- */
/*              Operating Modes Initialization - End                */
/* ----------------------------------------------------------- */

}

void sysclk_init_fnc(void)
{

/* ----------------------------------------------------------- */
/*              Enable All Peripheral Clocks            */
/* ----------------------------------------------------------- */

    CGM.SC_DC[0].R =0x80;    
        /* Peripheral Set 1 Clock Divider Status: Enabled */
        /* Peripheral Set 1 Clock Divider: 1 */
    CGM.SC_DC[1].R =0x80;    
        /* Peripheral Set 2 Clock Divider Status: Enabled */
        /* Peripheral Set 2 Clock Divider: 1 */
    CGM.SC_DC[2].R =0x80;    
        /* Peripheral Set 3 Clock Divider Status: Enabled */
        /* Peripheral Set 3 Clock Divider: 1 */


/* --------------- Set Maximum CMU RC Divider  --------------- */
    CGM.CMU_CSR.R = 0x00000006;
        /* RC Clock Division factor: 8  */


/* ----------------------------------------------------------- */
/*              Clock Source Configuration            */
/* ----------------------------------------------------------- */

    *((unsigned char *) &CGM.FIRC_CTL.B + 2) = 0x00;
        /* IRC Oscillator Trimming: 0    */
        /* The 16MHz IRC Clock Divider: 1    */

    CGM.FXOSC_CTL.R = 0x00800000;
        /* Oscillator Output is Disabled as rootclock    */
        /* The End of Count Value for XOSC = 0x80    */
        /* The XOSC Clock Interrupt: Disabled    */
        /* The XOSC Clock Divider: 1    */

    CGM.FMPLL_CR.R = 0x01280100;
     	/* Refer FMPLL lookup table in MPC5604BCRM
        /* Input Division Factor: 1    */
        /* Output Division Factor: 1    */
        /* Loop Division Factor: 40   */
        /* Progressive Clock Switching Enabled in Standby Mode    */

    CGM.FMPLL_MR.R = 0x20000000;
        /* The selected Spread Type: Center Spread    */
        /* The Modulation Period for FMPLL: 0    */
        /* Frequency modulation for PLL: Disabled    */
        /* The Increment Step for FMPLL: 0    */



/* ----------------------------------------------------------- */
/*                    System Clock Setup (16MHz IRC)                 */
/* ----------------------------------------------------------- */

    ME.DRUN.R = 0x001F0070;
        /* I/O Power Down Control: Disabled    */
        /* Main Voltage Regulator Control: Enabled    */
        /* Data Flash Power Down Control: Normal    */
        /* Code Flash Power Down Control: Normal    */
        /* System PLL: ON    */
        /* Crystal Oscillator: ON    */
        /* 16MHz IRC: ON    */
        /* System Clock Source: 16MHz internal RC oscillator     */

        /* Re-enter in DRUN mode to update the configuration*/
    ME.MCTL.R = 0x30005AF0;    
        /* Mode & Key */
    ME.MCTL.R = 0x3000A50F;    
        /* Mode & Key  Inverted */
    while(0x1 == ME.GS.B.S_MTRANS){};    
        /* Wait for mode entry to complete */
    while(0x3 != ME.GS.B.S_CURRENTMODE){};    
        /* Check DRUN mode has been entered  */

        /* Poll Global Status Register to get current System Clock */
    while(0x0!= ME.GS.B.S_SYSCLK){};    
        /* Fail is stuck here */



/* ----------------------------------------------------------- */
/*          Activate the clock Configuration              */
/* -----------------------------------------------------------  */

    ME.MCTL.R = ((ME.GS.B.S_CURRENTMODE << 28) | 0x00005AF0);    
    ME.MCTL.R = ((ME.GS.B.S_CURRENTMODE << 28) | 0x0000A50F);    

/* ----------------------------------------------------------- */
/*                    System Output Clock Setup                 */
/* ----------------------------------------------------------- */

    CGM.OCDS_SC.R = 0x02000000;    
        /* Clock Divider: 1 */
        /* Output Clock Source: System PLL */
    CGM.OC_EN.B.EN = 0x0;    
        /* Output Clock: Disabled */

/* ----------------------------------------------------------- */
/*                    Low Power Clock Setup                 */
/* ----------------------------------------------------------- */
/* ------------------------LPOSC 32KHz Configuration------------------- */
    CGM.SXOSC_CTL.R = 0x00800000;    
        /* LP Oscillator Output is Enabled as rootclock */
        /* The End of Count Value for LPOSC = 0x80 */
        /* The LPOSC Clock Interrupt: Disabled */
        /* The LPOSC Clock Divider: 1 */
        /* Crystal Oscillator Powerdown Control: Disabled*/


/* ------------------------128KHz Slow IRC Configuration------------------- */
    *((unsigned char *) &CGM.SIRC_CTL.B + 2) = 0x03;
    *((unsigned char *) &CGM.SIRC_CTL.B + 3) = 0x10;

        /* LPRC Oscillator Trimming: 0 */
        /* The 128KHz RC Clock Divider = 4 */
        /* LPRC Oscillator is switched ON in Standby Mode */
}

void cmu_init_fnc(void)
{

/*-----------------------CMU 0 Setup------------------------*/

    CGM.CMU_MDR.R = 0x00000000;
        /* IRC Measurement Duration in IRC Clock Cycles: 0 */

    CGM.CMU_HFREFR_A.R = 0x00000FFF;
        /* High Frequency Reference Value for FMPLL0: 1023.75MHz */

    CGM.CMU_LFREFR_A.R = 0x00000000;
        /* Low Frequency Reference Value for FMPLL0: 0.0MHz */

    CGM.CMU_CSR.R = 0x00000006;
        /* RC Oscillator to be calibrated by Frequency Meter: 16MHz IRC*/
        /* RC Clock Division factor: 8 */
        /* Clock Monitoring Unit 0: Disable */
}

void mode_entry_post_config_fnc(void)
{
/* ----------------------------------------------------------- */
/*              Peripheral RUN Mode Configuration            */
/* ----------------------------------------------------------- */

    ME.RUNPC[0].R = 0x000000FE;
        /* Peripheral Operation in RUN3  mode: Enabled    */
        /* Peripheral Operation in RUN2  mode: Enabled    */
        /* Peripheral Operation in RUN1  mode: Enabled    */
        /* Peripheral Operation in RUN0  mode: Enabled    */
        /* Peripheral Operation in DRUN  mode: Enabled    */
        /* Peripheral Operation in SAFE  mode: Enabled    */
        /* Peripheral Operation in TEST  mode: Enabled    */
        /* Peripheral Operation in RESET  mode: Disabled    */

    ME.RUNPC[1].R = 0x000000FE;
        /* Peripheral Operation in RUN3  mode: Enabled    */
        /* Peripheral Operation in RUN2  mode: Enabled    */
        /* Peripheral Operation in RUN1  mode: Enabled    */
        /* Peripheral Operation in RUN0  mode: Enabled    */
        /* Peripheral Operation in DRUN  mode: Enabled    */
        /* Peripheral Operation in SAFE  mode: Enabled    */
        /* Peripheral Operation in TEST  mode: Enabled    */
        /* Peripheral Operation in RESET  mode: Disabled    */

    ME.RUNPC[2].R = 0x00000000;
        /* Peripheral Operation in RUN3  mode: Disabled    */
        /* Peripheral Operation in RUN2  mode: Disabled    */
        /* Peripheral Operation in RUN1  mode: Disabled    */
        /* Peripheral Operation in RUN0  mode: Disabled    */
        /* Peripheral Operation in DRUN  mode: Disabled    */
        /* Peripheral Operation in SAFE  mode: Disabled    */
        /* Peripheral Operation in TEST  mode: Disabled    */
        /* Peripheral Operation in RESET  mode: Disabled    */

    ME.RUNPC[3].R = 0x00000000;
        /* Peripheral Operation in RUN3  mode: Disabled    */
        /* Peripheral Operation in RUN2  mode: Disabled    */
        /* Peripheral Operation in RUN1  mode: Disabled    */
        /* Peripheral Operation in RUN0  mode: Disabled    */
        /* Peripheral Operation in DRUN  mode: Disabled    */
        /* Peripheral Operation in SAFE  mode: Disabled    */
        /* Peripheral Operation in TEST  mode: Disabled    */
        /* Peripheral Operation in RESET  mode: Disabled    */


    ME.RUNPC[4].R = 0x00000000;
        /* Peripheral Operation in RUN3  mode: Disabled    */
        /* Peripheral Operation in RUN2  mode: Disabled    */
        /* Peripheral Operation in RUN1  mode: Disabled    */
        /* Peripheral Operation in RUN0  mode: Disabled    */
        /* Peripheral Operation in DRUN  mode: Disabled    */
        /* Peripheral Operation in SAFE  mode: Disabled    */
        /* Peripheral Operation in TEST  mode: Disabled    */
        /* Peripheral Operation in RESET  mode: Disabled    */

    ME.RUNPC[5].R = 0x00000000;
        /* Peripheral Operation in RUN3  mode: Disabled    */
        /* Peripheral Operation in RUN2  mode: Disabled    */
        /* Peripheral Operation in RUN1  mode: Disabled    */
        /* Peripheral Operation in RUN0  mode: Disabled    */
        /* Peripheral Operation in DRUN  mode: Disabled    */
        /* Peripheral Operation in SAFE  mode: Disabled    */
        /* Peripheral Operation in TEST  mode: Disabled    */
        /* Peripheral Operation in RESET  mode: Disabled    */

    ME.RUNPC[6].R = 0x00000000;
        /* Peripheral Operation in RUN3  mode: Disabled    */
        /* Peripheral Operation in RUN2  mode: Disabled    */
        /* Peripheral Operation in RUN1  mode: Disabled    */
        /* Peripheral Operation in RUN0  mode: Disabled    */
        /* Peripheral Operation in DRUN  mode: Disabled    */
        /* Peripheral Operation in SAFE  mode: Disabled    */
        /* Peripheral Operation in TEST  mode: Disabled    */
        /* Peripheral Operation in RESET  mode: Disabled    */

    ME.RUNPC[7].R = 0x00000000;
        /* Peripheral Operation in RUN3  mode: Disabled    */
        /* Peripheral Operation in RUN2  mode: Disabled    */
        /* Peripheral Operation in RUN1  mode: Disabled    */
        /* Peripheral Operation in RUN0  mode: Disabled    */
        /* Peripheral Operation in DRUN  mode: Disabled    */
        /* Peripheral Operation in SAFE  mode: Disabled    */
        /* Peripheral Operation in TEST  mode: Disabled    */
        /* Peripheral Operation in RESET  mode: Disabled    */

/* ----------------------------------------------------------- */
/*      DRUN  Clock & Peripheral Clock Divider Settings    */
/* ----------------------------------------------------------- */

    ME.DRUN.R = 0x001F0070;
        /* I/O Power Down Control: Disabled    */
        /* Main Voltage Regulator Control: Enabled    */
        /* Data Flash Power Down Control: Normal    */
        /* Code Flash Power Down Control: Normal    */
        /* System PLL: ON    */
        /* Crystal Oscillator: ON    */
        /* 16MHz IRC:  ON    */
        /* System Clock Source: 16MHz internal RC oscillator     */

    CGM.SC_DC[0].R =0x80;    
        /* Peripheral Set 1 Clock Divider Status: Enabled */
        /* Peripheral Set 1 Clock Divider: 1 */
    CGM.SC_DC[1].R =0x80;    
        /* Peripheral Set 2 Clock Divider Status: Enabled */
        /* Peripheral Set 2 Clock Divider: 1 */
    CGM.SC_DC[2].R =0x80;    
        /* Peripheral Set 3 Clock Divider Status: Enabled */
        /* Peripheral Set 3 Clock Divider: 1 */


/* ----------------------------------------------------------- */
/*                     DRUN Re-Entry                    */
/* ----------------------------------------------------------- */

        /* Re-enter in DRUN mode to update the configuration*/
    ME.MCTL.R = 0x30005AF0;    
        /* Mode & Key */
    ME.MCTL.R = 0x3000A50F;    
        /* Mode & Key  Inverted */
    while(0x1 == ME.GS.B.S_MTRANS){};    
        /* Wait for mode entry to complete */
    while(0x3 != ME.GS.B.S_CURRENTMODE){};    
        /* Check DRUN mode has been entered  */

}
 
/*
 *######################################################################
 *                           End of File
 *######################################################################
*/



void mode_entry_change_mode(uint32_t mode)
{
	/**
	 * Get current mode.
	 * If requested mode is same , simply return.
	 * else enter the requested mode. 
	 */
	uint32_t val;
	val = (mode << 28);
	val |= 0x5AF0;
	ME.MCTL.R = val;
	
	val = (val & 0xFFFF0000) | 0xA50F;
	ME.MCTL.R = val;
	
	/* Wait for mode entry to complete */
	while(0x1 == ME.GS.B.S_MTRANS){};    
	//while(mode != ME.GS.B.S_CURRENTMODE){};
	while(mode != ME.GS.B.S_CURRENTMODE){};
}
 
/*
 *######################################################################
 *                           End of File
 *######################################################################
*/


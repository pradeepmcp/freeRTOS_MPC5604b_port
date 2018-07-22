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
 * file                   : pit_init.c
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
 * Brief Description      : PIT Initialization file
 *
 ******************************************************************************** 
 *
 * Detail Description     : File contains Periodic Interrupt Timer (PIT) parameter
 *                         initialization function. Along with PIT module, the
 *                         function configures parameters such as individual
 *                         channel status, interrupt status & timer load value.
 *
 ******************************************************************************** 
 *
 *######################################################################
*/

 
 
/********************  Dependent Include files here **********************/

#include "pit.h"


/********************* Initialization Function(s) *********************** */


void pit_init_fnc(void)
{
    PIT.PITMCR.B.MDIS   = 1;    
        /*Disable PIT for initialization         */

/* ----------------------------------------------------------- */
/*                     Configure Load Value Registers                */
/* ----------------------------------------------------------- */

    PIT.CH[0].LDVAL.R  = 0x03D09000;    
        /*value loaded in the Timer0: 128000    */
    
    PIT.CH[1].LDVAL.R  = 0x00000000;    
        /*value loaded in the Timer1: 0    */
    
    PIT.CH[2].LDVAL.R  = 0x00000000;    
        /*value loaded in the Timer2: 0    */
    
    PIT.CH[3].LDVAL.R  = 0x00000000;    
        /*value loaded in the Timer3: 0    */
    
    PIT.CH[4].LDVAL.R  = 0x00000000;    
        /*value loaded in the Timer4: 0    */
    
    PIT.CH[5].LDVAL.R  = 0x00000000;    
        /*value loaded in the Timer5: 0    */
    
    PIT.CH[6].LDVAL.R  = 0x00000000;    
        /*value loaded in the Timer6: 0    */
    
    PIT.CH[7].LDVAL.R  = 0x00000000;    
        /*value loaded in the Timer7: 0    */
    


/* ----------------------------------------------------------- */
/*                     Enable Interrupts                  */
/* ----------------------------------------------------------- */

    PIT.CH[0].TCTRL.B.TIE  = 0x1;    
        /*Timer 0 Interrupt : Enabled    */
    
    PIT.CH[1].TCTRL.B.TIE  = 0x0;    
        /*Timer 1 Interrupt : Disabled    */
    
    PIT.CH[2].TCTRL.B.TIE  = 0x0;    
        /*Timer 2 Interrupt : Disabled    */
    
    PIT.CH[3].TCTRL.B.TIE  = 0x0;    
        /*Timer 3 Interrupt : Disabled    */
    
    PIT.CH[4].TCTRL.B.TIE  = 0x0;    
        /*Timer 4 Interrupt : Disabled    */
    
    PIT.CH[5].TCTRL.B.TIE  = 0x0;    
        /*Timer 5 Interrupt : Disabled    */
    
    PIT.CH[6].TCTRL.B.TIE  = 0x0;    
        /*Timer 6 Interrupt : Disabled    */
    
    PIT.CH[7].TCTRL.B.TIE  = 0x0;    
        /*Timer 7 Interrupt : Disabled    */
    


/* ----------------------------------------------------------- */
/*                   Start Timers                 */
/* ----------------------------------------------------------- */

    PIT.CH[0].TCTRL.B.TEN = 0x1;    
        /*Start Timer 0 is : Enabled    */
    
    PIT.CH[1].TCTRL.B.TEN = 0x0;    
        /*Start Timer 1 is : Disabled    */
    
    PIT.CH[2].TCTRL.B.TEN = 0x0;    
        /*Start Timer 2 is : Disabled    */
    
    PIT.CH[3].TCTRL.B.TEN = 0x0;    
        /*Start Timer 3 is : Disabled    */
    
    PIT.CH[4].TCTRL.B.TEN = 0x0;    
        /*Start Timer 4 is : Disabled    */
    
    PIT.CH[5].TCTRL.B.TEN = 0x0;    
        /*Start Timer 5 is : Disabled    */
    
    PIT.CH[6].TCTRL.B.TEN = 0x0;    
        /*Start Timer 6 is : Disabled    */
    
    PIT.CH[7].TCTRL.B.TEN = 0x0;    
        /*Start Timer 7 is : Disabled    */
    

    PIT.PITMCR.B.MDIS = 1;    
        /*PIT Module : Enabled        */

}

void pit_config(INTCInterruptFn handler_fn, uint8_t channel, uint32_t interrupt_enable, uint16_t priority, uint32_t ld_val)
{
	PIT.PITMCR.B.MDIS = 1;
	PIT.PITMCR.B.FRZ = 0;
	PIT.CH[channel].TCTRL.B.TEN = 0;
	PIT.CH[channel].TCTRL.R  |= interrupt_enable;
	PIT.CH[channel].LDVAL.R = ld_val;
	INTC.PSR[PIT_PSR_BASE+channel].B.PRI = priority;
	INTC_InstallINTCInterruptHandler(handler_fn, PIT_PSR_BASE, (unsigned char) priority);
}

/*
 *######################################################################
 *                           End of File
 *######################################################################
*/


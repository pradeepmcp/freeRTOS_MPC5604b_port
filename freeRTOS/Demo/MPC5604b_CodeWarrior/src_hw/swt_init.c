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
 * file                   : swt_init.c
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
 * Brief Description      : SWT Initialization file
 *
 ******************************************************************************** 
 *
 * Detail Description     : File contains Software Watchdog Timer (SWT) parameter
 *                         initialization function. The function configures
 *                         SWT parameters such as watchdog status, watchdog
 *                         timeout, debug mode control, sleep mode control,
 *                         window mode status & window value. Also, the file has
 *                         a function for Watchdog Service Routine.
 *
 ******************************************************************************** 
 *
 *######################################################################
*/

 
 
/********************  Dependent Include files here **********************/

#include "swt_init.h"




/********************* Initialization Function(s) *********************** */


void swt_init_fnc(void)
{

        vint32_t init_status=0;        
        uint32_t delay=100;        
        /* Check whether the Hardware is enabled or not    */

        if(1 != SWT.CR.B.HLK)    
        {    
            SWT.SR.B.WSC = 0xC520;    
            SWT.SR.B.WSC = 0xD928;    
            /* Disable Software lock of register by writing sequence register with unlock data     */


            while((1 == SWT.CR.B.SLK) && (0 < (delay--))){}    
                /*Wait until Soft-Lock is disabled    */

            if(1 != SWT.CR.B.SLK)    
            {    
                    /*Proceed with initialization    */

                init_status = 0;    
            }    
            else    
            {    
                init_status = 1;    
                    /**SWT initialization cannot be proceed as software lock is still enabled    */

            }    
        }    
        else    
        {    
            init_status = 1;    
                /* SWT initialization cannot be proceed as Hardware lock is still enabled */
    
        }    
        if(0 == init_status)    
        {    
            SWT.CR.B.WEN =0;    
                /* Software Watchdog Timer: Disabled */
    
            SWT.TO.R = 0x500;    
                /* Software Watchdog Timer timeout is 10ms    */

            SWT.WN.R = 0x0;    
                /* Service Sequence window time: 0 ms    */

            SWT.CR.R = 0x8000010A;    
                /* Master Access Control for Master 0: Enabled     */
                /* SWT Reset on Invalid Access: Enabled    */
                /* SWT Window Mode: Disabled    */
                /* SWT Interrupt then Reset: Disabled    */
                /* SWT Hard Lock: Disabled    */
                /* SWT Soft Lock: Disabled    */
                /* SWT Clock Source Selected: IRC 128KHz     */
                /* SWT Stop Mode Control: Disabled    */
                /* SWT Debug Mode Control: Enabled    */
                /* Software Watchdog Timer: Disabled    */

        }    

}
/********************* SWT Service Sequence Function *********************** */
void swt_srvc_seq_fnc(void)
{

        SWT.SR.B.WSC = 0xA602;    
        SWT.SR.B.WSC = 0xB480;    
}


 
/*
 *######################################################################
 *                           End of File
 *######################################################################
*/


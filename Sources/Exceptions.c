/** 
 * FILE: Exceptions.c
 *
 *  DESCRIPTION: Setup of IVPR to point to the EXCEPTION_HANDLERS memory area 
 *               defined in the linker command file.
 *               Default setup of the e200z0h IVORxx registers.
 *
 * VERSION: 1.2    
*/

/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/

#include "Exceptions.h" /* Implement functions from this file */

/*----------------------------------------------------------------------------*/
/* Function Implementations                                                   */
/*----------------------------------------------------------------------------*/

#pragma push /* Save the current state */
/* Symbol EXCEPTION_HANDLERS is defined in the application linker command file (.lcf) 
   It is defined to the start of the code memory area used for the .__exception_handlers section. 
*/
/*lint -esym(752, EXCEPTION_HANDLERS) */
__declspec (section ".__exception_handlers") extern long EXCEPTION_HANDLERS;  
#pragma force_active on
#pragma function_align 16 /* We use 16 bytes alignment for Exception handlers */
__declspec(interrupt)
__declspec (section ".__exception_handlers")
void EXCEP_DefaultExceptionHandler(void)
{

}
#pragma force_active off
#pragma pop

__asm void EXCEP_InitExceptionHandlers(void)
{
nofralloc

    /* Set the IVPR to the Exception Handlers memory area defined in the lcf file */ 
    lis r0, EXCEPTION_HANDLERS@h
    ori r0, r0, EXCEPTION_HANDLERS@l
    mtivpr  r0
    /* IVORxx registers are "hard-wired" in the e200z0 and z0h cores */
    blr
}

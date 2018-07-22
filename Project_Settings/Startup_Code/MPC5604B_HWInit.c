/*
 *
 * FILE : MPC5604B_HWInit.c
 *
 * DESCRIPTION:
 *  This file contains the initialization for MPC5604B derivative.
 *
 *  VERSION: 1.0
 */

#include "MPC5604B.h"   /* platform development header */
#include "MPC5604B_HWInit.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Symbol L2SRAM_LOCATION is defined in the application linker command file (.lcf)
   It represents the start of the L2SRAM.
*/
/*lint -esym(752, L2SRAM_LOCATION) */
extern long L2SRAM_LOCATION;

/* Symbol L2SRAM_CNT is defined in the application linker command file (.lcf)
   It represents the how many writes with stmw,128 bytes each, are needed to cover
   the whole L2SRAM.
*/
extern long L2SRAM_CNT;

__asm void INIT_Derivative(void) 
{
nofralloc
    /* Disable WatchDog*/
    // *(volatile unsigned int*)0xfff38010 = 0x0000c520; 
    e_lis r9,0x0001
    e_add16i r9,r9,-15072
    e_lis r8,0xfff4
    e_stw r9,-32752(r8)

    //  *(volatile unsigned int*) 0xfff38010 = 0x0000d928; 
    e_lis r9,0x0001
    e_add16i r9,r9,-9944
    e_lis r8,0xfff4
    e_stw r9,-32752(r8)
    // *(volatile unsigned int*) 0xfff38000 = 0xff00000A; 
    e_lis r3,0xff00
    se_addi r3,0x000a
    e_lis r8,0xfff4
    e_stw r3,-32768(r8)
    
    /* SRAM initialization code*/
    lis r11,L2SRAM_LOCATION@h
    ori r11,r11,L2SRAM_LOCATION@l

    /* Loops to cover L2SRAM, stmw allows 128 bytes (32 GPRS x 4 bytes) writes */
    lis r12,L2SRAM_CNT@h
    ori r12,r12,L2SRAM_CNT@l
    mtctr r12

    init_l2sram_loop:
        stmw r0, 0(r11)        /* Write 32 GPRs to SRAM*/
        addi r11,r11,128      /* Inc the ram ptr; 32 GPRs * 4 bytes = 128B */
        bdnz init_l2sram_loop /* Loop for 48k of SRAM */
    blr
}

__asm void INIT_ExternalBusAndMemory(void)
{
nofralloc
    blr
}

#ifdef __cplusplus
}
#endif

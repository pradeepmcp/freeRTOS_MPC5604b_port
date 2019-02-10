/*
 * FILE: ivor_branch_table.c
 *   
 * COPYRIGHT (c) 2007-2012 Freescale Semiconductor, Inc. All rights reserved.
 *
 * DESCRIPTION: e200z0h IVOR branch table interrupts for core 0. 
 *
 *  Rev 1.0 Jul  6 2007 S.M. - Initial version 
 *  Rev 1.1 May 13 2008 D.F. - Adapted 551x version for e200z0h processors
 *  Rev 1.2 Sept 2012 H.C. 	- add IVOR comments 
 *  
 * VERSION: 1.1 
*/

#ifdef __cplusplus
extern "C" {
#endif

/* IVOR4 will call this handler */
extern void INTC_INTCInterruptHandler(void);
extern void vPortYield(void);

#pragma push

#define SIXTEEN_BYTES 16

#pragma section code_type ".ivor_branch_table"
#pragma force_active on
#pragma function_align 16  
#pragma require_prototypes off

asm void ivor_branch_table_p0(void) {
nofralloc
	.align SIXTEEN_BYTES
IVOR0trap:  e_b   IVOR0trap /* Critical Input interrupt handler */ 

	.align SIXTEEN_BYTES
IVOR1trap:  e_b	IVOR1trap /* Machine check / (NMI) interrupt handler */

	.align SIXTEEN_BYTES
IVOR2trap:  e_b	IVOR2trap /* Data Storage interrupt handler */

	.align SIXTEEN_BYTES
IVOR3trap:  e_b	IVOR3trap /* Instruction Storage interrupt handler */

	.align SIXTEEN_BYTES
IVOR4trap:  e_b   INTC_INTCInterruptHandler /* External Interrupt interrupt handler */

	.align SIXTEEN_BYTES
IVOR5trap:  e_b	IVOR5trap /* Alignment interrupt handler */

	.align SIXTEEN_BYTES
IVOR6trap:  e_b	IVOR6trap /* Program interrupt handler */

	.align SIXTEEN_BYTES
IVOR7trap:  e_b	IVOR7trap /* Floating-point unavailable interrupt handler */

.align SIXTEEN_BYTES
IVOR8trap:  e_b	vPortYield /* System call interrupt handler */

	.align SIXTEEN_BYTES
IVOR9trap:  e_b	IVOR9trap /* AP unavailable interrupt handler */

	.align SIXTEEN_BYTES
IVOR10trap: e_b   IVOR10trap /* Decrementer interrupt handler */

	.align SIXTEEN_BYTES
IVOR11trap: e_b	IVOR11trap /* Fixed Interval Timer interrupt handler */

	.align SIXTEEN_BYTES
IVOR12trap:  e_b	IVOR12trap /* Watchdog Timer interrupt handler */

	.align SIXTEEN_BYTES
IVOR13trap:  e_b	IVOR13trap /* Data TLB Error interrupt handler */

	.align SIXTEEN_BYTES
IVOR14trap:  e_b	IVOR14trap /* Instruction TLB Error interrupt handler */

	.align SIXTEEN_BYTES
IVOR15trap:  e_b  IVOR15trap  /* Debug Interrupt */
}

#pragma pop

#ifdef __cplusplus
}
#endif

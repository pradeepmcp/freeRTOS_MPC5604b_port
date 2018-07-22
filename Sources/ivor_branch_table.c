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

#pragma push

#define SIXTEEN_BYTES 16

#pragma section code_type ".ivor_branch_table"
#pragma force_active on
#pragma function_align 16  
#pragma require_prototypes off

asm void ivor_branch_table_p0(void) {
nofralloc
	.align SIXTEEN_BYTES
IVOR0trap:  b   IVOR0trap /* Critical Input interrupt handler */ 

	.align SIXTEEN_BYTES
IVOR1trap:  b	IVOR1trap /* Machine check / (NMI) interrupt handler */

	.align SIXTEEN_BYTES
IVOR2trap:  b	IVOR2trap /* Data Storage interrupt handler */

	.align SIXTEEN_BYTES
IVOR3trap:  b	IVOR3trap /* Instruction Storage interrupt handler */

	.align SIXTEEN_BYTES
IVOR4trap:  b   INTC_INTCInterruptHandler /* External Interrupt interrupt handler */

	.align SIXTEEN_BYTES
IVOR5trap:  b	IVOR5trap /* Alignment interrupt handler */

	.align SIXTEEN_BYTES
IVOR6trap:  b	IVOR6trap /* Program interrupt handler */

	.align SIXTEEN_BYTES
IVOR7trap:  b	IVOR7trap /* Floating-point unavailable interrupt handler */

.align SIXTEEN_BYTES
IVOR8trap:  b	IVOR8trap /* System call interrupt handler */

	.align SIXTEEN_BYTES
IVOR9trap:  b	IVOR9trap /* AP unavailable interrupt handler */

	.align SIXTEEN_BYTES
IVOR10trap: b   IVOR10trap /* Decrementer interrupt handler */

	.align SIXTEEN_BYTES
IVOR11trap:  b	IVOR11trap /* Fixed Interval Timer interrupt handler */

	.align SIXTEEN_BYTES
IVOR12trap:  b	IVOR12trap /* Watchdog Timer interrupt handler */

	.align SIXTEEN_BYTES
IVOR13trap:  b	IVOR13trap /* Data TLB Error interrupt handler */

	.align SIXTEEN_BYTES
IVOR14trap:  b	IVOR14trap /* Instruction TLB Error interrupt handler */

	.align SIXTEEN_BYTES
IVOR15trap:  b  IVOR15trap  /* Debug Interrupt */
}

#pragma pop

#ifdef __cplusplus
}
#endif

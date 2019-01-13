/*==================================================================================================
*
*   (c) Copyright 2015 Freescale Semiconductor Inc.
*   
*   This program is free software; you can redistribute it and/or modify it under
*   the terms of the GNU General Public License (version 2) as published by the
*   Free Software Foundation >>>> AND MODIFIED BY <<<< the FreeRTOS exception.
*
*   ***************************************************************************
*   >>!   NOTE: The modification to the GPL is included to allow you to     !<<
*   >>!   distribute a combined work that includes FreeRTOS without being   !<<
*   >>!   obliged to provide the source code for proprietary components     !<<
*   >>!   outside of the FreeRTOS kernel.                                   !<<
*   ***************************************************************************
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*   
*   You should have received a copy of the GNU General Public License
*   along with this program; if not, write to the Free Software
*   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*
==================================================================================================*/

/*
   STACK FRAME DESIGN: Depth: (0x98, or 152 bytes modulo 8 bytes = 19)
              ************* ______________
     0x94     *  GPR31    *    ^
     0x90     *  GPR30    *    |
     0x8C     *  GPR29    *    |
     0x88     *  GPR28    *    |
     0x84     *  GPR27    *    |
     0x80     *  GPR26    *    |
     0x7C     *  GPR25    *    |
     0x78     *  GPR24    *    |
     0x74     *  GPR23    *    |
     0x70     *  GPR22    *    |
     0x6C     *  GPR21    *    |
     0x68     *  GPR20    *    |
     0x64     *  GPR19    *    |
     0x60     *  GPR18    *    |
     0x5C     *  GPR17    *    |
     0x58     *  GPR16    *    |
     0x54     *  GPR15    *    |
     0x50     *  GPR14    *    |
     0x4C     *  GPR12    *    |
     0x48     *  GPR11    *    |
     0x44     *  GPR10    *    |
     0x40     *  GPR9     *    |
     0x3C     *  GPR8     *    |
     0x38     *  GPR7     *  GPRs (32 bit)
     0x34     *  GPR6     *    |
     0x30     *  GPR5     *    |
     0x2C     *  GPR4     *    |
     0x28     *  GPR3     *    |
     0x24     *  GPR0     * ___v__________
     0x20     *  XER      *    ^
     0x1C     *  CTR      *    |
     0x18     *  LR       *    |
     0x14     *  CR       * locals & padding for 8 byte alignment
     0x10     *  SRR1     *    |
     0x0C     *  SRR0     *    |
     0x08     *  padding  * ___v__________
     0x04     *  LR save  * Reserved for calling function
     0x00     *  SP       * Backchain (same as gpr1 in GPRs)
              *************
*/
    .extern vTaskSwitchContext
    .extern pxCurrentTCB

  .global vPortStartFirstTask
  .global __external_interrupt_handler
  .global vPortYield
  .global portRESTORE_CONTEXT
  .global portSAVE_CONTEXT

/*
  # CORE0 Interrupt Acknowledge Register addres
  .equ    INTC_IACKR_PRC0, 0xFC040020
  # CORE0 End Of Interrupt Register addres
  .equ    INTC_EOIR_PRC0,  0xFC040030
*/
  .equ	INTC_IACKR	0xFFF48010
  .equ	INTC_EOIR	0xFFF48018

  # load immediate word macro, has to be done with 2 instructions
 .macro    e_lwi    reg,val
    e_lis    \reg,\val@H
    e_or2i   \reg,\val@L
 .endm

 # Saves context to task stack
 .macro portSAVE_CONTEXT
  	e_stw     r1,-0x98 (r1)		/* store backchain 	*/
    e_add16i  r1,r1, -0x98       /* allocate stack 	*/
    e_stw	  r0,  0x24 (r1)	/* Store r0 working register  */

    e_stw     r3,  0x28 (r1)   		/* Store r3 */
    /* Save rest of context required by EABI */
    e_stmw    r14, 0x50 (r1)        /* save r14-r31 by store word multiple */
    e_stw     r12, 0x4C (r1)      	/* Store r12 */
    e_stw     r11, 0x48 (r1)      	/* Store r11 */
    e_stw     r10, 0x44 (r1)      	/* Store r10 */
    e_stw     r9,  0x40 (r1)      	/* Store r9 */
    e_stw     r8,  0x3C (r1)      	/* Store r8 */
    e_stw     r7,  0x38 (r1)      	/* Store r7 */
    e_stw     r6,  0x34 (r1)      	/* Store r6 */
    e_stw     r5,  0x30 (r1)      	/* Store r5 */
    e_stw     r4,  0x2C (r1)      	/* Store r4 */
    mfcr      r0                  	/* Store CR */
    e_stw     r0,  0x20 (r1)
    mfxer     r0                  	/* Store XER */
    e_stw     r0,  0x1C (r1)
    mfctr     r0                  	/* Store CTR */
    e_stw     r0,  0x18 (r1)
    mflr      r0                  	/* Store LR */
    e_stw     r0,  0x14 (r1)
    mfsrr1    r0                	/* Store SRR1 (must be done before enabling EE) */
    e_stw     r0,  0x10 (r1)
    mfsrr0    r0                	/* Store SRR0 (must be done before enabling EE) */
    e_stw     r0,  0x0C (r1)
    
  	
  
    #e_stw         r1,-0x98 (r1)       # store backchain
    #e_sub16i      r1,r1, 0x98         # allocate stack
    #e_stmw    r14, 0x50 (r1)          # save r14-r31 by store word multiple
    #.long 0x18011124                  # save r0, r3-r12 by e_stmvgprw 0x24 (r1)
    #.long 0x18211114                  # save CR, LR, CTR, XER by e_stmvsprw 0x14 (r1)
    #.long 0x1881110C                  # save SRR0, SRR1 by e_stmvsrrw 0x0C (r1)
 .endm

  # Restores context from task stack
 .macro portRESTORE_CONTEXT
  	e_lwz     r0,  0x0C (r1)      /* Restore SRR0 */
    mtsrr0    r0
    e_lwz     r0,  0x10 (r1)      /* Restore SRR1 */
    mtsrr1    r0
	e_lwz     r0,  0x14 (r1)      /* Restore LR */
    mtlr      r0
    e_lwz     r0,  0x18 (r1)      /* Restore CTR */
    mtctr     r0
    e_lwz     r0,  0x1C (r1)      /* Restore XER */
    mtxer     r0
    e_lwz     r0,  0x20 (r1)      /* Restore CR */
    mtcrf     0xff, r0
    e_lwz     r5,  0x30 (r1)      /* Restore r5 */
    e_lwz     r6,  0x34 (r1)      /* Restore r6 */
    e_lwz     r7,  0x38 (r1)      /* Restore r7 */
    e_lwz     r8,  0x3C (r1)      /* Restore r8 */
    e_lwz     r9,  0x40 (r1)      /* Restore r9 */
    e_lwz     r10, 0x44 (r1)      /* Restore r10 */
    e_lwz     r11, 0x48 (r1)      /* Restore r11 */
    e_lwz     r12, 0x4C (r1)      /* Restore r12 */

	e_lwz     r3,  0x28 (r1)      /* Restore r3 */
    e_lwz     r4,  0x2C (r1)      /* Restore r4 */

    e_lmw     r14, 0x50 (r1)      /* load word multiple r14-r31 */

    e_lwz     r0,  0x24 (r1)      /* Restore r0 */

    /* Restore space on stack */
    e_add16i  r1, r1, 0x98
    
    #.long 0x1881100C             # load SRR0, SRR1 by e_lmvsrrw 0x0C (r1)
    #.long 0x18211014             # load CR, LR, CTR, XER by e_lmvsprw 0x14 (r1)
    #.long 0x18011024             # load r0, r3-r12 by e_lmvgprw 0x24 (r1)
    #e_lmw     r14, 0x50 (r1)     # load word multiple r14-r31
    #e_add16i      r1, r1, 0x98   # Reclaim stack space
 .endm

 # Macro to put task stack pointer into the TCB  (r3 used as scratch register)
 .macro portPUSH_TASK
    e_lis     r3, pxCurrentTCB@ha
    e_lwz     r3, pxCurrentTCB@l(r3)
    se_stw    r1, 0x00 (r3)       # store stack pointer
 .endm
  
  # Macro to get the task stack pointer from the TCB (r3 used as scratch register)
 .macro portPOP_TASK
    e_lis    r3, pxCurrentTCB@ha
    e_lwz    r3, pxCurrentTCB@l(r3)
    e_lwz    r1, 0x00 (r3)    # load stack pointer
.endm

.text
.align 4
vPortStartFirstTask:
  portPOP_TASK				# pxCurrentTCB should already point to the highest priority task
  portRESTORE_CONTEXT
  se_rfi					# Return into the first task

#.section .__exception_handlers
INTC_INTCInterruptHandler:
prolog:
	e_stw    r1, -0x98 (r1)    /* Create stack frame */
	e_add16i   r1,r1,(-0x98)
	e_stw r0,  0x24 (r1)        /* Store r0 working register  */
	
	/* Save SRR0 and SRR1 */
	mfsrr1  r0                /* Store SRR1 (must be done before enabling EE) */
	e_stw     r0,  0x10 (r1)
	mfsrr0  r0                /* Store SRR0 (must be done before enabling EE) */
	e_stw     r0,  0x0C (r1)
	
	/* Clear request to processor; r3 contains the address of the ISR */
	e_stw     r3,  0x28 (r1)    /* Store r3 */
	e_lis     r3, INTC_IACKR@h  /* Read pointer into ISR Vector Table & store in r3     */
	#e_ori     r3, r3, INTC_IACKR@l
	e_lwz	  r3, INTC_IACKR@l(r3)
	
	e_lwz     r3, 0x0(r3)       /* Load INTC_IACKR, which clears request to processor   */
	e_lwz     r3, 0x0(r3)       /* Read ISR address from ISR Vector Table using pointer */
	
	/* Enable processor recognition of interrupts */
	wrteei  1                   /* Set MSR[EE]=1  */
	
	/* Save rest of context required by EABI */
	e_stmw	r14, 0x50 (r1)		/* save r14-r31 by store word multiple */
	e_stw     r12, 0x4C (r1)      /* Store r12 */
	e_stw     r11, 0x48 (r1)      /* Store r11 */
	e_stw     r10, 0x44 (r1)      /* Store r10 */
	e_stw     r9,  0x40 (r1)      /* Store r9 */
	e_stw     r8,  0x3C (r1)      /* Store r8 */
	e_stw     r7,  0x38 (r1)      /* Store r7 */
	e_stw     r6,  0x34 (r1)      /* Store r6 */
	e_stw     r5,  0x30 (r1)      /* Store r5 */
	e_stw     r4,  0x2C (r1)      /* Store r4 */
	mfcr    r0                  /* Store CR */
	e_stw     r0,  0x20 (r1)
	mfxer   r0                  /* Store XER */
	e_stw     r0,  0x1C (r1)
	mfctr   r0                  /* Store CTR */
	e_stw     r0,  0x18 (r1)
	mflr    r0                  /* Store LR */
	e_stw     r0,  0x14 (r1)

	/* Push task */
	
	/* Branch to ISR handler address from SW vector table */
	mtlr    r3                  /* Store ISR address to LR to use for branching later */
	se_blrl                        /* Branch to ISR, but return here */
	
	epilog:
	/* Pop task */
		
	/* Restore context required by EABI (except working registers) */
	e_lwz     r0,  0x14 (r1)      /* Restore LR */
	mtlr    r0
	e_lwz     r0,  0x18 (r1)      /* Restore CTR */
	mtctr   r0
	e_lwz     r0,  0x1C (r1)      /* Restore XER */
	mtxer   r0
	e_lwz     r0,  0x20 (r1)      /* Restore CR */
	mtcrf   0xff, r0
	e_lmw     r14, 0x50 (r1)		/* load word multiple r14-r31 */
	e_lwz     r5,  0x30 (r1)      /* Restore r5 */
	e_lwz     r6,  0x34 (r1)      /* Restore r6 */
	e_lwz     r7,  0x38 (r1)      /* Restore r7 */
	e_lwz     r8,  0x3C (r1)      /* Restore r8 */
	e_lwz     r9,  0x40 (r1)      /* Restore r9 */
	e_lwz     r10, 0x44 (r1)      /* Restore r10 */
	e_lwz     r11, 0x48 (r1)      /* Restore r11 */
	e_lwz     r12, 0x4C (r1)      /* Restore r12 */
	
	/* Disable processor recognition of interrupts */
	wrteei  0
	
	/* Ensure interrupt flag has finished clearing */
	mbar    0
	
	/* Write 0 to INTC_EOIR, informing INTC to lower priority */
	e_li      r3, 0
	e_lis     r4, INTC_EOIR@h     /* Load upper half of INTC_EOIR address to r4 */
	#e_ori     r4, r4, INTC_EOIR@l
	e_stw	  r4, INTC_EOIR@l(r4)
	
	e_stw     r3, 0(r4)           /* Write 0 to INTC_EOIR */
	
	/* Restore Working Registers */
	e_lwz     r3,  0x28 (r1)      /* Restore r3 */
	e_lwz     r4,  0x2C (r1)      /* Restore r4 */
	
	/* Retrieve SRR0 and SRR1 */
	e_lwz     r0,  0x0C (r1)      /* Restore SRR0 */
	mtsrr0  r0
	e_lwz     r0,  0x10 (r1)      /* Restore SRR1 */
	mtsrr1  r0
	
	/* Restore Other Working Registers */
	e_lwz     r0,  0x24 (r1)      /* Restore r0 */
	
	/* Restore space on stack */
	e_add16i    r1, r1, 0x98
	
	/* End of Interrupt */
	se_rfi

    
/*
__external_interrupt_handler:

  portSAVE_CONTEXT
  portPUSH_TASK

  # Read in R3 the content of INTC_IACKR
  e_lis     r3, INTC_IACKR_PRC0@ha
  e_lwz     r3, INTC_IACKR_PRC0@l(r3)
  
  # we're interested in the INTVEC field value only
  e_lwi     r4,0x0FFC
  se_and    r3,r4
  
  # R4 = OSInterruptsHandlerTable
  e_lwi     r4, OSInterruptsHandlerTable

  # r3 = OSInterruptsHandlerTable[r3]
  se_add    r3,r4
  se_lwz    r3, 0x0(r3)
  
  # Store ISR address to LR to use for branching later
  mtlr      r3
  
  # Branch to user ISR, but return here
  se_blrl

  # Ensure store to clear interrupt's flag bit completed
  mbar      0

  # INTC_EOIR_PRC0 = 0;
  se_li     r4, 0
  e_lis     r3, INTC_EOIR_PRC0@ha
  e_stw     r4, INTC_EOIR_PRC0@l(r3)

  portPOP_TASK
  portRESTORE_CONTEXT
  
  # End of Interrupt - jump back into a task
  se_rfi
*/

.text
.align 4
vPortYield:
    portSAVE_CONTEXT
    portPUSH_TASK

    e_bl vTaskSwitchContext

    portPOP_TASK
    portRESTORE_CONTEXT
    
    # Return into a task
    se_rfi

  # end of assembler code
  .end

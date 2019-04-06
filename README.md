# freeRTOS_MPC5604b_port
Porting of FreeRTOS to MPC5604B. 
freeRTOS version: 10.0.1

Reference port used:
MPC5746C

TRK-MPC5604B is the platform used.
https://www.nxp.com/products/no-longer-manufactured/mpc5604b-startertrak-development-kit:TRK-MPC5604B?
 
Currently I have tested the project for RAM Build configuration only. 
Will update once I test for Flash Build configuration. 

Codewarrior Version : 10.7 
The following settings need to be enabled in codewarrior
c/c++ build -> settings -> PowerPC CPU -> Compress for PowerPC VLE (zen)
c/c++ build -> settings -> PowerPC Compiler -> Processor -> Translate PPC ASM to VLE ASM (ZEN)

"Compress for PowerPC VLE (zen)" makes sure code is placed in .text_vle section instead of .text section. 

Currently tested:
Scheduler
vTaskDelayUntil()
vTaskPrioritySet() and vTaskPriorityGet()
Queue send and receive
Binary semaphore
xTaskNotifyGive() and xTaskNotifyTake() as mutex between two processes. 

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


Directory structure:
Only specific files are mentioned below for brevity. 
Root                                                                             
  |---freeRTOS 
  |    |---Demo
  |		   |---MPC5604b_CodeWarrior
  |		   		|---include
  |    				|---freeRTOSConfig.h                                                      
  |				|---src_hw     (Machine init specific code)
  |				|---main.c 	   (Application code)                                                             
  |    |---Source                                                                
  |        |---include                                                           
  |             |---portable                                                     
  |                  |---CodeWarrior                                             
  |                  |    |---PowerPC_MPC560xB  (MPC5604B specific code. Refer freeRTOS documentation for more details.)                                
  |                  |         |---port.c                                        
  |                  |         |---portmacro.h 
  |					 |		   |---portasm.s                                  
  |                  |---MemMang                                                 
  |                  |    |---heap_1.c                                           
  |                                                                              
  |---Sources(Codewarrior project specific code)                                 
  |    |---main.c                                                                
  |    |---src_hw                  
  |---Project_Headers 
 
 
Currently tested:
Scheduler
vTaskDelayUntil()
vTaskPrioritySet() and vTaskPriorityGet()
Queue send and receive
Binary semaphore
xTaskNotifyGive() and xTaskNotifyTake() as mutex between two processes. 

                                                           
  
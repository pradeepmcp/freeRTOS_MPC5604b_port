# freeRTOS_MPC5604b_port
Porting of FreeRTOS to MPC5604B. 
freeRTOS version: 10.0.1

Reference port used:
MPC5746C

TRK-MPC5604B is the platform used.
https://www.nxp.com/products/no-longer-manufactured/mpc5604b-startertrak-development-kit:TRK-MPC5604B?

IDE:
Codewarrior Version : 10.7 (Available only for Windows OS).

IDE setup:
The following settings need to be enabled in CodeWarrior IDE:
1. Select the "Project" menu --> goto "Properties" --> Select "C/C++ build" -> settings -> PowerPC CPU -> Compress for PowerPC VLE (zen)
2. Select the "Project" menu --> goto "Properties" --> Select "C/C++ build" -> settings -> PowerPC Compiler -> Processor -> Translate PPC ASM to VLE ASM (ZEN)

"Compress for PowerPC VLE (zen)" makes sure code is placed in .text_vle section instead of .text section in the elf binary.

How to start:
1. Clone the repository.
2. Open CodeWarrior --> goto "File" menu --> Select "import" option --> In the pop up window, under "General" menu, select "Existing Projects into Workspace" --> provide the path the clone repository --> Select the check box against the name of the project --> Click "Finish"

Currently tested features:
Scheduler
vTaskDelayUntil()
vTaskPrioritySet() and vTaskPriorityGet()
Queue send and receive
Binary semaphore
xTaskNotifyGive() and xTaskNotifyTake() as mutex between two processes. 

We have tested the project for RAM Build configuration only. 
Will update once I test for Flash Build configuration.

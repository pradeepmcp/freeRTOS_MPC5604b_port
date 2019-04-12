# freeRTOS_MPC5604b_port
Porting of FreeRTOS to MPC5604B. 
freeRTOS version: 10.0.1

Reference port used:
MPC5746C

TRK-MPC5604B is the platform used.
https://www.nxp.com/products/no-longer-manufactured/mpc5604b-startertrak-development-kit:TRK-MPC5604B?

IDE:
Codewarrior Version : 10.7 (Available only for Windows OS).
The latest version can be obtained in https://www.nxp.com/

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

Reference documentations:
freeRTOS:
https://www.freertos.org/FreeRTOS-quick-start-guide.html#page_top
A lot of other topics are covered in www.freertos.org

MPC5604B
1. Reference Manual:
  https://www.nxp.com/docs/en/reference-manual/MPC5604BCRM.pdf

PPC Arhcitecture and programming:
1. PPC Book E architecture:
  https://www.st.com/content/ccc/resource/technical/document/reference_manual/8b/6f/4e/d6/72/82/45/78/CD00164807.pdf/files/CD00164807.pdf/jcr:content/translations/en.CD00164807.pdf
2. e200z core reference manual:
  https://www.nxp.com/docs/en/reference-manual/e200z0RM.pdf
3. PPC EABI reference manual:
  https://www.nxp.com/docs/en/application-note/PPCEABI.pdf
4. PPC Variable Length Encoding: (Good coverage on VLE instructions)
  https://drive.google.com/drive/folders/11an9Hp4jSgfs7cfD1QkB76o-8EDCjFd-
5. Variable-Length Encoding (VLE) Extension Programming Interface Manual Assembly programming:
  https://www.nxp.com/docs/en/supporting-information/VLEPIM.pdf

Codewarrior:
1. Assembler Reference
  https://www.nxp.com/docs/en/reference-manual/ASMX86RM.pdf
2. Compiler reference
  https://www.nxp.com/docs/en/reference-manual/CCOMPILERRM.pdf
3. CodeWarrior linker command file(LCF)
  https://www.nxp.com/docs/en/application-note/AN4497.pdf

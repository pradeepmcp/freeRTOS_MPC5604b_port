# freeRTOS_MPC5604b_port
Porting of FreeRTOS to MPC5604B. 

Reference port used:
MPC5746C
freeRTOS version: 10.0.1

This project is work in progress. Will update the README once usable.

The project needs to be cleaned up. Until the cleanup is done, please exclude the following files from the build to avoid compilation errors. 

Currently I have tested the project for RAM Build configuration only. 
Will update once I test for Flash Build configuration. 

Codewarrior Version : 10.7 
The following settings need to be enabled in codewarrior
c/c++ build -> settings -> PowerPC CPU -> Compress for PowerPC VLE (zen)
c/c++ build -> settings -> PowerPC Compiler -> Processor -> Translate PPC ASM to VLE ASM (ZEN)

"Compress for PowerPC VLE (zen)" makes sure code is placed in .text_vle section instead of .text section. 

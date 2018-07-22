/**
* FILE : MPC5604B_Startup.c
 *
 * DESCRIPTION:
 *  This file contains the entry point for user code.
 *  It calls the library __start routine which makes standard application
 *  initialization.
 *
 *  VERSION: 1.0
 */

#ifdef __cplusplus
extern "C" {
#endif

/* primary entry point */
__declspec(section ".init") extern void __startup(int argc, char **argv, char **envp);
extern asm void __start(register int argc, register char **argv, register char **envp);

#ifdef __cplusplus
}
#endif

asm void __startup(register int argc, register char **argv, register char **envp)
{
    nofralloc  /* explicitly no stack */
    /* frame allocation */
    // call standard application initialization
    bl __start
}


#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE. 
 *
 * See http://www.freertos.org/a00110.html.
 *----------------------------------------------------------*/

#define configUSE_PREEMPTION                        1
#define configUSE_IDLE_HOOK                         0
#define configUSE_TICK_HOOK                         1

/* 
 * tune this to the actual frequency used by the PIT in RUN0 mode 
 * init_sys(), configures RUN0 with pll to 64MHZ and also as sysclk
 */
#define configCPU_CLOCK_HZ                         ((unsigned portLONG ) 64000000 )
#define configTICK_RATE_HZ                         ((TickType_t) 1000 )

#define configMAX_PRIORITIES                       (( unsigned portBASE_TYPE ) 5 )
#define configMINIMAL_STACK_SIZE                   ((unsigned portSHORT ) 256)
#define configTOTAL_HEAP_SIZE                      ((size_t) (6 * 1024) )
#define configMAX_TASK_NAME_LEN                    ( 13 )
#define configUSE_TRACE_FACILITY                    0
#define configUSE_16_BIT_TICKS                      0
#define configIDLE_SHOULD_YIELD                     1
#define configUSE_MUTEXES                           1

#define configCHECK_FOR_STACK_OVERFLOW              0
#define configUSE_COUNTING_SEMAPHORES               0
#define configUSE_APPLICATION_TASK_TAG              0
#define configUSE_FPU                               0

/* MPC5604B specific: pit channel to use 0-15 */
#define configUSE_PIT_CHANNEL                     0


/* Co-routine definitions. */
#define configUSE_CO_ROUTINES                     0
#define configMAX_CO_ROUTINE_PRIORITIES         ( 4 )

/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */
#define INCLUDE_vTaskPrioritySet                  1
#define INCLUDE_uxTaskPriorityGet                 1
#define INCLUDE_vTaskDelete                       0
#define INCLUDE_vTaskCleanUpResources             0
#define INCLUDE_vTaskSuspend                      1
#define INCLUDE_vResumeFromISR                    1
#define INCLUDE_vTaskDelayUntil                   1
#define INCLUDE_vTaskDelay                        1
#define INCLUDE_xTaskGetSchedulerState            0
#define INCLUDE_xTaskGetCurrentTaskHandle         0
#define INCLUDE_uxTaskGetStackHighWaterMark       0




#endif /* FREERTOS_CONFIG_H */



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../freeRTOS/Source/croutine.c" \
"../freeRTOS/Source/event_groups.c" \
"../freeRTOS/Source/list.c" \
"../freeRTOS/Source/queue.c" \
"../freeRTOS/Source/stream_buffer.c" \
"../freeRTOS/Source/tasks.c" \
"../freeRTOS/Source/timers.c" \

C_SRCS += \
../freeRTOS/Source/croutine.c \
../freeRTOS/Source/event_groups.c \
../freeRTOS/Source/list.c \
../freeRTOS/Source/queue.c \
../freeRTOS/Source/stream_buffer.c \
../freeRTOS/Source/tasks.c \
../freeRTOS/Source/timers.c \

OBJS += \
./freeRTOS/Source/croutine_c.obj \
./freeRTOS/Source/event_groups_c.obj \
./freeRTOS/Source/list_c.obj \
./freeRTOS/Source/queue_c.obj \
./freeRTOS/Source/stream_buffer_c.obj \
./freeRTOS/Source/tasks_c.obj \
./freeRTOS/Source/timers_c.obj \

OBJS_QUOTED += \
"./freeRTOS/Source/croutine_c.obj" \
"./freeRTOS/Source/event_groups_c.obj" \
"./freeRTOS/Source/list_c.obj" \
"./freeRTOS/Source/queue_c.obj" \
"./freeRTOS/Source/stream_buffer_c.obj" \
"./freeRTOS/Source/tasks_c.obj" \
"./freeRTOS/Source/timers_c.obj" \

C_DEPS += \
./freeRTOS/Source/croutine_c.d \
./freeRTOS/Source/event_groups_c.d \
./freeRTOS/Source/list_c.d \
./freeRTOS/Source/queue_c.d \
./freeRTOS/Source/stream_buffer_c.d \
./freeRTOS/Source/tasks_c.d \
./freeRTOS/Source/timers_c.d \

OBJS_OS_FORMAT += \
./freeRTOS/Source/croutine_c.obj \
./freeRTOS/Source/event_groups_c.obj \
./freeRTOS/Source/list_c.obj \
./freeRTOS/Source/queue_c.obj \
./freeRTOS/Source/stream_buffer_c.obj \
./freeRTOS/Source/tasks_c.obj \
./freeRTOS/Source/timers_c.obj \

C_DEPS_QUOTED += \
"./freeRTOS/Source/croutine_c.d" \
"./freeRTOS/Source/event_groups_c.d" \
"./freeRTOS/Source/list_c.d" \
"./freeRTOS/Source/queue_c.d" \
"./freeRTOS/Source/stream_buffer_c.d" \
"./freeRTOS/Source/tasks_c.d" \
"./freeRTOS/Source/timers_c.d" \


# Each subdirectory must supply rules for building sources it contributes
freeRTOS/Source/croutine_c.obj: ../freeRTOS/Source/croutine.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"freeRTOS/Source/croutine.args" -o "freeRTOS/Source/croutine_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

freeRTOS/Source/%.d: ../freeRTOS/Source/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

freeRTOS/Source/event_groups_c.obj: ../freeRTOS/Source/event_groups.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"freeRTOS/Source/event_groups.args" -o "freeRTOS/Source/event_groups_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

freeRTOS/Source/list_c.obj: ../freeRTOS/Source/list.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"freeRTOS/Source/list.args" -o "freeRTOS/Source/list_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

freeRTOS/Source/queue_c.obj: ../freeRTOS/Source/queue.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"freeRTOS/Source/queue.args" -o "freeRTOS/Source/queue_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

freeRTOS/Source/stream_buffer_c.obj: ../freeRTOS/Source/stream_buffer.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"freeRTOS/Source/stream_buffer.args" -o "freeRTOS/Source/stream_buffer_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

freeRTOS/Source/tasks_c.obj: ../freeRTOS/Source/tasks.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"freeRTOS/Source/tasks.args" -o "freeRTOS/Source/tasks_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

freeRTOS/Source/timers_c.obj: ../freeRTOS/Source/timers.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"freeRTOS/Source/timers.args" -o "freeRTOS/Source/timers_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '



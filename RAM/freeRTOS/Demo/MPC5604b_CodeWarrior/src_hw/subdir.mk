################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/intc_init.c" \
"../freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/intc_pit.c" \
"../freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/pit.c" \
"../freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/swt_init.c" \
"../freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/sys_init.c" \
"../freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/sysclk.c" \

C_SRCS += \
../freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/intc_init.c \
../freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/intc_pit.c \
../freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/pit.c \
../freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/swt_init.c \
../freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/sys_init.c \
../freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/sysclk.c \

OBJS += \
./freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/intc_init_c.obj \
./freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/intc_pit_c.obj \
./freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/pit_c.obj \
./freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/swt_init_c.obj \
./freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/sys_init_c.obj \
./freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/sysclk_c.obj \

OBJS_QUOTED += \
"./freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/intc_init_c.obj" \
"./freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/intc_pit_c.obj" \
"./freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/pit_c.obj" \
"./freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/swt_init_c.obj" \
"./freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/sys_init_c.obj" \
"./freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/sysclk_c.obj" \

C_DEPS += \
./freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/intc_init_c.d \
./freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/intc_pit_c.d \
./freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/pit_c.d \
./freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/swt_init_c.d \
./freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/sys_init_c.d \
./freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/sysclk_c.d \

OBJS_OS_FORMAT += \
./freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/intc_init_c.obj \
./freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/intc_pit_c.obj \
./freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/pit_c.obj \
./freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/swt_init_c.obj \
./freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/sys_init_c.obj \
./freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/sysclk_c.obj \

C_DEPS_QUOTED += \
"./freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/intc_init_c.d" \
"./freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/intc_pit_c.d" \
"./freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/pit_c.d" \
"./freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/swt_init_c.d" \
"./freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/sys_init_c.d" \
"./freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/sysclk_c.d" \


# Each subdirectory must supply rules for building sources it contributes
freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/intc_init_c.obj: ../freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/intc_init.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/intc_init.args" -o "freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/intc_init_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/%.d: ../freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/intc_pit_c.obj: ../freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/intc_pit.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/intc_pit.args" -o "freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/intc_pit_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/pit_c.obj: ../freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/pit.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/pit.args" -o "freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/pit_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/swt_init_c.obj: ../freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/swt_init.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/swt_init.args" -o "freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/swt_init_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/sys_init_c.obj: ../freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/sys_init.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/sys_init.args" -o "freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/sys_init_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/sysclk_c.obj: ../freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/sysclk.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/sysclk.args" -o "freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/sysclk_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '



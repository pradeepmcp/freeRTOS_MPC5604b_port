################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../freeRTOS/Demo/MPC5604b_CodeWarrior/main.c" \

C_SRCS += \
../freeRTOS/Demo/MPC5604b_CodeWarrior/main.c \

OBJS += \
./freeRTOS/Demo/MPC5604b_CodeWarrior/main_c.obj \

OBJS_QUOTED += \
"./freeRTOS/Demo/MPC5604b_CodeWarrior/main_c.obj" \

C_DEPS += \
./freeRTOS/Demo/MPC5604b_CodeWarrior/main_c.d \

OBJS_OS_FORMAT += \
./freeRTOS/Demo/MPC5604b_CodeWarrior/main_c.obj \

C_DEPS_QUOTED += \
"./freeRTOS/Demo/MPC5604b_CodeWarrior/main_c.d" \


# Each subdirectory must supply rules for building sources it contributes
freeRTOS/Demo/MPC5604b_CodeWarrior/main_c.obj: ../freeRTOS/Demo/MPC5604b_CodeWarrior/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"freeRTOS/Demo/MPC5604b_CodeWarrior/main.args" -o "freeRTOS/Demo/MPC5604b_CodeWarrior/main_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

freeRTOS/Demo/MPC5604b_CodeWarrior/%.d: ../freeRTOS/Demo/MPC5604b_CodeWarrior/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '



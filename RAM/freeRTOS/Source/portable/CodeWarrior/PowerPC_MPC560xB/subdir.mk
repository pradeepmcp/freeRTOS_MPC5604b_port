################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../freeRTOS/Source/portable/CodeWarrior/PowerPC_MPC560xB/port.c" \

C_SRCS += \
../freeRTOS/Source/portable/CodeWarrior/PowerPC_MPC560xB/port.c \

S_SRCS += \
../freeRTOS/Source/portable/CodeWarrior/PowerPC_MPC560xB/portasm.s \

S_SRCS_QUOTED += \
"../freeRTOS/Source/portable/CodeWarrior/PowerPC_MPC560xB/portasm.s" \

S_DEPS_QUOTED += \
"./freeRTOS/Source/portable/CodeWarrior/PowerPC_MPC560xB/portasm_s.d" \

OBJS += \
./freeRTOS/Source/portable/CodeWarrior/PowerPC_MPC560xB/port_c.obj \
./freeRTOS/Source/portable/CodeWarrior/PowerPC_MPC560xB/portasm_s.obj \

S_DEPS += \
./freeRTOS/Source/portable/CodeWarrior/PowerPC_MPC560xB/portasm_s.d \

OBJS_QUOTED += \
"./freeRTOS/Source/portable/CodeWarrior/PowerPC_MPC560xB/port_c.obj" \
"./freeRTOS/Source/portable/CodeWarrior/PowerPC_MPC560xB/portasm_s.obj" \

C_DEPS += \
./freeRTOS/Source/portable/CodeWarrior/PowerPC_MPC560xB/port_c.d \

OBJS_OS_FORMAT += \
./freeRTOS/Source/portable/CodeWarrior/PowerPC_MPC560xB/port_c.obj \
./freeRTOS/Source/portable/CodeWarrior/PowerPC_MPC560xB/portasm_s.obj \

C_DEPS_QUOTED += \
"./freeRTOS/Source/portable/CodeWarrior/PowerPC_MPC560xB/port_c.d" \


# Each subdirectory must supply rules for building sources it contributes
freeRTOS/Source/portable/CodeWarrior/PowerPC_MPC560xB/port_c.obj: ../freeRTOS/Source/portable/CodeWarrior/PowerPC_MPC560xB/port.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"freeRTOS/Source/portable/CodeWarrior/PowerPC_MPC560xB/port.args" -o "freeRTOS/Source/portable/CodeWarrior/PowerPC_MPC560xB/port_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

freeRTOS/Source/portable/CodeWarrior/PowerPC_MPC560xB/%.d: ../freeRTOS/Source/portable/CodeWarrior/PowerPC_MPC560xB/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

freeRTOS/Source/portable/CodeWarrior/PowerPC_MPC560xB/portasm_s.obj: ../freeRTOS/Source/portable/CodeWarrior/PowerPC_MPC560xB/portasm.s
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: PowerPC Assembler'
	"$(PAToolsDirEnv)/mwasmeppc" @@"freeRTOS/Source/portable/CodeWarrior/PowerPC_MPC560xB/portasm.args" -o "freeRTOS/Source/portable/CodeWarrior/PowerPC_MPC560xB/portasm_s.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

freeRTOS/Source/portable/CodeWarrior/PowerPC_MPC560xB/%.d: ../freeRTOS/Source/portable/CodeWarrior/PowerPC_MPC560xB/%.s
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '



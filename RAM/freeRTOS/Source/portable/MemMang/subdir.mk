################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../freeRTOS/Source/portable/MemMang/heap_1.c" \

C_SRCS += \
../freeRTOS/Source/portable/MemMang/heap_1.c \

OBJS += \
./freeRTOS/Source/portable/MemMang/heap_1_c.obj \

OBJS_QUOTED += \
"./freeRTOS/Source/portable/MemMang/heap_1_c.obj" \

C_DEPS += \
./freeRTOS/Source/portable/MemMang/heap_1_c.d \

OBJS_OS_FORMAT += \
./freeRTOS/Source/portable/MemMang/heap_1_c.obj \

C_DEPS_QUOTED += \
"./freeRTOS/Source/portable/MemMang/heap_1_c.d" \


# Each subdirectory must supply rules for building sources it contributes
freeRTOS/Source/portable/MemMang/heap_1_c.obj: ../freeRTOS/Source/portable/MemMang/heap_1.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"freeRTOS/Source/portable/MemMang/heap_1.args" -o "freeRTOS/Source/portable/MemMang/heap_1_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

freeRTOS/Source/portable/MemMang/%.d: ../freeRTOS/Source/portable/MemMang/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '



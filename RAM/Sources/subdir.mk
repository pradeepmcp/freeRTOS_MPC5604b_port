################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Exceptions.c" \
"../Sources/IntcInterrupts.c" \
"../Sources/ivor_branch_table.c" \

C_SRCS += \
../Sources/Exceptions.c \
../Sources/IntcInterrupts.c \
../Sources/ivor_branch_table.c \

OBJS += \
./Sources/Exceptions_c.obj \
./Sources/IntcInterrupts_c.obj \
./Sources/ivor_branch_table_c.obj \

OBJS_QUOTED += \
"./Sources/Exceptions_c.obj" \
"./Sources/IntcInterrupts_c.obj" \
"./Sources/ivor_branch_table_c.obj" \

C_DEPS += \
./Sources/Exceptions_c.d \
./Sources/IntcInterrupts_c.d \
./Sources/ivor_branch_table_c.d \

OBJS_OS_FORMAT += \
./Sources/Exceptions_c.obj \
./Sources/IntcInterrupts_c.obj \
./Sources/ivor_branch_table_c.obj \

C_DEPS_QUOTED += \
"./Sources/Exceptions_c.d" \
"./Sources/IntcInterrupts_c.d" \
"./Sources/ivor_branch_table_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/Exceptions_c.obj: ../Sources/Exceptions.c
	@echo 'Building file: $<'
	@echo 'Executing target #18 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Exceptions.args" -o "Sources/Exceptions_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/IntcInterrupts_c.obj: ../Sources/IntcInterrupts.c
	@echo 'Building file: $<'
	@echo 'Executing target #19 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/IntcInterrupts.args" -o "Sources/IntcInterrupts_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/ivor_branch_table_c.obj: ../Sources/ivor_branch_table.c
	@echo 'Building file: $<'
	@echo 'Executing target #20 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/ivor_branch_table.args" -o "Sources/ivor_branch_table_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 24
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := "$(GNU_Make_Install_DirEnv)/rm" -f

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include freeRTOS/Source/subdir.mk
-include freeRTOS/Source/portable/MemMang/subdir.mk
-include freeRTOS/Source/portable/CodeWarrior/PowerPC_MPC560xB/subdir.mk
-include freeRTOS/Demo/MPC5604b_CodeWarrior/src_hw/subdir.mk
-include freeRTOS/Demo/MPC5604b_CodeWarrior/subdir.mk
-include Sources/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
STATICLIB += \

STATICLIB_QUOTED += \

STATICLIB_OS_FORMAT += \

EXECUTABLES += \

EXECUTABLES_QUOTED += \

EXECUTABLES_OS_FORMAT += \


# All Target
all: warning-messages explicit-dependencies freeRTOS_MPC5604b_port.elf

# Tool invocations
freeRTOS_MPC5604b_port.elf: $(OBJS) $(USER_OBJS) ../Project_Settings/Linker_Files/MPC5604B_RAM.lcf
	@echo 'Building target: $@'
	@echo 'Executing target #25 $@'
	@echo 'Invoking: PowerPC Linker'
	"$(PAToolsDirEnv)/mwldeppc" -o "freeRTOS_MPC5604b_port.elf" @@"freeRTOS_MPC5604b_port.args"  $(USER_OBJS_QUOTED)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) "./*/*/*/*/*/*.d"  $(STATICLIB_QUOTED) "./*/*/*.obj" "./*/*.obj" "./*/*/*/*.obj" "./*/*/*/*/*.obj" "./*/*/*/*/*/*.obj"  $(CPP_DEPS_QUOTED) $(CC_DEPS_QUOTED) $(S_UPPER_DEPS_QUOTED) $(CXX_DEPS_QUOTED) $(ASM_DEPS_QUOTED) $(ASM_UPPER_DEPS_QUOTED) $(C_UPPER_DEPS_QUOTED) $(C++_DEPS_QUOTED) $(EXECUTABLES_QUOTED) "./*/*/*.d" "./*/*.d" "./*/*/*/*.d" "./*/*/*/*/*.d" "./*/*/*/*/*/*.d"  $(ProjDirPath)/RAM/freeRTOS_MPC5604b_port.elf
	-@echo ' '

.PHONY: all clean dependents explicit-dependencies warning-messages
.SECONDARY:

-include ../makefile.targets

explicit-dependencies: ../Project_Settings/Linker_Files/MPC5604B_RAM.lcf 

warning-messages: 


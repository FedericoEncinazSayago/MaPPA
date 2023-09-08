################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../kernel/main.c 

C_DEPS += \
./kernel/main.d 

OBJS += \
./kernel/main.o 


# Each subdirectory must supply rules for building sources it contributes
kernel/%.o: ../kernel/%.c kernel/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-kernel

clean-kernel:
	-$(RM) ./kernel/main.d ./kernel/main.o

.PHONY: clean-kernel


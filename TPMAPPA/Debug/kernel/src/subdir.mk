################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../kernel/src/iniciar_kernel.c 

C_DEPS += \
./kernel/src/iniciar_kernel.d 

OBJS += \
./kernel/src/iniciar_kernel.o 


# Each subdirectory must supply rules for building sources it contributes
kernel/src/%.o: ../kernel/src/%.c kernel/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-kernel-2f-src

clean-kernel-2f-src:
	-$(RM) ./kernel/src/iniciar_kernel.d ./kernel/src/iniciar_kernel.o

.PHONY: clean-kernel-2f-src


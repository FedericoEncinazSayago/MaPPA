################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../include/inicializar_fs.c 

C_DEPS += \
./include/inicializar_fs.d 

OBJS += \
./include/inicializar_fs.o 


# Each subdirectory must supply rules for building sources it contributes
include/%.o: ../include/%.c include/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-include

clean-include:
	-$(RM) ./include/inicializar_fs.d ./include/inicializar_fs.o

.PHONY: clean-include


################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/comunicacion.c \
../src/inicializar_m.c 

C_DEPS += \
./src/comunicacion.d \
./src/inicializar_m.d 

OBJS += \
./src/comunicacion.o \
./src/inicializar_m.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/comunicacion.d ./src/comunicacion.o ./src/inicializar_m.d ./src/inicializar_m.o

.PHONY: clean-src


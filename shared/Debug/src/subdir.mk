################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/cambioDeColor.c \
../src/protocolo.c \
../src/sockets.c \
../src/utils.c 

C_DEPS += \
./src/cambioDeColor.d \
./src/protocolo.d \
./src/sockets.d \
./src/utils.d 

OBJS += \
./src/cambioDeColor.o \
./src/protocolo.o \
./src/sockets.o \
./src/utils.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/cambioDeColor.d ./src/cambioDeColor.o ./src/protocolo.d ./src/protocolo.o ./src/sockets.d ./src/sockets.o ./src/utils.d ./src/utils.o

.PHONY: clean-src


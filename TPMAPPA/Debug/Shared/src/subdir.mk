################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Shared/src/cambioDeColor.c \
../Shared/src/protocolo.c \
../Shared/src/sockets.c \
../Shared/src/utils.c 

C_DEPS += \
./Shared/src/cambioDeColor.d \
./Shared/src/protocolo.d \
./Shared/src/sockets.d \
./Shared/src/utils.d 

OBJS += \
./Shared/src/cambioDeColor.o \
./Shared/src/protocolo.o \
./Shared/src/sockets.o \
./Shared/src/utils.o 


# Each subdirectory must supply rules for building sources it contributes
Shared/src/%.o: ../Shared/src/%.c Shared/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/utnso/Desktop/TPMAPPA/TPMAPPA/Shared/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Shared-2f-src

clean-Shared-2f-src:
	-$(RM) ./Shared/src/cambioDeColor.d ./Shared/src/cambioDeColor.o ./Shared/src/protocolo.d ./Shared/src/protocolo.o ./Shared/src/sockets.d ./Shared/src/sockets.o ./Shared/src/utils.d ./Shared/src/utils.o

.PHONY: clean-Shared-2f-src


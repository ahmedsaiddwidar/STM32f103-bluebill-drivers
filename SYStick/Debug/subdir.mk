################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SYStick.c 

OBJS += \
./SYStick.o 

C_DEPS += \
./SYStick.d 


# Each subdirectory must supply rules for building sources it contributes
SYStick.o: ../SYStick.c
	arm-none-eabi-gcc "$<" -std=gnu11 -g3 -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"SYStick.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"


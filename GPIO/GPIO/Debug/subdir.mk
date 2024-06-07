################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GPIO.c 

OBJS += \
./GPIO.o 

C_DEPS += \
./GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
GPIO.o: ../GPIO.c
	arm-none-eabi-gcc "$<" -std=gnu11 -g3 -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"GPIO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"


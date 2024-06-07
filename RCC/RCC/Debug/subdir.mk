################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RCC.c 

OBJS += \
./RCC.o 

C_DEPS += \
./RCC.d 


# Each subdirectory must supply rules for building sources it contributes
RCC.o: ../RCC.c
	arm-none-eabi-gcc "$<" -std=gnu11 -g3 -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"RCC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"


################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../srcGrafo/AdministradorDeCatalogoDeDestinos.cpp \
../srcGrafo/Viaje.cpp 

OBJS += \
./srcGrafo/AdministradorDeCatalogoDeDestinos.o \
./srcGrafo/Viaje.o 

CPP_DEPS += \
./srcGrafo/AdministradorDeCatalogoDeDestinos.d \
./srcGrafo/Viaje.d 


# Each subdirectory must supply rules for building sources it contributes
srcGrafo/%.o: ../srcGrafo/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



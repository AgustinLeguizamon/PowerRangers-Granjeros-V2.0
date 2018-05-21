################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../srcBMPTerreno/BMPTerreno.cpp \
../srcBMPTerreno/CatalogoSemillas.cpp \
../srcBMPTerreno/EasyBMP.cpp \
../srcBMPTerreno/Parcela.cpp \
../srcBMPTerreno/Terreno.cpp \
../srcBMPTerreno/usoTerrenosBMP.cpp 

OBJS += \
./srcBMPTerreno/BMPTerreno.o \
./srcBMPTerreno/CatalogoSemillas.o \
./srcBMPTerreno/EasyBMP.o \
./srcBMPTerreno/Parcela.o \
./srcBMPTerreno/Terreno.o \
./srcBMPTerreno/usoTerrenosBMP.o 

CPP_DEPS += \
./srcBMPTerreno/BMPTerreno.d \
./srcBMPTerreno/CatalogoSemillas.d \
./srcBMPTerreno/EasyBMP.d \
./srcBMPTerreno/Parcela.d \
./srcBMPTerreno/Terreno.d \
./srcBMPTerreno/usoTerrenosBMP.d 


# Each subdirectory must supply rules for building sources it contributes
srcBMPTerreno/%.o: ../srcBMPTerreno/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



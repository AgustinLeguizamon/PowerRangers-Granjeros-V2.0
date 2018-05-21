################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../srcBmpprueba/BMPTerreno.cpp \
../srcBmpprueba/CatalogoSemillas.cpp \
../srcBmpprueba/EasyBMP.cpp \
../srcBmpprueba/Parcela.cpp \
../srcBmpprueba/Terreno.cpp \
../srcBmpprueba/usoTerrenosBMP.cpp 

OBJS += \
./srcBmpprueba/BMPTerreno.o \
./srcBmpprueba/CatalogoSemillas.o \
./srcBmpprueba/EasyBMP.o \
./srcBmpprueba/Parcela.o \
./srcBmpprueba/Terreno.o \
./srcBmpprueba/usoTerrenosBMP.o 

CPP_DEPS += \
./srcBmpprueba/BMPTerreno.d \
./srcBmpprueba/CatalogoSemillas.d \
./srcBmpprueba/EasyBMP.d \
./srcBmpprueba/Parcela.d \
./srcBmpprueba/Terreno.d \
./srcBmpprueba/usoTerrenosBMP.d 


# Each subdirectory must supply rules for building sources it contributes
srcBmpprueba/%.o: ../srcBmpprueba/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



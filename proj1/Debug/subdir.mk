################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CollectionTester.cpp \
../Menu.cpp \
../Movie.cpp \
../MovieCollection.cpp \
../MovieTester.cpp \
../main.cpp 

OBJS += \
./CollectionTester.o \
./Menu.o \
./Movie.o \
./MovieCollection.o \
./MovieTester.o \
./main.o 

CPP_DEPS += \
./CollectionTester.d \
./Menu.d \
./Movie.d \
./MovieCollection.d \
./MovieTester.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



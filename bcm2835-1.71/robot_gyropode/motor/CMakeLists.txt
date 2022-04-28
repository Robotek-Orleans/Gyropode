cmake_minimum_required(VERSION 3.13)    # CMake version check
project(motorworking)                   # Create project "CMakeLists.txt  motor.cpp  motor.h  motorworking  motorworking.cpp"
set(CMAKE_CXX_STANDARD 14)              # Enable c++14 standard

# add the source files
# set(SOURCE_FILES motorworking.cpp motor.cpp)
#set(SOURCE_FILES motorworking.cpp)
set(SOURCE_FILES motor.cpp)

find_library(BCM2835_LIB bcm2835)
if(NOT BCM2835_LIB)
  message(FATAL_ERROR "bcm2835_lib library not found")
else()
  message(STATUS "bcm2835_lib library found")
endif()

# Add the directory to search for header files
include_directories(include)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(motorworking ${SOURCE_FILES})
target_link_libraries(motorworking ${BCM2835_LIB})
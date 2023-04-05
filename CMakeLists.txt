set(CMAKE_TOOLCHAIN_FILE arduino-cmake/cmake/ArduinoToolchain.cmake) # Arduino Toolchain


cmake_minimum_required(VERSION 2.8)
#====================================================================#
#  Setup Project                                                     #
#====================================================================#
project(RosaExecutable C CXX)

print_board_list()
print_programmer_list()

add_subdirectory(src)       
add_subdirectory(include)

target_sources(Rosa main.c)
set(CMAKE_TOOLCHAIN_FILE arduino-cmake/cmake/ArduinoToolchain.cmake) # Arduino Toolchain


cmake_minimum_required(VERSION 3.16)
#====================================================================#
#  Setup Project                                                     #
#====================================================================#
project(
    RosaExecutable 
    VERSION 1.0.0 
    LANGUAGES C)

set(LIB "Library")
set(EXE "RosaExecutable")

print_board_list()
print_programmer_list()

add_subdirectory(src)
add_subdirectory(app)

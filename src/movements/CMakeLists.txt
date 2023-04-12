
add_library(${LIB} STATIC movements.c)

generate_arduino_library(movements_lib
    SRCS movements.c
    HDRS movements.h
    BOARD uno)

target_include_directories(Library PUBLIC "./")
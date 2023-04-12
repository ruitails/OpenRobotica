#add_executable(RosaExecutable main.c)

generate_arduino_firmware(RosaExecutable
    SRCS main.c
    LIBS movements_lib
    BOARD uno)

#target_link_libraries(RosaExecutable PUBLIC ${LIB})
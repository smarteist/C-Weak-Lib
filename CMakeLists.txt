cmake_minimum_required(VERSION 3.20)
project(helloworld C)

set(CMAKE_C_STANDARD 99)


# Add the library target
add_library(weaklib SHARED weaklib.c)

# Add the executable target
add_executable(helloworld
        main.c
        )
# Link the library to the executable
target_link_libraries(helloworld weaklib)
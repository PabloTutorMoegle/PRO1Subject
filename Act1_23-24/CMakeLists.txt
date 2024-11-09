cmake_minimum_required(VERSION 3.27)
project(pro1a1)

set(CMAKE_CXX_STANDARD 17)

add_executable(pro1a1 program.cpp
        Vol.hpp Vol.cpp
        Reserva.hpp Reserva.cpp
        Passatger.hpp Passatger.cpp
        Aerolinia.hpp Aerolinia.cpp
)

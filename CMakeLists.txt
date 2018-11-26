cmake_minimum_required(VERSION 3.10)
project(MSLMv3)

set(MSLM_SOURCE
        Motor.h
        Motor.cpp
        sensor.h
        deftype.h
        sensor.cpp
        switch.h
        vector.cpp
        block.h
        block.cpp
        map3.h
        map3.cpp
        Point.cpp
        Point.h
        PositionEstimator.h
        PositionEstimator.cpp algorithm.h)

set(MSLM_SIM_SOURCE
        block.cpp
        map3.cpp
        Simulator.cpp
        sim_main.cpp
        map_mbed.cpp)

add_library(MSLM ${MSLM_SOURCE})

target_link_libraries(MSLM ${MBED_LIBS})

add_executable(SIM ${MSLM_SIM_SOURCE})
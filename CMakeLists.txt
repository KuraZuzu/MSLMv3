cmake_minimum_required(VERSION 3.10)
project(MSLMv3)

set(MSLMv3_SOURCE
        Motor.h
        Motor.cpp
        sensor.h
        deftype.h
        sensor.cpp
        switch.h
        block.h
        block.cpp
        map3.h
        map3.cpp
        Point.h
        position_estimator.h
        position_estimator.cpp
        SensorManager.h
        )

#set(MSLMv3_SIM_SOURCE
#        block.cpp
#        map3.cpp
#        Simulator.cpp
#        sim_main.cpp
#        map_mbed.cpp
#        )

set(CMAKE_CXX_STANDARD 11)

add_library(MSLMv3 ${MSLMv3_SOURCE})

target_link_libraries(MSLMv3 ${MBED_LIBS})

#add_executable(SIM ${MSLMv3_SIM_SOURCE})
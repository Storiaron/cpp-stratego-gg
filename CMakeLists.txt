cmake_minimum_required(VERSION 3.26)
project(cpp_stratego_gg)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_stratego_gg main.cpp
        IO_Handler.h
        IO_Handler.cpp
        Enums/PlayerColor.h
        Figures/Figure.h
        Figures/Figure.cpp
        Figures/Soldiers/Peasant.h
        Figures/Soldiers/Peasant.cpp
        Figures/Soldiers/King.h
        Figures/Soldiers/BabyDragon.h)

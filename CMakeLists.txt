cmake_minimum_required(VERSION 3.16)
project(WarGame_t)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cppEx4_warGame
        Board.cpp
        Board.hpp
        DemoGame.cpp
        DemoGame.hpp
        FootCommander.cpp
        FootCommander.hpp
        FootSoldier.cpp
        FootSoldier.hpp
        Paramedic.cpp
        Paramedic.hpp
        ParamedicCommander.cpp
        ParamedicCommander.hpp
        Sniper.cpp
        Sniper.hpp
        SniperCommander.cpp
        SniperCommander.hpp
        Soldier.cpp
        Soldier.hpp
        Test.cpp
        TestCounter.cpp)
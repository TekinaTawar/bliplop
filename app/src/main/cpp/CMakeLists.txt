cmake_minimum_required(VERSION 3.22.1)
project("bliplop")
add_library(
        bliplop

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        include/OboeSinePlayer.h
        DuplexEngine.cpp
        BlipLop.cpp
        CJavaBridge.cpp)

find_package(oboe REQUIRED CONFIG)

include_directories(include)

find_library(
        log-lib

        log)

target_link_libraries( # Specifies the target library.
        bliplop
        oboe::oboe
        ${log-lib})

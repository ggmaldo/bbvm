cmake_minimum_required(VERSION 3.10)
project(BBVM)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})


add_executable(BBVM src/main.cpp)


set(IRN_SOURCE ${CMAKE_SOURCE_DIR}/programs/program.irn)
set(IRN_DESTINATION ${CMAKE_BINARY_DIR}/program.irn)


if(EXISTS "${IRN_SOURCE}")
    configure_file(${IRN_SOURCE} ${IRN_DESTINATION} COPYONLY)
else()
    message(WARNING "⚠️ The file program.irn do not exist.")
endif()

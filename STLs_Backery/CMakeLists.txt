cmake_minimum_required(VERSION 3.0)

project(Vector_Project) # change project name

set(CMAKE_CXX_STANDARD 17)

include_directories(includes/ utils/)

set(SOURCE

    src/main.cpp
    #utils/math.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE})
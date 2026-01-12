cmake_minimum_required(VERSION 3.16)
project(Engine)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include(FetchContent)


FetchContent_Declare(
    sfml
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.5.1
)

FetchContent_MakeAvailable(sfml)


add_executable(Engine src/main.cpp)


target_link_libraries(Engine PRIVATE sfml-graphics sfml-window sfml-system)

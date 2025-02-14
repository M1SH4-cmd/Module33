cmake_minimum_required(VERSION 3.25)
project(Note5 VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)

set(Boost_INCLUDE_DIR "C:\\boost_1_87_0")
set(Boost_LIBRARY_DIR "C:\\boost_1_87_0\\stage\\lib")

find_package(Boost COMPONENTS REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

add_executable(Note5 main.cpp)
target_link_libraries(Note5 ${Boost_LIBRARIES})

if(MINGW)
    target_link_libraries(Note5 ws2_32)
endif()

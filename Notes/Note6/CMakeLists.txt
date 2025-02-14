cmake_minimum_required(VERSION 3.25)
project(Note6 VERSION 1.5)

set(CMAKE_CXX_STANDARD 20)

set(Boost_INCLUDE_DIR "C:\\boost_1_85_0")
set(Boost_LIBRARY_DIR "C:\\boost_1_85_0\\stage\\lib")

find_package(Boost COMPONENTS REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

add_executable(Note6 main.cpp)
target_link_libraries(Note6 ${Boost_LIBRARIES})

if(MINGW)
    target_link_libraries(Note6 ws2_32)
endif()

cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 17)

set(GOOGLETEST_VERSION 1.15.2)

add_subdirectory(googletest/)

set(gtest_DIR googletest)
include_directories(${gtest_DIR}/include)

set(SOURCES_TESTS mainTest.cpp Movements.cpp Collision.cpp)

add_executable(test ${SOURCES_TESTS})

target_link_libraries(test gtest gtest_main gmock Game_Tests sfml-system sfml-window sfml-graphics)
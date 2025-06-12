# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(Images LANGUAGES CXX)

if(CMAKE_SYSTEM_NAME STREQUAL "Emscripten")
    add_link_options(
        "--preload-file=../examples/images/assets@assets"
    )
endif()

set(SOURCES
    src/main.cxx
    src/app.cxx
    src/app.hpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC Bismuth)
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

if(CMAKE_SYSTEM_NAME STREQUAL "Emscripten")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        SUFFIX ".html"
        LINK_FLAGS "-sEXIT_RUNTIME=1"
    )
endif()
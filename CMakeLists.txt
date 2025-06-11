# CMakeLists.txt
cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
project(Bismuth LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(utils)

if(CMAKE_SYSTEM_NAME STREQUAL "Emscripten")
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
    
    # im too lazy to optimize this thing
    add_compile_options(
        "-O2"
    )

    add_link_options(
        "-sWASM=1"
        "-sALLOW_MEMORY_GROWTH=1"
        "-sUSE_WEBGL2=1"
        "-sFULL_ES3=1"
    )
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

option(BUILD_EXAMPLES "Build examples" ON)
option(USE_SDL "Enable SDL interface" ON)

file(GLOB_RECURSE SOURCE_FILES "src/*.cxx")
file(GLOB_RECURSE HEADER_FILES "include/bismuth/*.hpp")

# uhh
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

foreach(FILE_PATH ${SOURCE_FILES})
    get_vs_group_name("${FILE_PATH}" GROUP_NAME)
    if(GROUP_NAME STREQUAL "")
        source_group("Source Files" FILES "${FILE_PATH}")
    else()
        source_group("Source Files/${GROUP_NAME}" FILES "${FILE_PATH}")
    endif()
endforeach()

foreach(FILE_PATH ${HEADER_FILES})
    get_vs_group_name("${FILE_PATH}" GROUP_NAME)
    if(GROUP_NAME STREQUAL "")
        source_group("Header Files" FILES "${FILE_PATH}")
    else()
        source_group("Header Files/${GROUP_NAME}" FILES "${FILE_PATH}")
    endif()
endforeach()

# submodules
add_subdirectory(external/SDL EXCLUDE_FROM_ALL)

# hacky hack
set(CMAKE_INSTALL_PREFIX "./out" CACHE BOOL "" FORCE)

if(BUILD_EXAMPLES)
    add_subdirectory(examples/barebones)
    add_subdirectory(examples/move_square)

    # installing
    install(TARGETS BareBones RUNTIME DESTINATION examples)
    install(TARGETS MovingSquare RUNTIME DESTINATION examples)
    install(FILES $<TARGET_FILE:SDL3::SDL3> DESTINATION examples)
endif()

add_library(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES} )
target_link_libraries(${PROJECT_NAME} PUBLIC
    SDL3::SDL3
)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION .) # install the library
target_compile_definitions(${PROJECT_NAME} PRIVATE _USE_SDL)
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/bismuth
    ${CMAKE_CURRENT_SOURCE_DIR}/external/SDL/include
)

if(USE_SDL)
    target_compile_definitions(${PROJECT_NAME} PRIVATE _USE_SDL)
else()
    message(FATAL_ERROR "Atleast one interface is required. Either implement your own, or enable one.")
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Emscripten")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        SUFFIX ".a" # static library suffix for Emscripten
    )
endif()
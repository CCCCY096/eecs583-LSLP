cmake_minimum_required(VERSION 3.4.3)

if(APPLE)
    if(NOT DEFINED ENV{LLVM_HOME})
        message(FATAL_ERROR "$LLVM_HOME is not defined")
    else ()
        set(ENV{LLVM_DIR} $ENV{LLVM_HOME}/lib/cmake/llvm)
    endif()
endif(APPLE)

find_package(LLVM 8.0.1 EXACT CONFIG)                        # This will find the shared LLVM build.

list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")        # You don't need to change ${LLVM_CMAKE_DIR} since it is already defined.
include(AddLLVM)
add_definitions(${LLVM_DEFINITIONS})                      # You don't need to change ${LLVM_DEFINITIONS} since it is already defined.
include_directories(${LLVM_INCLUDE_DIRS})                 # You don't need to change ${LLVM_INCLUDE_DIRS} since it is already defined.
link_directories(${LLVM_LIBRARY_DIRS})

add_subdirectory(LSLP)                                     # Add the directory which your pass lives.

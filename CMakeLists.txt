cmake_minimum_required(VERSION 3.31.0)

if (NOT DEFINED CMAKE_C_COMPILER)
  find_program(CMAKE_C_COMPILER NAMES clang)
endif()
if (NOT DEFINED CMAKE_CXX_COMPILER)
  find_program(CMAKE_CXX_COMPILER NAMES clang++)
endif()

project(Pasture C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 23)

set(PASTURE_LLVM_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/third_party/llvm-project")
set(PASTURE_LLVM_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/llvm-project")

set(LLVM_ENABLE_PROJECTS mlir CACHE STRING "")
set(LLVM_TARGETS_TO_BUILD AArch64 SPIRV CACHE STRING "")

set(LLVM_INCLUDE_BENCHMARKS OFF CACHE BOOL "")
set(LLVM_INCLUDE_EXAMPLES OFF CACHE BOOL "")
set(LLVM_INCLUDE_TESTS OFF CACHE BOOL "")

add_subdirectory("${PASTURE_LLVM_SOURCE_DIR}/llvm" "llvm-project" EXCLUDE_FROM_ALL)

include_directories("${PASTURE_LLVM_SOURCE_DIR}/llvm/include")
include_directories("${PASTURE_LLVM_BINARY_DIR}/include")

include_directories("${PASTURE_LLVM_SOURCE_DIR}/mlir/include")
include_directories("${PASTURE_LLVM_BINARY_DIR}/tools/mlir/include")

add_llvm_executable(test test.cpp)

target_link_libraries(test PRIVATE LLVMSupport)

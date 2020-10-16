cmake_minimum_required(VERSION 3.16)
project(SimpleDemoToUseJIT)

find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_INCLUDE_DIRS}")

message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")


include_directories(${LLVM_INCLUDE_DIRS})
add_executable(SimpleDemoToUseJIT main.cpp)

# Link against LLVM libraries
target_link_libraries(SimpleDemoToUseJIT LLVM)

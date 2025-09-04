cmake_minimum_required(VERSION 3.18)

add_subdirectory(tools)

set(LLVM_MOS_PLATFORM rp6502)
find_package(llvm-mos-sdk REQUIRED)

project(MY-RP6502-PROJECT C CXX ASM)

add_executable(hello)
rp6502_executable(hello
    DATA file
    RESET file
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.hlp
)
target_sources(hello PRIVATE
    src/main.c
)

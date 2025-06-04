cmake_minimum_required(VERSION 3.16)
project(NavCore)

set(CMAKE_CXX_STANDARD 17)

# 脚本路径的定义
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/scripts")

# 根据不同配置设置输出目录
foreach(OUTPUTCONFIG Debug Release RelWithDebInfo MinSizeRel)
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG_UPPER)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${CMAKE_BINARY_DIR}/bin/${OUTPUTCONFIG})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${CMAKE_BINARY_DIR}/bin/${OUTPUTCONFIG})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${CMAKE_BINARY_DIR}/bin/${OUTPUTCONFIG})
endforeach()

# 添加子模块
add_subdirectory(BaseMath)
add_subdirectory(DataDecode)

# 引入格式化脚本
include(${CMAKE_MODULE_PATH}/clang-format.cmake)

# 主程序
add_executable(NavCoreApp Main/main.cpp)
target_link_libraries(NavCoreApp PRIVATE BaseMath)


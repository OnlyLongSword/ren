# 动态库
add_library(BaseMath SHARED
TestBaseMath.cpp
TestBaseMath.h
)

include(GenerateExportHeader)
# 生成导出头文件
generate_export_header(BaseMath
    EXPORT_FILE_NAME ${CMAKE_CURRENT_BINARY_DIR}/BaseMathExport.h
)

# 包含生成的导出头文件目录
target_include_directories(BaseMath PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

message(STATUS "✅ BaseMath library added!")
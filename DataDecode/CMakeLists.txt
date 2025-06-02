# 动态库
add_library(DataDecode SHARED
    IObsDecoder.h 
    DecodeContext.h 
    NovDecodeContext.h 
    NovOem7Decoder.h 
    DecodeManager.h 
    SatelliteDataBase.h 
    SatelliteEphrec.h 
    SatelliteObs.h 
    SatelliteDataManager.h 
    DataIterator.h
    IObsDecoder.cpp 
    DecodeContext.cpp 
    NovDecodeContext.cpp 
    NovOem7Decoder.cpp 
    DecodeManager.cpp 
    SatelliteDataBase.cpp 
    SatelliteEphrec.cpp
    SatelliteObs.cpp 
    SatelliteDataManager.cpp 
    DataIterator.cpp
)

include(GenerateExportHeader)
# 生成导出头文件
generate_export_header(DataDecode
    EXPORT_FILE_NAME ${CMAKE_CURRENT_BINARY_DIR}/DataDecodeExport.h
)

# 包含生成的导出头文件目录
target_include_directories(DataDecode PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

message(STATUS "✅ DataDecode library added!")
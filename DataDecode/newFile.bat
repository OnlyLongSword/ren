@echo off
setlocal enabledelayedexpansion

:: 设置类名列表（按空格分隔）
set CLASSNAMES=IObsDecoder DecodeContext NovDecodeContext NovOem7Decoder DecodeManager SatelliteDataBase Ephrec Obs SatelliteDataManager DataIterator

for %%C in (%CLASSNAMES%) do (
    set "CLASSNAME=%%C"
    set "HEADER=%%C.h"
    set "SOURCE=%%C.cpp"

    :: 创建头文件
    if not exist "!HEADER!" (
        echo > "!HEADER!"
    )

    :: 创建源文件
    if not exist "!SOURCE!" (
        echo > "!SOURCE!"
    )
)

echo All class files generated.
pause

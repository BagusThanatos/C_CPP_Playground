@echo off

IF NOT EXIST build\windows mkdir build\windows
pushd build\windows
REM All these libraries used should be changed accordingly
cl -I ..\..\include\ -Zi ..\..\src\main.cpp /EHsc /link /incremental:no Gdi32.lib opengl32.lib user32.lib
popd
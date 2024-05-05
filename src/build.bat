@echo off
mkdir ..\build
pushd ..\build
cl gdi32.lib kernel32.lib msvcrt.lib opengl32.lib raylib.lib shell32.lib user32.lib winmm.lib /std:c++17 ..\src\StarField.cpp  -Ic:\raylib\raylib\out\build\x64-Debug\raylib\include /link /libpath:c:\raylib\raylib\out\build\x64-Debug\raylib\ 
popd

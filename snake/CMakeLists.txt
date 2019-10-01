# CMakeList.txt: SFML 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)
aux_source_directory(. DIRECTORY)
# 将源代码添加到此项目的可执行文件。
add_executable (shadertest ${DIRECTORY})
target_link_libraries(shadertest sfml-system-d sfml-window-d sfml-graphics-d sfml-network-d sfml-audio-d)
# TODO: 如有需要，请添加测试并安装目标。

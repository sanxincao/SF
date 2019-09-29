# Title

游戏程序设计
## Install
点击 clone and download
## Usage

打开项目选择Cmake
新建项目时在主cmakelist末尾加

```
add_subdirectory ("SFML")

```

新建项目文件夹 在子cmakelist 中
target_link_libraries(项目名 sfml-system sfml-window sfml-graphics sfml-network sfml-audio 加上所使用的库)

别问问什么不能自动生成

求求你别问啦！
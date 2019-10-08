# Title

游戏程序设计
## Install
点击 clone and download
我记不清了,点击open in visual 是否支持2017
但这个项目需要在installer 的c++ 中安装 cmake 工作负载
## Usage
已经有vs 可以直接点击sln解集了
SFML\out\build\x64-Debug

可执行文件在out/build/x/64/bin中
已不再需要copy dll至此
sfml默认的加载路径也是在exe同级，所有的素材也要放在这里

打开项目选择Cmake
新建项目时在主cmakelist末尾加

```
add_subdirectory ("SFML")

```

新建项目文件夹 在子cmakelist 中
```
target_link_libraries(项目名 sfml-system sfml-window sfml-graphics sfml-network sfml-audio 加上所使用的库)
```
别问问什么不能自动生成

求求你别问啦！
# Title

��Ϸ�������
## Install
��� clone and download
�Ҽǲ�����,���open in visual �Ƿ�֧��2017
�������Ŀ��Ҫ��installer ��c++ �а�װ cmake ��������
## Usage
�Ѿ���vs ����ֱ�ӵ��sln�⼯��
SFML\out\build\x64-Debug

��ִ���ļ���out/build/x/64/bin��
�Ѳ�����Ҫcopy dll����
sfmlĬ�ϵļ���·��Ҳ����exeͬ�������е��ز�ҲҪ��������

����Ŀѡ��Cmake
�½���Ŀʱ����cmakelistĩβ��

```
add_subdirectory ("SFML")

```

�½���Ŀ�ļ��� ����cmakelist ��
```
target_link_libraries(��Ŀ�� sfml-system sfml-window sfml-graphics sfml-network sfml-audio ������ʹ�õĿ�)
```
������ʲô�����Զ�����

�������������
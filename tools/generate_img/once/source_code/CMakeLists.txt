cmake_minimum_required(VERSION 3.10)
project(combine_file)

#set(CMAKE_C_COMPILER "D:/Program Files/CodeBlocks/MinGW/bin/gcc.exe")
#set(CMAKE_CXX_COMPILER "D:/Program Files/CodeBlocks/MinGW/bin/g++.exe")

# 指定源文件
set(SOURCES ./main.c)
  
# 添加可执行文件
add_executable(combine_file ${SOURCES})

#在windows上的生成步骤
#系统环境变量Path中添加D:\Program Files\CodeBlocks\MinGW\bin 
#cmake .. -G "MinGW Makefiles" -DCMAKE_C_COMPILER="D:/Program Files/CodeBlocks/MinGW/bin/gcc.exe"
#cmake .. -G "MinGW Makefiles"

#mingw32-make

#把生成的combine_file.exe复制到..\resource_manage\tools\generate_img\once
#python build_image.py build-img --path inputfiles
#esptool.py -p COM6 -b 921600 write_flash -z 0x910000 .\main\resource_manage\tools\generate_img\once\inputfiles\fat_product.img
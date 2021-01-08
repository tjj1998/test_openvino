cmake_minimum_required( VERSION 2.8 )
project( test_openvino )

# 添加c++ 11标准支持
set( CMAKE_CXX_FLAGS "-std=c++17 -O3" )
# 寻找OpenCV库
find_package( OpenCV REQUIRED )

# 添加头文件
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( test_openvino test_openvino.cpp )
# 链接OpenCV库
target_link_libraries( test_openvino  ${OpenCV_LIBS} )

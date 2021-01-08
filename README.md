# test_openvino
a naive C++ project for testing openvino and opencv

## requirements
1. openvino 
   [download page](https://software.intel.com/content/www/us/en/develop/tools/openvino-toolkit/choose-download/linux.html)

## install
```
mkdir build
cd build
cmake ..
make
```
## usage
please change the IR model path in test_openvino.cpp to your path
```
cd build
./test_openvino test.png
```
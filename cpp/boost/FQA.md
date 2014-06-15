C++ Bost FQA
============

## Why boost source code files' extension is .hpp

".hpp" means ".h+.cpp", extension like this for following 3 reasons:

1. 与普通的C头文件".c"区分。
2. 使Boost库不需要预先编译，直接引入程序员的工程即可编译链接，方便了库的使用。
3. 编译器的限制.许多编译器尚不支持C++标准提出的模板的分离编译模式(export 
		关键字），而boost库大量使用了模板，为了保持与各个编译器的兼容，不得不
		采用这种.hpp的头文件形式。

## 

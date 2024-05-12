/*
在C++语言中，我们可以通过sizeof查询数据 长度，
但C++语言却没有对对齐方式有关的查询或 者设定进行标准化，而语言本身又允许自定义类 型、模板等诸多特性。
编译器无法完全找到正确的 对齐方式，这会在使用时造成困难。
*/
#include<iostream>
 using namespace std; 
 //自定义的ColorVector，拥有32字节的数据 
 struct ColorVector
 { 
    double r; 
    double g; 
    double b; 
    double a; 
};

int main()
{
    //使用C++11中的alignof来查询ColorVector的对齐方式
    cout<<"alignof(ColorVector):"<<alignof(ColorVector)<<endl;
    
    return 0;
}




/*
使用了 C++11标准定义的alignof函数来查看数据的对齐 方式。
编译运行代码，我们可以看到 ColorVector在实验机上依然是对齐到8字节的地址 边界上。
*/
/*
我们利用 C++11新提供的修饰符alignas来重新设定 
ColorVector的对齐方式
*/

#include<iostream>
 using namespace std; 
 //自定义的ColorVector，拥有32字节的数据 
 struct alignas(32) ColorVector
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
指定数据 ColorVector对齐到32字节的地址边界上，
只需要 声明alignas(32)即可。
*/
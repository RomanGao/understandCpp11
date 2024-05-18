/*
C++11对于对齐的支持并不限于alignof操作符 及alignas描述符。
在STL库中，还内建了std::align 函数来动态地根据指定的对齐方式调整数据块的位 置。
该函数的原型如下：
void*align(std::size_t alignment,std::size_t size,void*＆ptr,std::size_t＆space);

该函数在ptr指向的大小为space的内存中进行 对齐方式的调整，将ptr开始的size大小的数据调整 为按alignment对齐。
*/

#include <iostream>
#include <cstdlib>
#include<memory>
using namespace std;

struct ColorVector
{
    double r;
    double g;
    double b;
    double a;
};

int main()
{
    size_t const size =100;
    ColorVector *const vec = new ColorVector[size];
    void *p = vec;
    size_t sz = size;
    void *aligned = align(alignof(double)*4, size, p, sz);

    if(aligned != nullptr)
    {
        cout<<alignof(p)<<endl;
    }
    return 0;
}

/*
试将vec中的内容按 alignof(double)*4的对齐值进行对齐
*/

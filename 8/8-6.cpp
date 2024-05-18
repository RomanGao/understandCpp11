/*
们采用了 模板的方式来实现一个固定容量但是大小随着所用 的数据类型变化的容器类型
*/

#include <iostream>
using namespace std;    

struct alignas(alignof(double)*4) ColorVector
{
    double r, g, b;
    double a; // alpha channel
};
template<typename T>
class FixedCapacityArray
{
public:
    void push_back(T t){}
    alignas(T) char data[1024]={0};
    //int length =1204;
};

int main()
{
    FixedCapacityArray<char> arrCh;
    cout<<"alignof(char) :"<<alignof(char)<<endl;
    cout<<"alignof(arrch.data)"<<alignof(arrCh.data)<<endl;
    FixedCapacityArray<ColorVector> arrCV;
    cout<<"alignof(ColorVector) :"<<alignof(ColorVector)<<endl;
    cout<<"alignof(arrCV.data)"<<alignof(arrCV.data)<<endl;
    return 0;
}

/*
如我们之前提到的一样，为了有效地访问数 据，必须使得数据按照其固有特性进行对齐。对于 arrCh，由于数组中的元素都是char类型，所以对 齐到1就行了，
而对于我们定义的arrCV，必须使其 符合ColorVector的扩展对齐，即对齐到8字节的内 存边界上。

  alignas(T) char data[1024]={0};
该句指示data[1024]这个char类型数组必须按 照模板参数T的对齐方式进行对齐。
*/
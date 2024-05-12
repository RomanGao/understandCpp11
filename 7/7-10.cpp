/*
在C++11中，标准则给出了更为简单的方法， 即在函数的定义或者声明加 上“=delete”。
“=delete”会指示编译器不生成 函数的缺省版本
*/

#include <iostream>
#include<type_traits>
using namespace std;

class NoCopyCstor
{
public:
    NoCopyCstor()=default;
private:
    //将拷贝构造函数声明为private成员并不提供实现 
    //可以有效阻止用户错用拷贝构造函数
    NoCopyCstor(const NoCopyCstor&)=delete;
};

int main()
{
    NoCopyCstor a;
    //NoCopyCstor b(a); //编译器会报错，拷贝构造函数被禁止使用
}

/*
一个使用“=delete”删除 拷贝构造函数的缺省版本的实例。

值得注意的是， 一旦缺省版本被删除了，重载该函数也是非法的。
*/
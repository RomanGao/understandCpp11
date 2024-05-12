/*
而在C++11中，标准是通过提供了新的机制来控制默认版本函数的生成来完成这个目标的。
这个新机制重用了default关键字。程序员可以在默认函数定义或者声明时加上“=default”，从而显式地指示编译器生成该函数的默认版本。
而如果指定产生默认版本后，程序员不再也不应该实现一份同名的函数。
*/

#include <iostream>
#include<type_traits>
using namespace std;

class TwoCstor
{
public:
    //提供了带参数版本的构造函数，再指示编译器
    //提供默认版本，则本自定义类型依然是POD类型
    TwoCstor()=default;
    TwoCstor(int i):data(i){}
private:
    int data;
};

int main()
{
    cout<<is_pod<TwoCstor>::value<<endl;
}

/*
会得到结果1。 TwoCstor还是一个POD的类型.

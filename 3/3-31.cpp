//同样的，函数的参数列表也可以使用初始化列表

#include <iostream>
#include<initializer_list>
using namespace std;

void Fun(initializer_list<int> il){}

int main()
{
    Fun({1,2,3});
    Fun({});
    return 0;
}

//同理，类和结构体的成员函数 也可以使用初始化列表，包括一些操作符的重载函数。

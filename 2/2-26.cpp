#include<iostream>
using namespace std;

template <typename T> void TempFun(T a)
{
    cout<<a<<endl;
}

#if 0
int main()
{
    TempFun(11); ////11,(实例化为TempFun＜const int＞(11))
    TempFun("1"); ////1,(实例化为TempFun＜const char*＞ ("1"))
    return 0;
}
#endif
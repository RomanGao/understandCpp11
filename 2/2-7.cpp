#include<cassert>
#include<iostream>
using namespace std;

//枚举编译器对各种特性的支持,每个枚举值占一位
enum FeatureSupports
{
    C99=0x0001,
    ExtInt=0x0002,
    SAssert=0x0004,
    NoExcept=0x0008,
    SMAX=0x0010,
};

struct Compiler
{
    const char* name;
    int spp; //使用FeatureSupports枚举
};

/*
int main()
{
    assert((SMAX -1) == (C99|ExtInt|SAssert|NoExcept));

    Compiler a={"abc",(C99|SAssert)};

    if(a.spp& C99)
    {
        cout<<"hello"<<endl;
    }

    return 0;
}
*/


//assert是一个运行时的断言，这意味着不运行程序我们将无法得知是否有枚举重位。
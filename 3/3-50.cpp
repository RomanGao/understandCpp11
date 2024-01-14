#include<iostream>
using namespace std;

namespace Jim
{
    #if __cplusplus ==201103L
    inline
    #endif
    namespace cpp11
    {
        struct Knife
        {
            Knife()
            {
                cout<<"Knife in c++11"<<endl;
            }
        };
    }

    #if __cplusplus <201103L
    inline
    #endif
    namespace oldcpp
    {
        struct Knife
        {
            Knife()
            {
                cout<<"Knife in old c++"<<endl;
            }
        };
    }
} // namespace Jim

using namespace Jim;
int main()
{
    Knife a;//Knife in c++11.(默认版本) //这也是++11中为什么要引入新的内联名字空间的一个 根本原因。

    cpp11::Knife b;//Knife in c++11.(强制使用cpp11 版本)
    oldcpp::Knife c;//Knife in old c++.(强制使用 oldcpp11版本)

}

/*
如果现在的宏__cplusplus等于201103这个常数，那么就将名字空间cpp11内联 到Jim中，
而如果小于201103，则将名字空间 oldcpp内联到Jim中。
而如果需要的话，我们依然可以通过名字空 间的方式（如cpp11::Knife）来访问相应名字空间 中的类型、数据、函数等。

事实上，在C++标准程序库中，开发者已经开 始这么做了。

但是程序员不应该在需要隔离名字的时候 使用inline namespace关键字。
*/


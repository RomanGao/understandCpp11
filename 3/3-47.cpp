/*
在C++中，引入了名字空间（namespace）这 样一个概念。
名字空间的目的是分割全局共享的名 字空间。
程序员在编写程序时可以建立自己的名字 空间，
而使用者则可以通过双冒号“空间名::函数/变量名”的形式来引用自己需要的版本。
这就解决 了C中名字冲突的问题。
*/
#include <iostream>
using namespace std;

namespace  Jim
{
    namespace  Basic
    {
        struct Knife
        {
            Knife()
            {
                cout<<"Knife in Basic."<<endl;
            }
        }; 
        class CorkScrew{};
    }// namespace Basic

    namespace Toolkit
    {
        template<typename T>
        class SwissArmyKnife{}; 
    } // namespace Toolkit

    namespace Other
    { 
        //Knife b;//无法通过编译
        struct Knife
        {
            Knife()
            {
                cout<<"Knife in Other"<<endl;
            }
        }; 
        Knife c;//Knife in Other 
        Basic::Knife k;//Knife in Basic
    }
}

using namespace Jim;
int main()
{
    Toolkit::SwissArmyKnife<Basic::Knife>sknife;
}


/*
不过Jim这样会带来一个问题，即库的使用者在 使用Jim名字空间的时候，需要知道太多的子名字空间的名字。
使用者显然不希望声明一个sknife变量时，
需要Toolkit::SwissArmyKnife＜ Basic::Knife＞这么长的类型声明。
*/

/*
在C++11中，标准引入了一个新特性，叫 做“内联的名字空间”。
通过关键字“inline namespace”就可以声明一个内联的名字空间。
内联的名字空间允许程序员在父名字空间定义或特化 子名字空间的模板。
*/
#include <iostream>
using namespace std;

namespace Jim
{
    inline namespace Basic
    {
        struct Knife
        {
            Knife()
            {
                cout<<"Knife in Basic"<<endl;
            }
        };
        class CorkScrew {};
    }

    inline namespace Toolkit
    {
        template <typename T>
        class SwissArmyKnife {};
    }

    namespace Other
    {
        Knife b;//Knife in Basic 
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

    //打开一些内部名字空间
    using namespace Basic;
    using namespace Toolkit;
}

namespace Jim
{ 
    template<>
    class SwissArmyKnife<Knife>{};//c++11 编译成功
}

using namespace Jim;
int main()
{
    SwissArmyKnife<Knife> s;    
    return 0;
}


/*
，我们将名字空间Basic和 Toolkit都声明为inline的。
此时，LiLei对库中模板 的偏特化（SwissArmyKnife＜Knife＞）则可以通 过编译。
*/

/*
不过这里我们需要再次注意一下Other这 个名字空间中的状况。
可以看到，变量b的声明语 句是可以通过编译的，而且其被声明为一个 Basic::Knife的类型。
如果换个角度理解的话，在子 名字空间Basic中的名字现在看起来就跟在父名字 空间中一样。
事实上，这跟inline namespace的使用方式有关。
*/
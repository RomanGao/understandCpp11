/*
而从库的提供者 Jim的角度看，通常也没必要让使用者看到子名字空间，
因此他可能考虑这样修改代码
*/
#include <iostream>
using namespace std;

namespace Jim
{
    namespace Basic
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

    namespace Toolkit
    {
        template <typename T>
        class SwissArmyKnife {};
    }

    namespace Other
    {

    }

    //打开一些内部名字空间
    using namespace Basic;
    using namespace Toolkit;
}

//namespace Jim
//{ 
    //template<>
    //class SwissArmyKnife<Knife>{};//c++98 编译失败 
//}

using namespace Jim;
int main()
{
    SwissArmyKnife<Knife> s;    
    return 0;
}

/*
Jim在名字空间
Jim的最后部分，打开了（using）Basic和Toolkit 两个名字空间（我们省略了关于Other名字空间中 的部分）。
这样一来在代码清单3-47中遇到的名字 过长的问题就不复存在了。
*/

/*
不过这里又有了新的问 题：
库的使用者由于觉得Toolkit中的模板 SwissArmyKnife有的时候不太合用，
所以决定特 化一个SwissArmyKnife＜Knife＞的版本.

这是由于C++98 标准不允许在不同的名字空间中对模板进行特化造 成的
*/
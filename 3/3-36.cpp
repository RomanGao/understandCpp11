/*
在C++11中，我们可以使用模板类来帮 助判断类型是否是一个标准布局的类型。
template ＜typename T＞ 
struct std::is_standard_layout;

通过is_standard_layout模板类的成员 value（is_standard_layout＜T＞::value），
我们 可以在代码中打印出类型的标准布局属性。
*/

#include <iostream>
#include <type_traits>
using namespace std;

struct SLayout1{};
struct SLayout2
{
private:
    int a;
    int b;
};

struct SLayout3: public SLayout1
{
    int x;
    int y;
    void f();
};
struct SLayout4: public SLayout1
{
    int x;
    SLayout1 y;
};

struct SLayout5:SLayout1,SLayout3{};
struct SLayout6{static int y;};
struct SLayout7:SLayout6{int x;};

struct NonSLayout1:SLayout1{ SLayout1 x; int i; };
struct NonSLayout2:SLayout2{int z;};
struct NonSLayout3:NonSLayout2{};

struct NonSLayout4
{ 
public: 
    int x; 
private: 
    int y;
};

int main()
{
    cout<<is_standard_layout<SLayout1>::value<<endl;
    cout<<is_standard_layout<SLayout2>::value<<endl;
    cout<<is_standard_layout<SLayout3>::value<<endl;
    cout<<is_standard_layout<SLayout4>::value<<endl;
    cout<<is_standard_layout<SLayout5>::value<<endl;
    cout<<is_standard_layout<SLayout6>::value<<endl;
    cout<<is_standard_layout<SLayout7>::value<<endl;
    cout<<is_standard_layout<NonSLayout1>::value<<endl;
    cout<<is_standard_layout<NonSLayout2>::value<<endl;
    cout<<is_standard_layout<NonSLayout3>::value<<endl;
    cout<<is_standard_layout<NonSLayout4>::value<<endl;
    return 0;
}
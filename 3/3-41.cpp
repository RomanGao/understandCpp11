//而在C++11中，为了减少这样的疑问，标准会 默认删除一些非受限联合体的默认函数。
//比如，非 受限联合体有一个非POD的成员，而该非POD成员类型拥有有非平凡的构造函数，
//那么非受限联合 体成员的默认构造函数将被编译器删除。
//其他的特 殊成员函数，例如默认拷贝构造函数、拷贝赋值操 作符以及析构函数等，也将遵从此规则。

#include<string>
using namespace std;

union T
{
    string s;////string有非平凡的构造函数
    int i;
};

int main()
{ 
    //T t;//构造失败，因为T的构造函数被删除了
}

//联合体T拥有一个非POD的成员s。
//而string有非平凡的构造函数，因此T的 构造函数被删除，其类型的变量t也就无法声明成 功。
//解决这个问题的办法是，由程序员自己为非受 限联合体定义构造函数。
//通常情况下，placement new会发挥很好的作用.

#include<string>
using namespace std;
union T
{
    string s;
    int i;
public:
    T(){new (&s) string();}
    ~T(){s.~string();}
};

int main()
{
    T t;////构造析构成功
}
//构造时，采用placement new将s构 造在其地址＆s上。
//这里placement new的唯一作 用只是调用了一下string的构造函数。
//而在析构 时，又调用了string的析构函数。
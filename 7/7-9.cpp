/*
另一方面，程序员在一些情况下则希望能够限 制一些默认函数的生成。
最典型地，类的编写者有 时需要禁止使用者使用拷贝构造函数，
在C++98 标准中，我们的做法是将拷贝构造函数声明为 private的成员，并且不提供函数实现。
这样一来，一旦有人试图（或者无意识）使用拷贝构造函数， 编译器就会报错。
*/


#include <iostream>
#include<type_traits>
using namespace std;

class NoCopyCstor
{
public:
    NoCopyCstor()=default;
private:
    //将拷贝构造函数声明为private成员并不提供实现 
    //可以有效阻止用户错用拷贝构造函数
    NoCopyCstor(const NoCopyCstor&);
};

int main()
{
    NoCopyCstor a;
    //NoCopyCstor b(a); //编译器会报错，拷贝构造函数被禁止使用
}

/*
，NoCopyCstor b(a)试图调用private的拷贝构造函数，该句编译不会通过。
不过 这样的做法也会对友元类或函数使用造成麻烦。
友 元类很可能需要拷贝构造函数，而简单声明private 的拷贝构造函数不实现的话，会导致编译的失败。
为了避免这种情况，我们还必须提供拷贝构造函数 的实现版本，并将其声明为private成员，才能达到 需要的效果

*/

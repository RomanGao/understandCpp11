/*
C++11标准称“=default”修饰的函数为显式缺省（explicit defaulted）函数，
而 称“=delete”修饰的函数为删除（deleted）函 数。
为了方便称呼，本书将删除函数称为显式删除 函数。


C++11引入显式缺省和显式删除是为了增强对 类默认函数的控制，
让程序员能够更加精细地控制 默认版本的函数。

不过这并不是它们的唯一功能， 而且使用上，也不仅仅局限在类的定义内。
事实 上，显式缺省不仅可以用于在类的定义中修饰成员函数，也可以在类定义之外修饰成员函数。代
*/

class DefaultedOptr
{
public:
    DefaultedOptr() = default; // 显式缺省构造函数 
    //这里没使用“=default” 
    DefaultedOptr& operator=(const DefaultedOptr &);
};

inline DefaultedOptr&
DefaultedOptr::operator=(const DefaultedOptr&)=default; // 显式缺省赋值运算符

int main()
{
    return 0;
}

/*
类DefaultedOptr的操作符 operator=被声明在了类的定义外，并且被设定为 缺省版本。
这在C++11规则中也是被允许的。
在类定义外显式指定缺省版本所带来的好处是，程序 员可以对一个class定义提供多个实现版本。



C++11标准并 不要求编译器为这些函数提供缺省的实现，
但如果将其声明为显式缺省的话，
则编译器会按照某 些“标准行为”为其生成所需要的版本。
*/
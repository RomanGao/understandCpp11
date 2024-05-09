//仿函数（functor）
//仿函数简单地说， 就是重定义了成员函数operator()的一种自定义类 型对象。这样的对象有个特点，就是其使用在代码 层面感觉跟函数的使用并无二样，
//但究其本质却并 非函数

class _functor
{
public:
    int operator()(int x, int y){return x+y;}
};

int main()
{
    int girls = 3, boys = 4;
    _functor totalChild;
    return totalChild(girls, boys);
}
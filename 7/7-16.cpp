/*
而在一些情况下，
我们需要对象在指定内存位置进行内存分配，并且不 需要析构函数来完成一些对象级别的清理。
这个时候，我们可以通过显式删除析构函数来限制自定义 类型在栈上或者静态的构造。
*/


#include <cstddef>
#include <new>

void*p; 
class NoStackAlloc
{ 
public:
    ~NoStackAlloc()=delete;
};
int main() 
{
    //NoStackAlloc nsa;//无法通过编译 
    new(p)NoStackAlloc();//placement new,假设p无需 调用析构函数 
    return 1; 
}

/*
由于placement new构造的对象，编译器不会
为其调用析构函数，因此析构函数被删除的类能够 正常地构造。
事实上，读者可以推而广之，
将显式 删除析构函数用于构建单件模式（Singleton），
*/

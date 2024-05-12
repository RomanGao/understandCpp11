/*
显式删除还有一些有趣的使用方式。
比如程序 员使用显式删除来删除自定义类型的operator new 操作符的话，就可以做到避免在堆上分配该class的 对象。
*/

#include <cstddef>
class NoHeapAlloc
{ 
public: 
    void*operator new(std::size_t)=delete; 
};
int main()
{ 
    NoHeapAlloc nha; 
    //NoHeapAlloc*pnha=new NoHeapAlloc;//编译失败 
    return 1; 
}
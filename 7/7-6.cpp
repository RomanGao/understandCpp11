/*
不过C++11标准并没有禁止声明一个nullptr的 右值引用，
并打印其地址，因此我们在一些编译器 上也做了个有趣的实验，
*/

#include <cstdio>
#include<cstddef>
using namespace std;

int main() 
{
    nullptr_t my_null;
    printf("%x\n", &my_null);
    //printf("%x",＆nullptr);//根据C++11的标准设定， 本句无法编译通过
    printf("%d\n", my_null == nullptr);

    const nullptr_t&& default_nullptr=nullptr;//default_nullptr是 nullptr的一个右值引用 
    printf("%x\n",&default_nullptr);    
}

/*
需要记得的仅仅 是，不要对nullptr做取地址操作即可。
*/

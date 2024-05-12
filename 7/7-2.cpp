/*
部标识__null，nullptr拥有更大的优势。
简单而言，由于nullptr是有类型的，且仅可以被隐式转化 为指针类型，
那么对于代码7-1的例子，nullptr做 参数则可以成功调用f(char*)版本的函数，
而不是 像gcc对NULL的处理一样，仅仅给出一个出错提 示，好让程序员去修改代码。
*/


#include <stdio.h>

void f(char* c)
{
    printf("char* f(char* )\n");
}

void f(int i)
{
    printf("int f(int )\n");
}

int main()
{
    f(0);
    f(nullptr); 
}
/*
在改为使用nullptr之后，用户能够 准确表达自己的意图，
也不会再出现在XLC编译器 上调用了f(int)版本而在gcc上却在编译时期给出了 错误提示的不兼容问题。
因此，通常情况下，在书 写C++11代码想使用NULL的时候，将NULL替换 成为nullptr我们就能获得更加健壮的代码。
*/
/*
而对于Unicode的字符串，也可以通过相同的 方式声明。声明UTF-8、UTF-16、UTF-32的原生
字符串字面量，将其前缀分别设为u8R、uR、UR 就可以了。
不过有一点需要注意，使用了原生字符 串的话，转义字符就不能使用了，这会给想使用\u 或者\U的方式写Unicode字符的程序员带来一定影 响。
*/

#include <iostream>
using namespace std;

int main()
{
    cout<<u8R"(\u4F60,\n \u597D)"<<endl;
    cout<<u8R"(你好)"<<endl;
    cout<<sizeof(u8R"(hello)")<<"\t"<<u8R"(hello)"<<endl;
    cout<<sizeof(uR"(hello)")<<"\t"<<uR"(hello)"<<endl;
    cout<<sizeof(UR"(hello)")<<"\t"<<UR"(hello)"<<endl;

    return 0;
}

/*
当程序员试图使用\u将数字转义为 Unicode的时候，原生字符串会保持程序员所写的 字面值，所以这样的企图并不能如愿以偿。
而借助 文本编辑器直接输入中文字符，反而可以在实验机 的环境下在文件中有效地保存UTF-8的字符（因为 编辑器按照UTF-8编码保存了文件）。
程序员应该注意到编辑器使用的编码对Unicode的影响。
而在 之后面的sizeof运算符中，我们看到了不同编码下 原生字符串字面量的大小，跟其声明的类型是完全 一致的。
*/
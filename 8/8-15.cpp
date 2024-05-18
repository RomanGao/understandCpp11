#include <iostream>
using namespace std; 

int main()
{ 
    char utf8[]=u8"\u4F60\u597D\u554A"; 
    char16_t utf16[]=u"\u4F60\u597D\u554A"; 
    cout<<sizeof(utf8)<<endl;//10字节 
    cout<<sizeof(utf16)<<endl;//8字节 
    cout<<utf8[1]<<endl;//输出不可见字符 
    cout<<utf16[1]<<endl;//输出22909(0x597D)
    return 0;
 }

 /*
 UTF-8由于采 用了变长编码，在这里把每个中文字符编码为3字 节，再加上'\0'的字符串终止符，所以utf8变量的 大小是10字节。
 而UTF-16则是定长编码，所以 utf16占用了8字节空间。


倘若我们按照使用ASCII 字符的思路来使用Unicode字符，
比如使用数组来 访问的时候，
我们发现utf8的输出是不正确的（这 里的utf16是正确的，只是实验机无法正常输 出）。
事实上，我们将UTF-8编码的数据放在了一 个char类型中，所以utf8[1]只是指向了第一个 UTF-8字符3字节中的第二位，因此输出不正常。


相比于定长编码的UTF-16，变长编码的UTF-8 的优势在于支持更多的Unicode码位，
而且也没有大数端小端段问题（而有字节序问题的UTF-16有 LE和BE两种不同版本）。
不过不能直接数组式访问 是UTF-8的最大的缺点。
此外，C++11为 char16_t和char32_t分别配备了u16string及 u32string等字符串类型，却没有u8string（因为 从实现上讲，变长的UTF-8编码的数据也不是很容 易与string配合使用）。
这样一来，UTF-8的字符 串不能够被方便地进行增删、查找，至于利用各种 高级的STL算法，就更加困难了。

*/


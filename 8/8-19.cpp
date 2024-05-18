/*
我们使用了wifstream来 打开一个UTF-8编码的文件。随后调用了这个 wifstream的imbue函数，为其设定了一个为 en_US.UTF-8的locale。
这样一来当进行I/O操作 的时候，会使用完成UTF-8到UTF-32编码转换的 facet（codecvt＜wchar_t,char,mbstate_t＞）来 完成编码转换.

codecvt还派生一些形如codecvt_utf8、 codecvt_utf16、codecvt_utf8_utf16等可以用于 字符串转换的模板类。
这些模板类配合C++11定 义的wstirng_convert模板，可以进行一些不同字 符串的转换。
*/

//#include<cvt/wstring>
#include<codecvt>
#include<iostream>
using namespace std;

int main()
{
    wstring_convert<codecvt_utf8<wchar_t>> conv;
    string mbstring=conv.to_bytes(L"Hello\n");

    cout<<mbstring;
    return 0;
}

/*
wstring_convert还支持使用 from_bytes来完成逆向的编码转换。
*/

/*
所以从实际情况出发，程序员可以利用不同 的codecvt的facet来将UTF-8编码存储的字符与不 同的Unicode进行转换，
而不必直接将UTF-16和 UTF-32编码的字符存储到文件，
基于此，也就没 在C++11标准中提供支持该功能的u16ifstream、 u32ofstream等
*/

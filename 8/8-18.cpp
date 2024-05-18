/*
而在使用facet上，用户并不需要显式地在代码 中生成codecvt对象。
比如在对C++11中stream 进行I/O时，我们只需要一些简单的设定，就可以 让stream自动进行一些编码的转换。
*/

#include <iostream>
#include <fstream>
#include <locale>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
    //UTF-8字符 串,"\x7a\xc3\x9f\xe6\xb0\xb4\xf0\x9d\x84\x8b";
    ofstream("text.txt")<<u8"z\u00df\u6c34\U0001d10b";
    wifstream fin("text.txt");
    fin.imbue(locale("en_US.UTF-8"));

    cout<<"The UTF-8 file contains the following wide characters:\n";
    for(wchar_t c; fin>>c; )
    {
        cout<<"U+"<<hex<<setw(4)<<setfill('0')<<uppercase<<c<<'\n';
    }

    return 0;
}


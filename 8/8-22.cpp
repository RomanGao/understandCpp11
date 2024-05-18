/*
此外，原生字符串字面量也像C的字符串字面量 一样遵从连接规则。
*/

#include <iostream>

using namespace std;

int main() 
{
    char u8string[]=u8R"(你好)""=hello";
    cout<<u8string<<endl;//输出"你好=hello" 
    cout<<sizeof(u8string)<<endl;//输出14
}

/*
原生字符串字面 量和普通的字符串字面量会被编译器自动连接起 来。整个字符串有2个3字节的中文字符，以及8个 ASCII字符，加上自动生成的\0，字符串的总长度 为15字节。与非原生字符串字面量一样，
连接不同 前缀的（编码）的字符串有可能导致不可知的结 果，
所以程序员总是应该避免这样使用字符串。
*/
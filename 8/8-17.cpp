/*
通常知道了一个地区的locale，要使用不同的地 区特征，则需访问该locale的一个facet。
facet可 以简单地理解为是locale的一些接口。
比如对于所 有的locale都会有num_put/num_get的操作，那 么这些操作就是针对该locale数值存取的接口，
即 该locale情况下数值存取的facet。
在C++中常见的 facet除去num_get/num_put、 money_get/money_put等外，还有一种就是codecvt

codecvt从类型上来讲是一个模板类，
从功能上 讲，是一种能够完成从当前locale下多字符编码字 符串到多种Unicode字符编码转换
（也包括 Unicode字符编码间的转换）的facet。
这里的多字 节字符串不仅可以是UTF-8，也可以是GB2312或 者其他，其实际依赖于locale所采用的编码方式。

这里的多字 节字符串不仅可以是UTF-8，也可以是GB2312或 者其他，其实际依赖于locale所采用的编码方式。 
在C++标准中，规定一共需要实现4种这样的 codecvt facet。

std::codecvt＜char,char,std::mbstate_t＞//完成 多字节与char之间的转换 
std::codecvt＜char16_t,char,std::mbstate_t＞// 完成UTF-16与UTF-8间的转换 
std::codecvt＜char32_t,char,std::mbstate_t＞// 完成UTF-32与UTF-8间的转换 
std::codecvt＜wchar_t,char,std::mbstate_t＞//完 成多字节与wchar_t之间的转换
*/
/*
每种facet负责不同类型编码数据的转换。
值得 注意的是，现行编译器支持情况下，一种locale并 不一定支持所有的codecvt的facet。
程序员可以通 过has_facet来查询该locale在本机上的支持情况:
*/

#include<iostream>
#include<locale>
using namespace std;   

int main()
{
    //定义一个locale并查询该locale是否支持一些facet
    locale lc("en_US.UTF-8");
    bool can_cvt=has_facet<codecvt<
    wchar_t,char,mbstate_t>>(lc);
    if(!can_cvt)
        cout<<"This locale does not support codecvt<wchar_t,char,mbstate_t>"<<endl;
    
    can_cvt=has_facet<codecvt<char16_t,char,mbstate_t>>(lc);
    if(!can_cvt)
        cout<<"This locale does not support codecvt<char16_t,char,mbstate_t>"<<endl;

    can_cvt=has_facet<codecvt<char32_t,char,mbstate_t>>(lc);
    if(!can_cvt)
        cout<<"This locale does not support codecvt<char32_t,char,mbstate_t>"<<endl;


    can_cvt=has_facet<codecvt<char,char,mbstate_t>>(lc);
    if(!can_cvt)
        cout<<"This locale does not support codecvt<char,char,mbstate_t>"<<endl;

    return 0;
}
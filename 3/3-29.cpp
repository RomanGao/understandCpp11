/*
初始化列表

c++98中，标准允许使用花括号"{}"对数组 元素进行统一的集合（列表）初始值设定，
int arr[5]={0}; int arr[]={1,2,3,4};

集合（列表）的初始化已经成为C++语言的一 个基本功能，
在C++11中，这种初始化的方法被 称为“初始化列表”（initializer list）。
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
    int a[] = {1,2,3};  ////C++98通过，C++11通过
    int b[]{1,2,3};  //C++98失败，C++11通过
    vector<int> c{1,2,3}; //C++98失败，C++11通过
    map<int,float> d = {{1,2.0},{3,4.5}}; //    C++98失败，C++11通过
    
    return 0;
}
//列表初始化可以在“{}”花括号之前 使用等号，其效果与不带使用等号的初始化相同。
/*
程序员可以使用以下几种形 式完成初始化的工作：
 ❑等号“=”加上赋值表达式（assignment- expression)，比如int a=3+4。 
 ❑等号“=”加上花括号式的初始化列表，比如 int a={3+4}。
 ❑圆括号式的表达式列表（expression-list）， 比如int a(3+4)。
 ❑花括号式的初始化列表，比如int a{3+4}。


而后两种形式也可以用于获取堆内存new操作 符中，比如：
int*i=new int(1); double*d=new double{1.2f};
*/
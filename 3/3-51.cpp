/*
在C++中，使用typedef为类型定义别名。
typedef int myint;

当遇到一些比 较长的名字，尤其是在使用模板和域的时候,使用 别名的优势会更加明显。

typedef std::vector＜std::string＞strvec;

使用using同样也可以定义类 型的别名，而且从语言能力上看，using丝毫不比 typedef逊色。
*/

#include<iostream> 
#include<type_traits> 
using namespace std; 
using uint=unsigned int; 
typedef unsigned int UINT; 
using sint=int; 
//int main()
//{ 
//    cout<<is_same<uint,UINT>::value<<endl;//1 
//}//编译选项:g++ -std=c++11 3-10-1.cpp
//使用了C++11标准库中的is_same 模板类来帮助我们判断两个类型是否一致。


//在使用模板编程的时候，using的语法甚至比 typedef更加灵活。

#include<map> 
using std::map; 
template<typename T> 
using MapString=std::map<string,T>; 
MapString<int> map1; 
//使用typedef将 无法达到这样的效果
int main()
{

}
/*
标准模板库中容器对初始化列表的支持源 自＜initializer_list＞这个头文件中initialize_list类模 板的支持。
程序员只要#include了＜initializer_list ＞头文件，并且声明一个以initialize_list＜T＞模板 类为参数的构造函数，同样可以使得自定义的类使 用列表初始化。
*/

#include <iostream>
#include<vector>
#include<string>
#include<initializer_list>
using namespace std;

enum Gender {boy, girl};

class Person 
{
public:
    Person(initializer_list<pair<string, Gender>> initList)
    {
        for (auto iter = initList.begin(); iter != initList.end(); ++iter)
        {
            m_vec.push_back(*iter);
        }
    }

private:
    vector<pair<string, Gender>> m_vec;
};

int main(int argc, char const *argv[])
{
    Person ship2012 = {{"gao", boy}, {"chang", girl}};
    return 0;
}

//类Person定义了一 个使用initializer_list＜pair＜string,Gender＞＞模 板类作为参数的构造函数。
//由于该构造函数的存在， ship2012声明就可以使用列表初始化


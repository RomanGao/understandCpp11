//类和结构体的成员函数 也可以使用初始化列表，包括一些操作符的重载函数。
//利用了初始化列表重载了operator[]，并且重载了 operator=以及使用辅助的数组。

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Array 
{
public:
    Array &operator[](initializer_list<int> l)
    {
        for (auto i = l.begin(); i != l.end(); ++i)
        {
            index.push_back(*i);
        }
        return *this;
    }
    Array &operator=(int v)
    {
        if(!index.empty())
        {
            for(auto i = index.begin(); i != index.end(); ++i)
            {
                data.resize(*i > data.size() ? *i : data.size());
                data[*i-1] = v;
            }
            index.clear();
        }
        return *this;
    }

void print()
{
    for(auto i = data.begin(); i != data.end(); ++i)
    {
        cout << *i <<"";
        cout<<endl;
    }
}
private:
    vector<int> index;
    vector<int> data;
};

int main()
{
    Array a;
    a[{1,2,3}] = 4;
    a[{4,5}] = 10;
    a.print();
    return 0;
}

/*
此外，初始化列表还可以用于函数返回的情 况。
返回一个初始化列表，通常会导致构造一个临 时变量，比如：
vector＜int＞ Func(){return{1,3};}

当然，跟声明时采用列表初始化一样，列表初 始化构造成什么类型是依据返回类型的，
比如： deque＜int＞ Func2(){return{3,5};}
上面的返回值就是以deque＜int＞列表初始化 构造函数而构造的.

而跟普通的字面量相同，如果 返回值是一个引用类型的话，则会返回一个临时变 量的引用。
比如： const vector＜int＞ ＆Func1(){return{3,5};}
这里注意，必须要加const限制符。该规则与返 回一个字面常量是一样的。

*/


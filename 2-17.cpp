//相对于传统的初始化列表，在类声明中对非静态成员变量进行就地列表初始化可以降低程序员的工作量
//只在有多个构造函数，且有多个成员变量的时候可以看到新方式带来的便利

#include <string>
using namespace std;

class Mem
{
public:
    Mem(int i ):m(i){}
private:
    int m;
};

class Group
{
public:
    Group() {}
    Group(int a):data(a){} //这里就不需要初始化mem、name成员了
    Group(Mem m):mem(m){}  //这里就不需要初始化data、name成员了
    Group(int a , Mem m, string n):data(a),mem(m),name(n){}

private:
    int data =1;
    Mem mem{0};
    string name{"Group"};
};
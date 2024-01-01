//_Pragma(字符串字面量)
//_Pragma("once");


#include<iostream>
#include<string>
using namespace std;

struct TestStruct{
    TestStruct():name(__func__){}
    const char* name;
};
//_fun__标识符作为函数参数的默认值是不允许
/*
int main()
{
    // cout<<"hello"<<endl;
    TestStruct ts;
    cout<<ts.name<<endl;

    return 0;
}
*/


//就地初始化和初始化列表并不冲突。
//初始化列表的效果总是优先于就地初始化的。

#include<iostream>
using namespace std;

struct Mem
{
    Mem() {cout <<"Mem default, num: " << num<<endl;}
    Mem(int i):num(i) {cout <<"Mem, num: " << num<<endl;}
    int num = 2; //使用=初始化非静态函数
};

class Group
{
public:
    Group() {cout<<"Group default.val:"<<val<<endl;}
    Group(int i):val('G'),a(i){cout<<"Group.val: "<<val<<endl;}

    void NumOfA(){cout<<"numberofA:"<<a.num<<endl;}
    void NumOfB(){cout<<"numberofB:"<<b.num<<endl;}
private:
    char val{'g'}; //使用{}初始化非静态成员函数
    Mem a;
    Mem b{19}; //使用{}初始化非静态成员函数
};
/*
int main(){
    Mem member;//Memdefault,num:2
    Group group;//Memdefault,num:2
    //Mem,num:19
    //Groupdefault.val:g
    group.NumOfA();//numberofA:2
    group.NumOfB();//numberofB:19
    Group group2(7);//Mem,num:7
    //Mem,num:19
    //Group.val:G
    group2.NumOfA();//numberofA:7
    group2.NumOfB();//numberofB:19

    return 0;
}*/
#include<iostream>
using namespace std;

class  HugeMen

{
private:
    /* data */
public:
     HugeMen(int size):sz(size>0?size:1)
     {
        c = new int[sz];
     }
    ~ HugeMen()
    {
        delete[] c;
    }
    HugeMen(HugeMen &&other):sz(other.sz),c(other.c)
    {
        other.c = nullptr;
    }

    int *c;
    int sz;
};

class Mobeable
{
private:
    /* data */
public:
    Mobeable(/* args */):i(new int(10)),hm(new HugeMen(2)){}
    ~Mobeable()
    {
        delete i;
    }
    Mobeable(Mobeable &&other):i(other.i),hm(move(other.hm))//移动构造函数
    {
        other.i = nullptr;
    }
    //使用std::move强制其为右值.
    //如果我们不这么做，由于m.h是个左值，就会导致调用HugeMem的拷贝构造函数来构造Moveable的成员h.
    //如果是这样，移动语义就没有能够成功地向类的成员传递。换言之，还是会由于拷贝而导致一定的性能上的损失
    int *i;
    HugeMen *hm;
};

Mobeable GetTemp()
{
    Mobeable m = Mobeable();
    cout<<hex<<"HugeMen from: "<<__func__<<"@"<<m.hm->c<<endl;
    return m; //移动构造
}

int main(int argc, char const *argv[])
{
    Mobeable m = GetTemp();
    cout<<hex<<"HugeMen from: "<<__func__<<"@"<<m.hm->c<<endl;
    return 0;
}


 
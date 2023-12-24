/*
第三章 从3-11开始

委派构造函数
*/


class Info
{ 
public: 
    Info()  {InitRest();}          //目标构造函数
    Info(int i):Info(){type=i;}   //为委派构造函数
    Info(char e):Info(){name=e;}  //为委派构造函数
private: 
    void InitRest(){/*其他初始化*/} 
    int type{1}; 
    char name{'a'}; 
    //... 
};

/*
，委派构造函数只能 在函数体中为type、name等成员赋初值。
这是由 于委派构造函数不能有初始化列表造成的

struct Rule1{ 
    int i; 
    Rule1(int a):i(a){} 
    Rule1():Rule1(40),i(1){}//无法通过编译
 };

 因为初始化列表的初始化方式 总是先于构造函数完成的
*/
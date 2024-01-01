/*
而在构造函数比较多的时候，我们可能会拥有
不止一个委派构造函数，而一些目标构造函数很可 能也是委派构造函数，
这样一来，我们就可能在委 派构造函数中形成链状的委派构造关系
*/

class Info
{ 
public: 
    Info():Info(1){}//委派构造函数 
    Info(int i):Info(i,'a'){}//既是目标构造函数，也是 委派构造函数 
    Info(char e):Info(1,e){} 
private: 
    Info(int i,char e):type(i),name(e){/*其他初始化 */}//目标构造函数 
    int type; 
    char name; //... 
};

/*
在委托构 造的链状关系中，有一点程序员必须注意，就是不 能形成委托环（delegation cycle）。

*/
//虽然在C++11中这是一个小的改进，却会带来 一点应用的变化——程序员可以为类模板声明友元了。

class P;
template<typename T>
class  People
{
    friend T;
};

People<P> pp; //类型P在这里是People类型的友元
People<int> pi; //对于int类型模板参数，友元声明被忽略
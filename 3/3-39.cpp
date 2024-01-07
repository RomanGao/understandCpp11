//在新的C++11标准 中，取消了联合体对于数据成员类型的限制。
//标准 规定，任何非引用类型都可以成为联合体的数据成 员，
//这样的联合体即所谓的非受限联合体 （Unrestricted Union）。

//此外，联合体拥有静态成 员(在非匿名联合体中)的限制，也在C++11新标准 中被删除了
//不过从实践中，我们发现C++11的 规则不允许静态成员变量的存在（否则所有该类型 的联合体将共享一个值）。而静态成员函数存在的 唯一作用，大概就是为了返回一个常数
//因此，C++11标准中，联合体中的静态成员变量，只 能是const static。

#include <iostream>
using namespace std;
union U {
    static long Get() { return 1; }
};

int main() {
    cout << U::Get() << endl;
    return 0;
}

//就定义了一个有静态 成员函数的联合体。不过看起来这里的union T更 像是一个作用域限制符，并没有太大的实用意义。

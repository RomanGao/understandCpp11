/*
代码清单2-7和代码清单2-8这类问题的解决方案是进行编译时期的断言，即所谓的“静态断言”

事实上，利用语言规则实现静态断言的讨论非常多，比较典型的实现是开源库Boost内置的
BOOST_STATIC_ASSERT断言机制（利用sizeof操作符）。



我们可以利用“除0”会导致编译器报错这个特性来实现静态断言(即：下面代码编译不过，编译器会报错)
*/
#include<cstring>
using namespace  std;

/*
#define assert_static(e)\
do{\
    enum{assert_static__=1/(e) };\
} while (0)
*/
/*
在C++11标准中，引入了static_assert断言来解决断信息不够充分，
不熟悉该静态断言实现的程序员可能一时无法将错误对应到断言错误上，从而难以准确定位错误的根源的问题；

*/
template<typename T, typename U>
int bit_copy(T& a, U&b)
{
 //   assert_static(sizeof(a) == sizeof(b));
    static_assert(sizeof(b)==sizeof(a),"the parametersofbit_copymusthave samewidth.");
    memcpy(&a, &b, sizeof(b));
};
/*
int main()
{
    int a = 0x2345;
    double b;
    bit_copy(a, b);
}
*/
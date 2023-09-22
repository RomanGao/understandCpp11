//C++的模板的编写中使用assert
#include<assert.h>
#include<cstring>
using namespace  std;

template<typename T, typename U>
int bit_copy(T& a, U&b)
{
    assert(sizeof(a) == sizeof(b));

    memcpy(&a, &b, sizeof(b));
}

int main()
{
    int a = 0x2345;
    double b;
    bit_copy(a, b);
}

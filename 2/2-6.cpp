#define NDEBUG  //使用此，assert语句失效
#include<cassert>

using namespace std;


char * ArrayAlloc(int n)
{
    assert(n > 0);
    return new char[n];
}
/*

int main()
{
    char *a = ArrayAlloc(0);


    return 0;
}
*/

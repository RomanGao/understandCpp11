/*
__VA_ARGS__则可以在宏定义的实现部分替换省略号所代表的字符串
#definePR(...)printf(__VA_ARGS__)
*/


#include<stdio.h>

#define LOG(...){\
fprintf(stderr,"%s:Line%d:\t",__FILE__,__LINE__);\
fprintf(stderr,__VA_ARGS__);\
fprintf(stderr,"\n");\
}
/*
int main()
{

    int x = 3;
    LOG("x=%d", x);

}*/
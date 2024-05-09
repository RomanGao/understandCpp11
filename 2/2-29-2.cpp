/*
“外部”（extern）

我们在一个文件中a.c中定义了一个变量int i，而在另外一个文 件b.c中想使用它，
这个时候我们就会在没有定义变 量i的b.c文件中做一个外部变量的声明

这样做的好处是，在分别编译了a.c和b.c之后，其生成的目标文件a.o和b.o中只有i这个符号的一份定义。
具体地，a.o中的i是实在存在于a.o目标文件的数据区中的数据，而在b.o中，只是记录了i符号(symbol)会引用其他目标文件中数据区中的名为i的数据。 
这样一来，在链接器（通常由编译器代为调用）将 a.o和b.o链接成单个可执行文件（或者库文件）c的 时候，
c文件的数据区也只会有一个i的数据（供a.c 和b.c的代码共享）。


而如果b.c中我们声明int i的时候不加上extern 的话，那么i就会实实在在地既存在于a.o的数据区中，也存在于b.o的数据区中。
那么链接器在链接 a.o和b.o的时候，就会报告错误，因为无法决定相 同的符号是否需要合并。


而对于函数模板来说，现在我们遇到的几乎是一模一样的问题。
不同的是，发生问题的不是变量（数据），而是函数（代码）。
这样的困境是由于 模板的实例化带来的。


对于源代码中出现的每 一处模板实例化，编译器都需要去做实例化的工作；
而在链接时，链接器还需要移除重复的实例化代码

很明显，这样的工作太过冗余，而在广泛使 用模板的项目中，由于编译器会产生大量冗余代 码，会极大地增加编译器的编译时间和链接时间。 
解决这个问题的方法基本跟变量共享的思路是一样 的，就是使用“外部的”模板

test.h
template＜typename T＞void fun(T){}

test1.cpp
#include "test.h" 
template void fun＜int＞(int);//显示地实例化 
void test1(){fun(3);}

test2.cpp
#include "test.h"
extern template void fun＜int＞(int);//外部模板 的声明
void test1(){fun(3);}

这样一来，在test2.o中不会再生成fun＜int＞ (int)的实例代码(因为test2.cpp中加入了extern关键词)



在使用外部模板的时候，我们还需要注意以下 问题：
如果外部模板声明出现于某个编译单元中， 那么与之对应的显示实例化必须出现于另一个编译 单元中或者同一个编译单元的后续代码中；
外部模 板声明不能用于一个静态函数（即文件域函数），但可以用于类静态成员函数（这一点是显而易见 的，因为静态函数没有外部链接属性，不可能在本
编译单元之外出现）


“模板的显式实例化定 义、外部模板声明和使用”好比“全局变量的定义、外部声明和使用”方式的再次应用。
不过相比于外部变量声明，不使用外部模板声明并不会导致 任何问题
*/


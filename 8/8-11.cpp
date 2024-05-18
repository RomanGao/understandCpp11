/*
C++11语言中的通用属性使用了左右双中括号 的形式：
 [[attribute-list]] 
 这样设计的好处是：
 既不会消除语言添加或者 重载关键字的能力，又不会占用用户空间的关键字 的名字空间。

对于作用于声明的通用属 性，既可以写在声明的起始处，也可以写在声明的 标识符之后。
而对于作用于整个语句的通用属性， 则应该写在语句起始处。
而出现在以上两种规则描述的位置之外的通用属性，作用于哪个实体跟编译 器具体的实现有关。

第一个是关于通用属性 应用于函数的，具体如下：
 [[attr1]]void func[[attr2]]();
 这里，[[attr1]]出现在函数定义之前，而 [[attr2]]则位于函数名称之后，
 根据定义，[[attr1]] 和[[attr2]]均可以作用于函数[func]


下一个是数组 的例子：
[[attr1]]int array[[attr2]][10];
这跟第一个例子很类似，根据定义，[[attr1]]和 [[attr2]]均可以作用于数组array。


[[attr1]]class C[[attr2]]{} 
[[attr3]]c1[[attr4]],c2[[attr5]];
这个例子声明了类C及其类型的变量c1和c2。 
本语句中，一共有5个不同的属性。按照C++11的 定义，
[[attr1]]和[[attr4]]会作用于c1，
[[attr1]]和 [[attr5]]会作用于c2，
[[attr2]]出现在声明之后，仅 作用于类C，
而[[attr3]]所作用的对象则跟具体实现 有关。


下面是一个switch-case加标签的例子： 
[[attr1]]L1: 
switch(value)
{ 
    [[attr2]]case 1://do something... 
    [[attr3]]case 2://do something... 
    [[attr4]]break; 
    [[attr5]]default://do something...
}
[[attr6]]goto L1; 
这里，[[attr1]]作用于标签L1，
[[attr2]]和 [[attr3]]作用于case 1和case 2表达式，
[[attr4]]作 用于break，[[attr5]]作用于default表达式， 
[[attr6]]作用于goto语句。

下面的for语句也是类似 的：
[[attr1]]for(int i=0;i＜top;i++)
{ //do something... }[[attr2]]return top; 这里，[[attr1]]作用于for表达式，[[attr2]]作用 于return。下面是函数有参数的情况： [[attr1]]int func([[attr2]]int i,[[attr3]]int j) {
//do something [[attr4]]return i+j; }
[[attr1]]作用于函数func，
[[attr2]]和[[attr3]]分 别作用于整型参数i和j，
[[attr4]]作用于return语 句。
*/


/*
在现有C++11标准中，只预定义了两 个通用属性，
分别是[[noreturn]]和 [[carries_dependency]]。

*/
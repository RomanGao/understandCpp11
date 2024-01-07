/*
非受限联合体
在C/C++中，联合体（Union）是一种构造类 型的数据结构。
在一个联合体内，我们可以定义多 种不同的数据类型，这些数据将会共享相同内存空 间，这在一些需要复用内存的情况下，可以达到节 省空间的目的。
不过，根据C++98标准，并不是 所有的数据类型都能够成为联合体的数据成员。
*/

struct Student
{
    Student(bool g,int a):gender(g),age(a){} 
    bool gender; 
    int age;
};

union T
{ 
    Student s;//std=c++98中 编译失败，不是一个POD类型， std=c++11中编译成功
    int id; 
    char name[10]; 
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
//，除了非POD类型之外，C++98标 准也不允许联合体拥有静态或引用类型的成员。
//这 样虽然可能在一定程度上保证了和C的兼容性，不 过也为联合体的使用带来了很大的限制。



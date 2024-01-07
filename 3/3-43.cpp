//匿名非受限联合体可以运用于类的声明中，
//这 样的类也被称为“枚举式的类”（union-like class）。


#include<cstring>
using namespace std;

struct Student
{
    Student(bool g, int a):age(a), gender(g){}
    int age;
    bool gender;
};

class Singer
{
public:
    enum Type{STUDENT, NATIVE, FOREIGENER};
    Singer(bool g, int a):s(g, a){t = STUDENT;}
    Singer(int i):id(i){t = NATIVE;}
    Singer(const char* n, int s)
    {
        int size = (s>9)?9:s;
        memcpy(name, n, size);
        name[s] = '\0';
        t = FOREIGENER;
    }   
private:
    Type t;
    union{//匿名的非受限联合体 
        Student s; 
        int id; 
        char name[10]; 
    };
};

int main()
{
    Singer(true,13);
    Singer(310217); 
    Singer("J Michael",9);
}

//我们也把匿名非受限联合 体成为类Singer的“变长成员”（variant member）。
//可以看到，这样的变长成员给类的编 写带来了更大的灵活性，这是C++98标准中无法 达到的。
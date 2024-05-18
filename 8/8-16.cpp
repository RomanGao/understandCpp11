#include<iostream>
#include<cuchar>
using namespace std;

int main()
{
    char16_t utf16[]=u"\u4F60\u597D\u554A";
    char mbr[sizeof(utf16)*2] = {0};

    mbstate_t s;
   // c16rtomb(mbr, utf16, &s);
    cout<<mbr<<endl;

    return 0;
}
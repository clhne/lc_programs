#include <iostream>
using namespace std;
int main()
{
    int i;
    float f = 166.71;
    i = static_cast<int> (f);
    cout<<i<<endl;
    
    int j;
    char *p = "Thisisanexample.";
    j = reinterpret_cast<int>(p);
    cout<<j<<endl;
    return 0;
}

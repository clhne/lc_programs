#include <iostream>
using namespace std;
int main()
{
    char *ptr = "abc\\\n\"def"; // abc\ 回车 "def
    cout<<ptr<<endl;

    return 0;
}

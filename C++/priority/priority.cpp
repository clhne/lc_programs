#include <iostream>
#include <cmath>
using  namespace std;
int main()
{
    float center = 1;
    float x = 3;
    float y = 6;
    float z = 9;
    float result = center > 0 && abs(x-y) <= 2? y:z;
    float result1 = (center > 0 && abs(x-y) <= 2)? y:z;
    cout<<result<<endl;
    cout<<result1<<endl;
    
    return 0;
}

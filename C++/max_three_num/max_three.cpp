#include <iostream>
#define max_two(x,y) (x)>(y)?(x):(y)
using namespace std;
float max_three(float x, float y, float z){
    return max_two(x,y)>(z)?max_two(x,y):z;
}
int main()
{
    float x = 10, y = 2, z = 3;
    
    printf("max num is %f\n",max_three(x,y,z));

    return 0;
}

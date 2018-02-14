#include <math.h>
#include <iostream>
using namespace std;
//求x的平方根分之一的高效算法
float invSqrt(float x){
    float halfx = 0.5f * x;     
    float y = x;                
    long i = *(long*)&y;        //get bits for floating value
    i = 0x5f3759df - (i>>1);    //gives initial guess 
    y = *(float*)&i;            //convert bits BACK to float
    y = y * (1.5f - (halfx *y * y));    //newton step, repeating increases accuracy
    y = y * (1.5f - (halfx *y * y));
    y = y * (1.5f - (halfx *y * y));
    
    return y;
}

int main()
{
    float x = 3.0;
    printf("1.0/sqrt(%0.6f) = %0.6f\n",x,invSqrt(x));
    
    return 0;
}
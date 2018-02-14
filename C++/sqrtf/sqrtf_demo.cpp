#include <iostream>
#include <math.h>
#include <windows.h>
using namespace std;
double sqrt_binarysearch(double x)
{
    double low = 0;
    double up = x;
    double mid ,last;
    mid = (up + low)/2;
    do{
        if(mid * mid > x)
            up = mid;
        else 
            low = mid;
        last = mid;
        mid = (up + low)/2;
    }while(abs(mid-last)>0.000001);
    return mid;
}
double sqrtNewton(double x)
{
    double val = x;
    double last;
    do{
        last = val;
        val = (val + x/val)/2;
    }while(abs(val - last) > 0.000001);
    return val;
}

float InvSqrt(float x)
{
    float xhalf = 0.5f*x;
    int i = *(int*)&x; // get bits for floating VALUE 
    i = 0x5f375a86- (i>>1); // gives initial guess y0
    x = *(float*)&i; // convert bits BACK to float
    x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy
    //x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy
    //x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy

    return 1/x;
}
int main()
{
    float x = 65535.0;
    double time1,time2,time3,time4;
    LARGE_INTEGER nFreq1,nFreq2,nFreq3,nFreq4;
    LARGE_INTEGER nBeginTime1,nBeginTime2,nBeginTime3,nBeginTime4;
    LARGE_INTEGER nEndTime1,nEndTime2,nEndTime3,nEndTime4;
    
    QueryPerformanceFrequency(&nFreq1);
    QueryPerformanceCounter(&nBeginTime1);
    printf("sqrt(%f) = %f\n",x,sqrt(x));
    QueryPerformanceCounter(&nEndTime1);
    time1 = (double)(nEndTime1.QuadPart - nBeginTime1.QuadPart)/(double)nFreq1.QuadPart;
    //cout<<"sqrt runtime : "<<time1<<endl<<endl;
    printf("sqrt runtime : %0.16f\n\n",time1);
    
    QueryPerformanceFrequency(&nFreq2);
    QueryPerformanceCounter(&nBeginTime2);
    printf("sqrt_binarysearch(%f) = %f\n",x,sqrt_binarysearch(x));
    QueryPerformanceCounter(&nEndTime2);
    time2 = (double)(nEndTime2.QuadPart - nBeginTime2.QuadPart)/(double)nFreq2.QuadPart;
    //cout<<"sqrt_binarysearch runtime : "<<time2<<endl<<endl;
    printf("sqrt_binarysearch runtime : %0.16f\n\n",time2);
    
    QueryPerformanceFrequency(&nFreq3);
    QueryPerformanceCounter(&nBeginTime3);
    printf("sqrtNewton(%f) = %f\n",x,sqrtNewton(x));
    QueryPerformanceCounter(&nEndTime3);
    time3 = (double)(nEndTime3.QuadPart - nBeginTime3.QuadPart)/(double)nFreq3.QuadPart;
    //cout<<"sqrtNewton runtime : "<<time3<<endl;
    printf("sqrtNewton runtime : %0.16f\n\n",time3);

    QueryPerformanceFrequency(&nFreq4);
    QueryPerformanceCounter(&nBeginTime4);
    printf("InvSqrt(%f) = %f\n",x,InvSqrt(x));
    QueryPerformanceCounter(&nEndTime4);
    time4 = (double)(nEndTime4.QuadPart - nBeginTime4.QuadPart)/(double)nFreq4.QuadPart;
    printf("InvSqrt runtime : %0.16f\n\n",time4);
    return 0;
}
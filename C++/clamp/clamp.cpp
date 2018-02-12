#include <stdio.h>
#include <iostream>
using namespace std;
int clamp(int x ,int min, int max)
{
    //cout<<((x > max)?max:((x < min)?min:x));
    return ((x > max)?max:((x < min)?min:x));
}

template <typename T>
T clampT(T x, T min, T max){
    return ((x > max)?max:((x < min)?min:x));
}
int main()
{
    int a = 18;
    int min = 10;
    int max = 100;
    double aT = 2.2;
    double minT = 3.0;
    double maxT = 300.0;
  
    cout<<clamp(a,min,max)<<endl;
    cout<<clampT(a,min,max)<<endl;
    cout<<clampT(aT,minT,maxT)<<endl;
    cout<<clampT(23.2,3.0,300.3)<<endl;
    cout<<(int)clampT('d','a','z')<<endl;
    cout<<(int)('a')<<endl;
    cout<<clampT((bool)0,(bool)1,(bool)1)<<endl;
    return 0;
}
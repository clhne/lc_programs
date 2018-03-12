#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#define PI 3.14159265
#define cov (180 / PI)
using namespace std;

int main(int ac, char* av[])
{
    double x, y, theta;
    if(ac != 3)
    {
        fprintf(stderr,"Usage: %s <x> <y> \n",av[0]);
        return 1;
    }
    x = atof(av[1]);
    theta = atan(x);
    printf("Arctangent of %f / %f: %f\n",1.0, x, cov*theta);
    y = atof(av[2]);
    theta = atan2(y, x);
    printf("Arctangent of %f / %f: %f\n",y, x, theta);
    printf("Arctangent of 1.0/0 : %f\n",cov*atan2(1,0));    //atan2中第二个参数可以为0，atan不能；atan2 in the interval [-pi,+pi], atan [-pi/2,+pi/2]
    
    printf("atan2(-1/1) : %f\n",cov*atan2(1.0,-1));
    printf("atan(-1/1) : %f\n",cov*atan(-1));
    printf("atan2f (-1,1) : %f\n",cov * atan2f(-1.0,1));

    //system("pause");

    return 0;
}

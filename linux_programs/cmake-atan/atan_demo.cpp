#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <errno.h>
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
    printf("Arctangent of %f / %f: %f\n",y, x, theta);
    y = atof(av[2]);
    theta = atan2(y, x);
    printf("Arctangent of %f / %f: %f\n",y, x, theta);

    //system("pause");

    return 0;
}

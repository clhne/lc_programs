#include <iostream>
#include <cmath>
#define SIZE 5
using namespace std;

softmax(double *x)
{
    double max = 0.0;
    double sum = 0.0;

    for (int i = 0; i<SIZE; i++) {
        if (max < x[i]) max = x[i];
    }
    for (int i = 0; i<SIZE; i++) {
        x[i] = exp(x[i] - max);
        sum += x[i];
    }

    for (int i = 0; i<SIZE; i++) {
        x[i] /= sum;
    }
}

int main()
{
    double x[SIZE] = {1000,2,3,4,5};

    softmax(x);
    for(int i = 0; i < SIZE; i++) {
        cout<<x[i]<<endl;
    }
    return 0;
}
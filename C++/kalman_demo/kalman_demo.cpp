#include <iostream>
using namespace std;
float z[10] = {0.39, 0.50, 0.48, 0.29, 0.25, 0.32, 0.34, 0.48, 0.41, 0.45};
float R = 0.1, p[10] = {1}, x[10] = {0},k[10] = {0};

//TimeUpdate: prediction
float time_update(int i){
        x[i] = x[i];
        p[i] = p[i];
    return 0;
}

//Measurement Update: correction
float measurement_update(int j){
        k[j+1] = p[j]/(p[j] + R);
        x[j+1] = x[j] + k[j+1]*(z[j+1]-x[j]);
        p[j+1] = (1 - k[j+1]) * p[j];
    return 0;
}
int main()
{
    for(int i = 0; i < 10; i++){
        if(i == 0){
            k[0] = p[0]/(p[0] + R);
            x[0] += k[0]*(z[0]-x[0]);
            p[0] = (1-k[0])*p[0];
        }
        time_update(i);
        measurement_update(i);
    }
    for(int j = 0; j < 10; j++){
        printf("x[%d]=%f, p[%d] = %f, k[%d]=%f\n",j,x[j],j,p[j],j,k[j]);
    }
    return 0;
}
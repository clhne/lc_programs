#include <iostream>
#include <math.h>
using namespace std;

float math_round(float num){
	if(num < 0){
		return ceilf(num - 0.5);
	}
	else 
	{
		return floorf(num + 0.5);
	}
	return 0;
}

int main(){
	float num[2] = {-3.7, 7.8};
	printf("round(-3.7)=%f, round(7.8)=%f\n",math_round(num[0]),math_round(num[1]));
	
	return 0;
}
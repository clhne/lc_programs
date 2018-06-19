#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

float math_round(float num){
	float result;
	if(num < 0){
		result = ceilf(num - 0.5);
	}
	else 
	{
		result =  floorf(num + 0.5);
	}
	return result;
}
float math_round1(float num){
	return floorf(num + 0.5);
}
int main(){
	float num[2] = {-3.7, 7.8};
	int N;
	cin>>N;
	//float *array = new float [N];
	vector<float> array(N);
	for(int i = 0; i < N; i++){
		cin>>array[i];
		printf("round_array[%d] = %f\n",i, math_round(array[i]));
		printf("round1_array[%d] = %f\n",i, math_round1(array[i]));
	}
	printf("round(-3.7)=%f, round(7.8)=%f\n",math_round(num[0]),math_round(num[1]));
	printf("round1(-3.7)=%f, round1(7.8)=%f\n",math_round1(num[0]),math_round1(num[1]));
	//delete[] array;
	
	return 0;
}
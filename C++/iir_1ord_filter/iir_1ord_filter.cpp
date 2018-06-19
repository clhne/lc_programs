#include <iostream>
#include <fstream>
using namespace std;
int irr_1ord_filter(float *iir_data, float *input_data)
{
	float coef = 0.55;
	*iir_data = *input_data * (1 - coef) + *iir_data * coef;
	return 1;
}
int main(){
	int i;
	float coef = 0.55;
	float iir_data[10] = {0};
	float input_data[10] = {6, 5, 9, 10, 12, 13, 15, 15, 18, 20};
	int length = sizeof(input_data)/sizeof(input_data[0]);
	int is_init = 1;
	//write input_data to input_data.txt
	ofstream myfile;
	myfile.open("input_data.txt");
	for (i = 0; i < length; i++){
		myfile<<input_data[i]<<endl;
	}
	myfile.close();
	
	//irr_1ord_filter(irr_data, input_data), then write irr data to irr_data.txt
	myfile.open("iir_data.txt");
	for (i = 1; i < 10; i++){
		if(is_init){
			iir_data[0]=input_data[0]*(1-coef) + iir_data[0]*coef;
			myfile<<iir_data[0]<<endl;
		}
		is_init = 0;
		iir_data[i]=input_data[i]*(1-coef) + iir_data[i-1]*coef;
		//irr_1ord_filter(&iir_data[i], &input_data[i]);
		myfile<<iir_data[i]<<endl;
	}
	myfile.close();
	return 0;
}
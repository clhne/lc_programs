#include <iostream>
#include <fstream>
using namespace std;
void irr_1ord_filter(float *iir_data, float *input_data)
{
	float coef = 0.55;
	*iir_data = *input_data * (1 - coef) + *iir_data * coef;
}
int main(){
	int i;
	float iir_data[10] = {0};
	float input_data[10] = {0.6, 0.5, 0.9, 1.0, 1.2, 1.3, 1.5, 1.6, 1.8, 2.0};
	int length = sizeof(input_data)/sizeof(input_data[0]);
	
	//write input_data to input_data.txt
	ofstream myfile;
	myfile.open("input_data.txt");
	for (i = 0; i < length; i++){
		myfile<<input_data[i]<<endl;
	}
	myfile.close();
	
	//irr_1ord_filter(irr_data, input_data), then write irr data to irr_data.txt
	myfile.open("iir_data.txt");
	for (i = 0; i < 10; i++){
		irr_1ord_filter(&iir_data[i], &input_data[i]);
		myfile<<iir_data[i]<<endl;
	}
	myfile.close();
}
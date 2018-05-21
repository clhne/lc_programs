#include <iostream>
using namespace std;

char MATRIX_Identity(float *p_InMatrix_f32r, unsigned char v_dim_u8r) {
  int i, j;
  for (i = 0; i < (int)v_dim_u8r; i++) {
    for (j = 0; j < (int)v_dim_u8r; j++) {
      if (j == i) {
        p_InMatrix_f32r[j] = 1.0f;
      } else {
        p_InMatrix_f32r[j] = 0.0f;
      }
    }
    p_InMatrix_f32r += v_dim_u8r;
  }
  return 0;
}

char test(float *ptr){
	ptr[0] = 10;
	ptr[1] = 9;
	ptr[2] = 8;
	ptr[3] = 7;
	ptr[4];
	printf("ptr %f, %f, %f, %f, %f\n",ptr[0],ptr[1],ptr[2],ptr[3],ptr[4]);
	return 0;
}
int main()
{
	float p_InMatrix_f32r[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	unsigned char v_dim_u8r = 4;
	float ptr[5] = {1,2,3,4,5};
	printf("The original InputMatrix: \n");
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			cout<<p_InMatrix_f32r[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
	printf("The Identity_Matrix: \n");
	MATRIX_Identity(*p_InMatrix_f32r, v_dim_u8r);
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			cout<<p_InMatrix_f32r[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
	test(ptr);
}

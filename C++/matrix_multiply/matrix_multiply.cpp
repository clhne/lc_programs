#include <iostream>
using namespace std;

char MATRIX_Multiply(float *p_InMatrixA_f32r, float *p_InMatrixB_f32r, float *p_OutMatrix_f32r, unsigned char v_RowsA_u8r, unsigned char v_RowsB_u8r, unsigned char v_ColumnsB_u8r) {
  int i, j, k;
  for (i = 0; i < (int)v_RowsA_u8r; i++) {
    for (j = 0; j < (int)v_ColumnsB_u8r; j++) {
      float sum = 0.0f;
      for (k = 0; k < (int)v_RowsB_u8r; k++) {
        sum += p_InMatrixA_f32r[k] * p_InMatrixB_f32r[k * v_ColumnsB_u8r + j];
      }
      p_OutMatrix_f32r[j] = sum;
    }
    p_OutMatrix_f32r += v_ColumnsB_u8r;
    p_InMatrixA_f32r += v_RowsB_u8r;
  }
  return 0;
}

int main(){
	float p_InMatrixA_f32r[3][2] = {1,2,3,4,5,6};
	float p_InMatrixB_f32r[2][3] = {1,2,1,2,1,1};
	float p_OutMatrix_f32r[3][3] ={0};
	unsigned char v_RowsA_u8r = 3, v_RowsB_u8r = 2, v_ColumnsB_u8r = 3;
	MATRIX_Multiply(*p_InMatrixA_f32r, *p_InMatrixB_f32r, *p_OutMatrix_f32r, v_RowsA_u8r,  v_RowsB_u8r, v_ColumnsB_u8r);
	printf("InMatrixA: \n");
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 2; j++){
			cout<<p_InMatrixA_f32r[i][j]<<"\t";
		}	
    cout<<endl;		
	}
	printf("\nInMatrixB: \n");
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 3; j++){
			cout<<p_InMatrixB_f32r[i][j]<<"\t";
		}	
    cout<<endl;		
	}
	printf("\nOutMatrix: \n");
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cout<<p_OutMatrix_f32r[i][j]<<"\t";
		}	
    cout<<endl;		
	}
	cout<<endl;
	
	return 0;
}
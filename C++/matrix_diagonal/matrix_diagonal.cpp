#include <iostream>
using namespace std;

char MATRIX_Diagonal(float *p_InMatrix_f32r, float *p_OutMatrix_f32r, unsigned char v_Rows_u8r, unsigned char v_Columns_u8r) {
  int i, j;
  if (v_Rows_u8r == v_Columns_u8r) {
    for (i = 0; i < (int)v_Rows_u8r; i++) {
      *p_OutMatrix_f32r = *p_InMatrix_f32r;
      ++p_OutMatrix_f32r;
      p_InMatrix_f32r += (int)v_Rows_u8r + 1;
    }
    return 0;
  }
  if (v_Rows_u8r == 1 || v_Columns_u8r == 1) {
    if (v_Rows_u8r < v_Columns_u8r) {
      v_Rows_u8r = v_Columns_u8r;
    }
    for (i = 0; i < (int)v_Rows_u8r; i++) {
      for (j = 0; j < (int)v_Rows_u8r; j++) {
        float value = 0.0f;
        if (i == j) {
          value = *p_InMatrix_f32r;
        }
        p_OutMatrix_f32r[j] = value;
      }
      ++p_InMatrix_f32r;
      p_OutMatrix_f32r += v_Rows_u8r;
    }
  }
  return 0;
}

int main(){
	//float p_InMatrix_f32r[9][1] = {1,2,3,4,5,6,7,8,9};
	//unsigned char v_Rows_u8r = 9, v_Columns_u8r = 1;
	float p_InMatrix_f32r[1][9] = {1,2,3,4,5,6,7,8,9};
	unsigned char v_Rows_u8r = 1, v_Columns_u8r = 9;
	float p_OutMatrix_f32r[9][9] = {0};
	MATRIX_Diagonal(*p_InMatrix_f32r, *p_OutMatrix_f32r, v_Rows_u8r, v_Columns_u8r);
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cout<<p_OutMatrix_f32r[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
	
	return 0;
}
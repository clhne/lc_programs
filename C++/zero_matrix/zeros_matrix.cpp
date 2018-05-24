#include <iostream>
using namespace std;

void zeros_matrix(float *mat, int m, int n){
	int i;
	for(i = 0; i < m * n; i++){
		mat[i] = 0;
	}
}

int main()
{
	float mat[10];
	int j;
	zeros_matrix(mat, 2, 5);
	for(j = 0; j < 10; j++){
		cout<<mat[j]<<" ";
	}
	cout<<endl;
	return 0;
}
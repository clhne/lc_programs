#include <iostream>
#include <vector>
using namespace std;

#define  N (3)
#define  M (3)

void rotate_image(int **matrix, int n, int m){
	int tmp;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			tmp = matrix[j][i];
			matrix[j][i] = matrix[j][m-i-1];
			matrix[j][m-i-1] = tmp;
		}
	}
}
void rotate(vector<vector<int>>& matrix){
	const int n = matrix.size();
	for(int i = 0; i < n / 2; i++){
		for(int j = i; j < n-1; j++){
			const auto tmp = matrix[i][j];
			matrix[i][j] = matrix[n-1-j][i];
			matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
			matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
			matrix[j][n-1-i] = tmp;
		}
	}
}
int main(){
	//int matrix[N][N] = {1,2,3;4,5,6;7,8,9};
	/*
	int **matrix = new int*[M];
	for(int i = 0; i < M; i++){
		matrix[i] = new int[N];
	}
	*/
	vector<vector<int>> matrix(M,vector<int>(N));
	//matrix[0][0] = 1;
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			matrix[i][j] = 3 * i + j + 1;
		}
	}
	//rotate_image(matrix, N, M);
	rotate(matrix);
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			printf("%d, ", matrix[i][j]);
		}
		cout<<endl;
	}
	
	return 0;
}

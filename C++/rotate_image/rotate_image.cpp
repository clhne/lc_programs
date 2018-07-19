#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define  N (3)
#define  M (3)

//method 1
void rotate1(vector<vector<int>>& matrix){
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

//method 2 先转秩，再左右翻转
void rotate2(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
int main(){
 	vector<vector<int>> matrix(M,vector<int>(N));
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			matrix[i][j] = 3 * i + j + 1;
		}
	}
	//rotate1(matrix);
	rotate2(matrix);
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			printf("%d  ", matrix[i][j]);
		}
		cout<<endl;
	}
	
	return 0;
}

#include <iostream>
#include <vector>
#define ARRAY_SIZE 20
#define ROW 4
#define COL 5
using namespace std;
int main()
{
	//vector one demention array
	vector<int>::iterator it;
	vector<int> vec_array;
	for (int i = 0; i < ARRAY_SIZE; i++){
		vec_array.push_back(i+1);
	}
	
	for(it = vec_array.begin(); it != vec_array.end(); it++){
		cout<<*it<<endl;
	}
	
	//vector two demention array, method 1:
	//vector<vector<int> >matrix;
	//matrix.resize(ROW, vector<int>(COL));
	//method 2:
	//vector<vector<int> >matrix(ROW, vector<int>(COL));
	// vector<vector<int> >matrix(ROW, vector<int>(COL, -1)); //init as -1
	//method 3:
	/*
	vector<vector<int> >matrix;
	matrix.resize(ROW);
	for(int i = 0; i < ROW; ++i){
		matrix[i].resize(COL);
	}
	*/
	//method 4:
	vector<vector<int> >matrix;
	vector<int> v1;
	// use space of method 4
	for(int i = 0; i < ROW; i++){
		matrix.push_back(v1);
	}
	for(int j = 0; j < ROW; j++){
		for(int i = 0; i < COL; i++){
			matrix[j].push_back(2 * (i + 1) + j);
		}
	}
	//use space of method 1, 2, 3
	/*
	for (int j = 0; j < matrix.size(); j++){
		for (int k = 0; k < matrix[j].size(); k++){
			matrix[j][k] = 2 * (j + 1) + k;
		}
	}
	*/
	//output
	for(int j = 0; j < matrix.size(); j++){
		cout<<endl;
		for(int k = 0; k < matrix[j].size(); k++){
			cout<<matrix[j][k]<<"\t";
		}
	}
    cout<<endl;
	return 0;
}
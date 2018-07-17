#include <iostream>
#include <vector>
#define VEC_SIZE  10
using namespace std;
int main(){
	vector<int> my_vec;
	for(int i = 1; i < VEC_SIZE; i++){
		my_vec.push_back(i);
	}
	my_vec.resize(5);
	my_vec.resize(8,100);
	my_vec.resize(12);
	
	cout<<"my_vec contains:";
	for(int i = 0; i < my_vec.size(); i++){
		cout<<' '<<my_vec[i];
	}
	cout<<endl;
	
	return 0;
}
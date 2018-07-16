#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct flex{
	int count;
	double ave;
	double sco;//[];  sizeof ?
};
int main(){
	int array[] = {8, 6, 4, 9,12};
	int iter;
	//first method
	cout<<*max_element(array, array + sizeof(array)/sizeof(int)) <<endl;
	cout<<*min_element(array, array + sizeof(array)/sizeof(int)) <<endl;
	//vector method
	vector <int> v(array, array + sizeof(array)/sizeof(int));
	cout<<*max_element(v.begin(), v.end())<<endl;
	cout<<*min_element(v.begin(), v.end())<<endl;
	for(iter = 0; iter < sizeof(array)/sizeof(int); iter++){
		cout<<v[iter]<<" ";
	}

	cout<<endl;
	cout<<sizeof(struct flex)<<endl;
	return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;
long double sqrt_newton(long double x){
	long double k = x;
	if(x >= 0){
		while((k * k - x) > 1e-15){
		    k = 0.5 * ( k + x / k);
	    }
	    return k;
	}
	else{
		cout<<"input number should greater than 0 !"<<endl;
		//return k;
	}
}

int main(){
	long double x;
	while(cin>>x){
		cout<<sqrt_newton(x)<<endl;
	}
	cout<<endl;
	return 0;
}
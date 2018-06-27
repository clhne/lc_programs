#include <iostream>
using namespace std;
int main(){
	int a, b, result;
	while(!cin.eof()){
		cin>>a>>b;
		printf("^ xor: %d\n",a^b);
		printf("& xor: %d\n",a^b);
		printf("&& and: %d\n",a&&b);
	}
	
	return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int seq_list[10];
    int i,j;
    for (i = 0; i < 10; i++){
        seq_list[i] = i; 
    }
    for(j = 0;j < 10; j++){
        //cout<<seq_list[j]<<endl;
		printf("seq_list[%d]= %d\n",j,seq_list[j]);
    }
    
    return 0;
}

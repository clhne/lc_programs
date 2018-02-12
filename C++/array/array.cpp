#include <iostream>
using namespace std;
int main()
{
    int seg_list[10];
    int i,j;
    for (i = 0; i < 10; i++){
        seg_list[i] = i; 
    }
    for(j = 0;j < 10; j++){
        cout<<seg_list[j]<<endl;
    }
    
    return 0;
}

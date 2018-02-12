#include <iostream>
using namespace std;
//max(a,min(b,c))
int clip3(int a, int b, int c){
    cout<<((c < a)?a:((c > b)? b:c))<<endl;
    return 0;
}
int main()
{
    int x = 0;
    int y = 20;
    int z = 10;
    //cout<<((z < x)?x:((z > y)?y:z))<<endl;
    clip3(x,y,z);
    
    return 0;
}


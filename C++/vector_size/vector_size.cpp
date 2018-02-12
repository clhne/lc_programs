#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec;
    cout<<"0. size: "<<vec.size()<<endl;
    for(int i = 0; i < 10; i++){
        vec.push_back(i);
        cout<<"1. size: "<<vec.size()<<endl;
    }
    
    vec.insert(vec.end(),10,100);
    cout<<"2. size: "<<vec.size()<<endl;
    vec.pop_back();
    cout<<"3. size: "<<static_cast<int>(vec.size())<<endl;
    
    cout<<(2<<2)<<endl;
    cout<<(2>>1)<<endl;
    return 0;
}
#include <fstream>
using namespace std;

int main()
{
    ofstream fout;
    fout.open("test.txt");
    fout<<"test file!"<<endl;
    
    return 0;
}
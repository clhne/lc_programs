#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
 
int main()
{
    std::vector<int> v{9,2,3,5,7};
    std::reverse(std::begin(v), std::end(v));
    for(auto e : v) 
		std::cout << e;
    std::cout << '\n';
 
    int a[] = {4, 1, 9, 7};
    std::reverse(std::begin(a), std::end(a));
    for(auto e : a) 
		std::cout << e;
    std::cout<<std::endl;

    std::cin.get();
	  //system("pause");
  	return 0;
}
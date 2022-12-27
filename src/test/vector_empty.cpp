#include "vector.hpp"
#include <vector>
#include "containers.hpp"
#include <stdexcept>
#include <iostream>

using namespace NAMESPACE;

int main(void)
{
	vector<int>	myVector;
	std::cout << "Vector is empty  : [" << myVector.empty() << "]" << std::endl;
	myVector.push_back(21);
	std::cout << "Vector is not empty  : [" << myVector.empty() << "]" << std::endl;
	return (0);
}

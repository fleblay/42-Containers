#include "vector.hpp"
#include <vector>
#include "containers.hpp"
#include <stdexcept>
#include <iostream>

using namespace NAMESPACE;

int main(void)
{
	vector<int>	myVector;
	std::cout << "Vector capacity : [" << myVector.capacity() << "]" << std::endl;
	std::cout << "Pushing back a value" << std::endl;
	myVector.push_back(42);
	std::cout << "Vector capacity : [" << myVector.capacity() << "]" << std::endl;
	return (0);
}


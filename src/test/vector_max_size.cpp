#include "vector.hpp"
#include <vector>
#include "containers.hpp"
#include <stdexcept>
#include <iostream>

using namespace NAMESPACE;

int main(void)
{
	vector<int>	myVector;
	std::cout << "max size : [" << myVector.max_size() << "]" << std::endl;
	return (0);
}

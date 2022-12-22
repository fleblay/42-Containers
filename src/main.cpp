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
	try
	{
		myVector.reserve(myVector.max_size() - 1);
	}
	catch (std::exception &e)
	{
		COUT(e.what())
	}
	try
	{
		myVector.reserve(myVector.max_size() + 1);
	}
	catch (std::exception &e)
	{
		COUT(e.what())
	}
	myVector.push_back(42);
	return (0);
}

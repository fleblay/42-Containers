#include "vector.hpp"
#include <vector>
#include "containers.hpp"
#include <stdexcept>
#include <iostream>

using namespace NAMESPACE;

int main(void)
{
	vector<int>	myVector;
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
	return (0);
}

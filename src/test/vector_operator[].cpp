#include "vector.hpp"
#include <vector>
#include "containers.hpp"
#include <stdexcept>
#include <iostream>

using namespace NAMESPACE;

int main(void)
{
	vector<int>	myVector;
	const vector<int> &cRef = myVector;

	try
	{
		myVector.push_back(21);
		myVector.push_back(42);
		std::cout << "value with operator [0] : [" << myVector[0] << "]" << std::endl;
		std::cout << "value with operator [1] : [" << myVector[1] << "]" << std::endl;
		std::cout << "value with const operator [0] : [" << cRef[0] << "]" << std::endl;
		std::cout << "value with const operator [1] : [" << cRef[1] << "]" << std::endl;
	}
	catch (std::exception &e)
	{
		COUT("THIS SHOULD NOT PRINT")
		COUT(e.what())
	}
	try
	{
		std::cout << "value with operator [10] : [" << myVector[10] << "]" << std::endl;
	}
	catch (std::exception &e)
	{
		COUT(e.what())
	}
	try
	{
		std::cout << "value with operator [-2] : [" << myVector[-2] << "]" << std::endl;
	}
	catch (std::exception &e)
	{
		COUT(e.what())
	}
	try
	{
		std::cout << "value with const operator [10] : [" << cRef[10] << "]" << std::endl;
	}
	catch (std::exception &e)
	{
		COUT(e.what())
	}
	try
	{
		std::cout << "value with const operator [-2] : [" << cRef[-2] << "]" << std::endl;
	}
	catch (std::exception &e)
	{
		COUT(e.what())
	}
	return (0);
}

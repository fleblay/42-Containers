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
		myVector.push_back(21);
		myVector.push_back(42);
		std::cout << "value with operator [0] : [" << myVector[0] << "]" << std::endl;
		std::cout << "value with operator [1] : [" << myVector[1] << "]" << std::endl;
		const int value_0 = myVector[0];
		const int value_1 = myVector[1];
		std::cout << "value with const operator [0] : [" << value_0 << "]" << std::endl;
		std::cout << "value with const operator [1] : [" << value_1 << "]" << std::endl;
	}
	catch (std::exception &e)
	{
		COUT("THIS SHOULD NOT PRINT")
		COUT(e.what())
	}
	try
	{
		std::cout << "value with operator [0] : [" << myVector[10] << "]" << std::endl;
	}
	catch (std::exception &e)
	{
		COUT(e.what())
	}
	try
	{
		std::cout << "value with operator [0] : [" << myVector[-2] << "]" << std::endl;
	}
	catch (std::exception &e)
	{
		COUT(e.what())
	}
	return (0);
}

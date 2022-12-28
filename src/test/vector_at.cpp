#include "vector.hpp"
#include <vector>
#include "containers.hpp"
#include <stdexcept>
#include <iostream>

using namespace NAMESPACE;

template <typename T>
void printInfo(const vector<T> &to_print)
{
	std::cout	<< "Vector"
				<< " size : [" << to_print.size() << "]"
				<< " capacity : [" << to_print.capacity() << "]"
				<< std::endl;
}

int main(void)
{
	vector<int>	myVector;
	const vector<int> &cRef = myVector;

	try
	{
		myVector.push_back(21);
		myVector.push_back(42);
		std::cout << "value with at 0 : [" << myVector.at(0) << "]" << std::endl;
		std::cout << "value with at 1 : [" << myVector.at(1) << "]" << std::endl;
		std::cout << "value with const at 0 : [" << cRef.at(0) << "]" << std::endl;
		std::cout << "value with const at 1 : [" << cRef.at(1) << "]" << std::endl;
	}
	catch (std::exception &e)
	{
		COUT("THIS SHOULD NOT PRINT")
		COUT(e.what())
	}
	try
	{
		std::cout << "value with at 10 : [" << myVector.at(10) << "]" << std::endl;
	}
	catch (std::exception &e)
	{
		COUT(e.what())
	}
	try
	{
		std::cout << "value with at -2 : [" << myVector.at(-2) << "]" << std::endl;
	}
	catch (std::exception &e)
	{
		COUT(e.what())
	}
	try
	{
		std::cout << "const value with at 10 : [" << cRef.at(10) << "]" << std::endl;
	}
	catch (std::exception &e)
	{
		COUT(e.what())
	}
	try
	{
		std::cout << "const value with at -2 : [" << cRef.at(-2) << "]" << std::endl;
	}
	catch (std::exception &e)
	{
		COUT(e.what())
	}
	return (0);
}

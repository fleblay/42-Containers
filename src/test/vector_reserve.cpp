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
	try
	{
		myVector.reserve(-1);
	}
	catch (std::exception &e)
	{
		COUT(e.what())
	}
	try
	{
		printInfo(myVector);
		std::cout << "Reserve 5" << std::endl;
		myVector.reserve(5);
		printInfo(myVector);
		std::cout << "Reserve 6" << std::endl;
		myVector.reserve(6);
		printInfo(myVector);
		std::cout << "Reserve 100" << std::endl;
		myVector.reserve(100);
		printInfo(myVector);
		std::cout << "Reserve 120" << std::endl;
		myVector.reserve(120);
		printInfo(myVector);
	}
	catch (std::exception &e)
	{
		COUT("THIS SHOULD NOT PRINT")
		COUT(e.what())
	}
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

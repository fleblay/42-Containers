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
	try
	{
	vector<int>	myVector;
	myVector.push_back(11);
	printInfo(myVector);
	myVector.push_back(21);
	printInfo(myVector);
	myVector.push_back(42);
	printInfo(myVector);
	myVector.push_back(84);
	printInfo(myVector);
	myVector.push_back(0);
	printInfo(myVector);
	myVector.push_back(-10);
	printInfo(myVector);

	COUT(myVector[0])
	COUT(myVector[1])
	COUT(myVector[2])
	COUT(myVector[3])
	COUT(myVector[4])
	COUT(myVector[5])
	}
	catch (std::exception &e)
	{
		COUT("THIS SHOULD NOT PRINT")
		COUT(e.what())
	}
	return (0);
}

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
	myVector.push_back(11);
	myVector.push_back(21);
	myVector.push_back(42);
	myVector.push_back(84);
	myVector.push_back(0);
	myVector.push_back(-10);

	COUT("--------------------------")
	for (unsigned long i = 0; i < myVector.size(); i++)
		COUT(myVector[i])
	printInfo(myVector);
	myVector.resize(4);
	COUT("--------------------------")
	for (unsigned long i = 0; i < myVector.size(); i++)
		COUT(myVector[i])
	printInfo(myVector);
	myVector.resize(10, 666);
	COUT("--------------------------")
	for (unsigned long i = 0; i < myVector.size(); i++)
		COUT(myVector[i])
	printInfo(myVector);
	myVector.resize(12);
	COUT("--------------------------")
	for (unsigned long i = 0; i < myVector.size(); i++)
		COUT(myVector[i])
	printInfo(myVector);
	COUT("--------------------------")
	return (0);
}

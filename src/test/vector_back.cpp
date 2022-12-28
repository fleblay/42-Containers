#include "vector.hpp"
#include <vector>
#include "containers.hpp"
#include <stdexcept>
#include <iostream>
#include <csignal>
#include <cstdlib>

void	signal_handler(int signal_number)
{
	std::cout << "A signal has been trapped [" << signal_number << "]" << std::endl;
	exit(2);
}

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
	signal(SIGSEGV, signal_handler);

	vector<int>	myVector;
	vector<int>	myEmptyVector;
	const vector<int> &cRef = myVector;

	std::cout << "Pushing back a value" << std::endl;
	myVector.push_back(42);
	std::cout << "back on vector : [" << myVector.back() << "]" << std::endl;
	std::cout << "Pushing back a value" << std::endl;
	myVector.push_back(84);
	std::cout << "back on vector : [" << myVector.back() << "]" << std::endl;
	std::cout << "const back on vector : [" << cRef.back() << "]" << std::endl;

	try
	{
		std::cout << "back on empty vector" << std::endl;
		int result = myEmptyVector.back();
		std::cout << result << std::endl;
	}
	catch (std::exception &e)
	{
		COUT("THIS SHOULD NOT PRINT : segfault expected")
	}
	return (0);
}

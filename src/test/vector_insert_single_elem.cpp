#include "vector.hpp"
#include <vector>
#include "containers.hpp"
#include <stdexcept>
#include <iostream>
#include <csignal>
#include <cstdlib>
#include "is_integral.hpp"
#include "enable_if.hpp"
#include <iterator>
#include <sstream>

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

	vector<int>		myvect;
	for (int i = 0; i < 11; i++)
		myvect.push_back(i * 10);

	std::cout << "[" << *myvect.insert(myvect.begin() + 1, 42) << std::endl;
	printInfo(myvect);
	for (vector<int>::iterator it = myvect.begin(); it != myvect.end(); it++)
		std::cout << "myvect : [" << *it << "]" << std::endl;

	std::cout << "----" << std::endl;

	std::cout << "[" << *myvect.insert(myvect.begin(), 21) << std::endl;
	printInfo(myvect);
	for (vector<int>::iterator it = myvect.begin(); it != myvect.end(); it++)
		std::cout << "myvect : [" << *it << "]" << std::endl;

	std::cout << "----" << std::endl;

	std::cout << "[" << *myvect.insert(myvect.end(), 84) << std::endl;
	printInfo(myvect);
	for (vector<int>::iterator it = myvect.begin(); it != myvect.end(); it++)
		std::cout << "myvect : [" << *it << "]" << std::endl;

	std::cout << "[" << *myvect.insert(myvect.begin() + 6, 168) << std::endl;
	printInfo(myvect);
	for (vector<int>::iterator it = myvect.begin(); it != myvect.end(); it++)
		std::cout << "myvect : [" << *it << "]" << std::endl;
}

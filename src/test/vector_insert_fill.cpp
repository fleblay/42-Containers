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
	for (int i = 0; i < 10; i++)
		myvect.push_back(i * 10);

	myvect.insert(myvect.begin() + 1, 3, 42);
	printInfo(myvect);
	for (vector<int>::iterator it = myvect.begin(); it != myvect.end(); it++)
		std::cout << "myvect : [" << *it << "]" << std::endl;

	std::cout << "----" << std::endl;

	myvect.insert(myvect.begin(), 4, 21);
	printInfo(myvect);
	for (vector<int>::iterator it = myvect.begin(); it != myvect.end(); it++)
		std::cout << "myvect : [" << *it << "]" << std::endl;

	std::cout << "----" << std::endl;

	myvect.insert(myvect.end(), 6, 84);
	printInfo(myvect);
	for (vector<int>::iterator it = myvect.begin(); it != myvect.end(); it++)
		std::cout << "myvect : [" << *it << "]" << std::endl;

	myvect.insert(myvect.begin() + 6, 8, 168);
	printInfo(myvect);
	for (vector<int>::iterator it = myvect.begin(); it != myvect.end(); it++)
		std::cout << "myvect : [" << *it << "]" << std::endl;
}

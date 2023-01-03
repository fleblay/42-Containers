#include "vector.hpp"
#include <vector>
#include "containers.hpp"
#include <stdexcept>
#include <iostream>
#include <csignal>
#include <cstdlib>
#include "is_integral.hpp"
#include "enable_if.hpp"

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

	vector<int>	myvect;
	myvect.assign(4, 42);
	vector<int>::iterator	it = myvect.begin();
	vector<int>::iterator	ite = myvect.end();

	printInfo(myvect);
	for (; it != ite; it++)
		std::cout << "myvect : [" << *it << "]" << std::endl;

	//Next test

	vector<int>	myvect2;
	for (int i = 0; i < 4; i++)
		myvect2.push_back(i);
	myvect2.assign(10, 21);
	vector<int>::iterator	it2 = myvect2.begin();
	vector<int>::iterator	ite2 = myvect2.end();

	printInfo(myvect2);
	for (; it2 != ite2; it2++)
		std::cout << "myvect2 : [" << *it2 << "]" << std::endl;

	//Next test

	vector<int>	myvect3;
	for (int i = 0; i < 20; i++)
		myvect3.push_back(i);
	myvect3.assign(3, 84);
	vector<int>::iterator	it3 = myvect3.begin();
	vector<int>::iterator	ite3 = myvect3.end();

	printInfo(myvect3);
	for (; it3 != ite3; it3++)
		std::cout << "myvect : [" << *it3 << "]" << std::endl;

	//Test bad alloc
	try
	{
		myvect3.assign(myvect3.max_size(), 2);

	}
	catch (std::exception &e)
	{
		COUT(e.what())
	}
	//Test vector in valid state after throw
	printInfo(myvect3);
	for (; it3 != ite3; it3++)
		std::cout << "myvect : [" << *it3 << "]" << std::endl;
}

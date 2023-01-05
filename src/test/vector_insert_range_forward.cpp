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

	vector<int>	myvect;
	vector<int>	myvect2;

	myvect2.push_back(-12);
	for (int i = 20; i < 30; i++)
	{
		myvect.push_back(i);
		myvect2.push_back(i * 10);
	}
	myvect2.insert(myvect2.begin() + 3, myvect.begin() + 2, myvect.begin() + 8);

	printInfo(myvect2);
	for (vector<int>::iterator it = myvect2.begin(); it != myvect2.end(); it++)
		std::cout << "myvect2 value [" << *it << "]" << std::endl;

	//Next tests
	vector<int>		myvect3;
	vector<int>		myvect4;

	for (int i = 0; i < 10; i++)
	{
		myvect4.push_back(i);
		myvect3.push_back(i * 10);
	}

	myvect3.insert(myvect3.begin() + 1, myvect4.begin() + 2, myvect4.begin() + 3);
	printInfo(myvect3);
	for (vector<int>::iterator it = myvect3.begin(); it != myvect3.end(); it++)
		std::cout << "myvect3 : [" << *it << "]" << std::endl;

	std::cout << "----" << std::endl;

	myvect3.insert(myvect3.begin() + 1, myvect4.begin(), myvect4.begin() + 6);
	printInfo(myvect3);
	for (vector<int>::iterator it = myvect3.begin(); it != myvect3.end(); it++)
		std::cout << "myvect3 : [" << *it << "]" << std::endl;

	std::cout << "----" << std::endl;

	myvect3.insert(myvect3.begin() + 1, myvect4.begin() + 8, myvect4.end());
	printInfo(myvect3);
	for (vector<int>::iterator it = myvect3.begin(); it != myvect3.end(); it++)
		std::cout << "myvect3 : [" << *it << "]" << std::endl;

	std::cout << "----" << std::endl;

	myvect3.insert(myvect3.end(), myvect4.begin(), myvect4.end());
	printInfo(myvect3);
	for (vector<int>::iterator it = myvect3.begin(); it != myvect3.end(); it++)
		std::cout << "myvect3 : [" << *it << "]" << std::endl;
}

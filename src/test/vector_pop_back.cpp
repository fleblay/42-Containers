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

	for (int i = 0; i < 12; i++)
		myvect.push_back(i * 2);

	for (int i = 1; i <= 3; i++)
	{
		for (int j = 0; j <= i; j++)
			myvect.pop_back();
		for (vector<int>::size_type j = 0; j < myvect.size(); j++)
			std::cout << "vect : [" << myvect[j] << "]" << std::endl;
		printInfo(myvect);
	}
	for (vector<int>::size_type j = 0; j < myvect.size(); j++)
		std::cout << "vect : [" << myvect[j] << "]" << std::endl;
	printInfo(myvect);
	for (vector<int>::size_type i = 0; i <= myvect.size() + 2; i++)
	{
		myvect.pop_back();
		printInfo(myvect);
	}
}

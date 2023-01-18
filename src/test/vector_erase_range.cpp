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

	for (int i = 0; i < 21; i++)
		myvect.push_back(i);

	std::cout << "next value : [" << *myvect.erase(myvect.begin() + 2, myvect.begin() + 4) << "]" << std::endl;
	for (vector<int>::size_type i = 0; i < myvect.size(); i++)
		std::cout << "value : [" << myvect[i] << "]" << std::endl;
	printInfo(myvect);
	std::cout << "----------------------" << std::endl;

	std::cout << "next value : [" << *myvect.erase(myvect.begin(), myvect.begin() + 3) << "]" << std::endl;
	for (vector<int>::size_type i = 0; i < myvect.size(); i++)
		std::cout << "value : [" << myvect[i] << "]" << std::endl;
	printInfo(myvect);
	std::cout << "----------------------" << std::endl;

	std::cout << "next value is end ? : [" << (*myvect.erase(myvect.begin() + 6, myvect.end()) == *myvect.end()) << "]" << std::endl;
	for (vector<int>::size_type i = 0; i < myvect.size(); i++)
		std::cout << "value : [" << myvect[i] << "]" << std::endl;
	printInfo(myvect);
	std::cout << "----------------------" << std::endl;
}

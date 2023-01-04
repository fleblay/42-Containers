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
	vector<int>	myvect2;

	myvect2.push_back(-12);
	for (int i = 20; i < 30; i++)
		myvect.push_back(i);
	myvect2.assign(myvect.begin() + 1, myvect.begin() + 8);

	printInfo(myvect2);
	for (vector<int>::iterator it = myvect2.begin(); it != myvect2.end(); it++)
		std::cout << "myvect2 value [" << *it << "]" << std::endl;

}

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

	for (int i = 0; i < 11; i++)
		myvect.push_back(i);
	for (int i = 3; i < 20; i++)
		myvect2.push_back(i * 2);

	myvect.clear();
	printInfo(myvect);
	myvect2.clear();
	printInfo(myvect2);
}

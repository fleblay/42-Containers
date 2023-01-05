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
#include "lexicographical_compare.hpp"

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

bool comparator (int c1, int c2)
{
	return (c1 < c2);
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

	vector<int>::iterator it1 = myvect.begin();
	vector<int>::iterator it2 = myvect2.begin();
	vector<int>::iterator ite1 = myvect.end();
	vector<int>::iterator ite2 = myvect2.end();

	swap(myvect2, myvect);

	for (vector<int>::size_type i = 0; i < myvect.size(); i++)
		std::cout << "value : [" << myvect[i] << "]" << std::endl;
	printInfo(myvect);
	std::cout << "----------------------" << std::endl;

	myvect.push_back(48);

	for (vector<int>::size_type i = 0; i < myvect2.size(); i++)
		std::cout << "value : [" << myvect2[i] << "]" << std::endl;
	printInfo(myvect2);
	std::cout << "----------------------" << std::endl;

	for (; it1 != ite1; it1 ++)
		std::cout << "value : [" << *it1 << "]" << std::endl;
	std::cout << "----------------------" << std::endl;

	for (; it2 != ite2; it2 ++)
		std::cout << "value : [" << *it2 << "]" << std::endl;
	std::cout << "----------------------" << std::endl;
}

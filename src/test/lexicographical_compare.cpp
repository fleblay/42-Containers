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
	for (int i = 0; i < 20; i++)
		myvect2.push_back(i);

	std::cout	<< "Lexico compare default : ["
				<< lexicographical_compare(myvect.begin(), myvect.end(), myvect2.begin(), myvect2.end())
				<< "]" << std::endl;

	std::cout	<< "Lexico compare custom : ["
				<< lexicographical_compare(myvect.begin(), myvect.end(), myvect2.begin(), myvect2.end(), comparator)
				<< "]" << std::endl;

	//Reverse
	std::cout	<< "Lexico compare default : ["
				<< lexicographical_compare(myvect2.begin(), myvect2.end(), myvect.begin(), myvect.end())
				<< "]" << std::endl;

	std::cout	<< "Lexico compare custom : ["
				<< lexicographical_compare(myvect2.begin(), myvect2.end(), myvect.begin(), myvect.end(), comparator)
				<< "]" << std::endl;
}

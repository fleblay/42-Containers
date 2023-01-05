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

	vector<int>	myvect(4, 42);
	myvect.push_back(-12);

	for (vector<int>::size_type i = 0; i < myvect.size(); i++)
		std::cout << "value : [" << myvect[i] << "]" << std::endl;
	printInfo(myvect);
	std::cout << "----------------------" << std::endl;

	vector<int>	myvect2(myvect.begin() + 1, myvect.end());
	myvect2.push_back(48);

	for (vector<int>::size_type i = 0; i < myvect2.size(); i++)
		std::cout << "value : [" << myvect2[i] << "]" << std::endl;
	printInfo(myvect2);
	std::cout << "----------------------" << std::endl;

	std::stringstream	text;
	text	<< "1238" << std::endl
			<< "323" << std::endl
			<< "666" << std::endl
			<< "-24" << std::endl;

	std::istream_iterator<int> iit (text);
	std::istream_iterator<int> eos;

	vector<int>	myvect3(iit, eos);

	for (vector<int>::size_type i = 0; i < myvect3.size(); i++)
		std::cout << "value : [" << myvect3[i] << "]" << std::endl;
	printInfo(myvect3);
	std::cout << "----------------------" << std::endl;

	vector<int>	myvect4(myvect2);
	for (vector<int>::size_type i = 0; i < myvect4.size(); i++)
		std::cout << "value : [" << myvect4[i] << "]" << std::endl;
	printInfo(myvect4);
	std::cout << "----------------------" << std::endl;

	//Testing if allocator is fine
	myvect4.push_back(999);
	for (vector<int>::size_type i = 0; i < myvect4.size(); i++)
		std::cout << "value : [" << myvect4[i] << "]" << std::endl;
	printInfo(myvect4);
	std::cout << "----------------------" << std::endl;
}

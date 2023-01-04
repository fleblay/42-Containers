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

	//1 value;
	std::stringstream	text;
	text	<< "42" << std::endl;

	std::istream_iterator<int> iit (text);
	std::istream_iterator<int> eos;

	vector<int>	myvect;
	myvect.push_back(-12);
	myvect.assign(iit, eos);

	for (vector<int>::size_type i = 0; i < myvect.size(); i++)
		std::cout << "value : [" << myvect[i] << "]" << std::endl;
	printInfo(myvect);

	//3 value;
	std::stringstream	text_2;
	text_2	<< "42" << std::endl
			<< "21" << std::endl
			<< "84" << std::endl;

	std::istream_iterator<int> iit_2 (text_2);

	vector<int>	myvect_2;
	myvect_2.push_back(-12);
	myvect_2.assign(iit_2, eos);

	for (vector<int>::size_type i = 0; i < myvect_2.size(); i++)
		std::cout << "value : [" << myvect_2[i] << "]" << std::endl;
	printInfo(myvect_2);

	//10 value;
	std::stringstream	text_3;
	text_3	<< "42" << std::endl
			<< "212" << std::endl
			<< "214" << std::endl
			<< "218" << std::endl
			<< "211" << std::endl
			<< "321" << std::endl
			<< "821" << std::endl
			<< "921" << std::endl
			<< "84" << std::endl;

	std::istream_iterator<int> iit_3 (text_3);

	vector<int>	myvect_3;
	myvect_3.push_back(-12);
	myvect_3.assign(iit_3, eos);

	for (vector<int>::size_type i = 0; i < myvect_3.size(); i++)
		std::cout << "value : [" << myvect_3[i] << "]" << std::endl;
	printInfo(myvect_3);
}

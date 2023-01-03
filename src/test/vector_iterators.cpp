#include "vector.hpp"
#include <vector>
#include "containers.hpp"
#include <stdexcept>
#include <iostream>
#include <csignal>
#include <cstdlib>

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
struct myStruct
{
	int a;
};

int main(void)
{
	signal(SIGSEGV, signal_handler);

	//Simple Iterator Test, * and ->
	vector<int>::iterator it_0;
	int a = 12;
	vector<int>::iterator it_1(&a);
	it_0 = it_1;
	std::cout << *it_0 << std::endl;
	struct myStruct test;
	test.a = 28;
	vector<struct myStruct>::iterator	it_struct(&test);
	std::cout << it_struct->a << std::endl;

	//Using begin and end to test simple use case operators
	vector<int>	myvector;

	for (int i = 0; i <= 10; i++)
		myvector.push_back(i);
	vector<int>::iterator	it = myvector.begin();
	vector<int>::iterator	ite = myvector.end();

	for (; it != ite; it++)
		std::cout << "vector value : [" << *it << "]" << std::endl;

	//Testing iterator member functions (overload of operators)
	vector<int>::iterator	it2 = myvector.begin() + 4;
	std::cout << "vector value : [" << (*it2++) << "]" << std::endl;
	std::cout << "vector value : [" << *it2 << "]" << std::endl;
	std::cout << "vector value : [" << *(it2--) << "]" << std::endl;
	std::cout << "vector value : [" << *(++it2) << "]" << std::endl;
	std::cout << "vector value : [" << *(--it2) << "]" << std::endl;
	std::cout << "vector value : [" << *(it2 + 3) << "]" << std::endl;
	std::cout << "vector value : [" << *(it2 += 3) << "]" << std::endl;
	std::cout << "vector value : [" << *(it2 - 2) << "]" << std::endl;
	std::cout << "vector value : [" << *(it2 -= 1) << "]" << std::endl;
	std::cout << "vector value : [" << it2[3] << "]" << std::endl;
	std::cout << "diff value : [" << it2 - it << "]" << std::endl;
	std::cout << "vector value : [" << *(3 + it2) << "]" << std::endl;

	//Testing iterator comparisons
	if (it == it2)
		std::cout << "same" << std::endl;
	if (it != it2)
		std::cout << "diff" << std::endl;
	if (it >= it2)
		std::cout << "ge" << std::endl;
	if (it <= it2)
		std::cout << "le" << std::endl;
	if (it > it2)
		std::cout << "gt" << std::endl;
	if (it < it2)
		std::cout << "lt" << std::endl;

	it = myvector.begin();
	
	if (it == it2)
		std::cout << "same" << std::endl;
	if (it != it2)
		std::cout << "diff" << std::endl;
	if (it >= it2)
		std::cout << "ge" << std::endl;
	if (it <= it2)
		std::cout << "le" << std::endl;
	if (it > it2)
		std::cout << "gt" << std::endl;
	if (it < it2)
		std::cout << "lt" << std::endl;

	//Testing const iterators
	const vector<int>				myconstvector;
	vector<int>::const_iterator		cit = myconstvector.begin();
	cit++;
	vector<int>::const_iterator		cend = myconstvector.end();
	cend--;

	vector<int>::const_iterator		cit2;
	cit2 = myvector.begin();
	cit2++;
	std::cout << "const vector value : [" << *cit2 << "]" << std::endl;

	//Testing const iterators construction from non-const iterator
	vector<int>::const_iterator		cit3 = myvector.begin();
	cit3++;
	vector<int>::const_iterator		cit4 = myvector.end();
	cit4--;

	//Testing comparison of const and non-const iterator
	if (cit == it2)
		std::cout << "same" << std::endl;
	if (cit != it2)
		std::cout << "diff" << std::endl;
	if (cit >= it2)
		std::cout << "ge" << std::endl;
	if (cit <= it2)
		std::cout << "le" << std::endl;
	if (cit > it2)
		std::cout << "gt" << std::endl;
	if (cit < it2)
		std::cout << "lt" << std::endl;
}

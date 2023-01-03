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

	//Simple reverse_iterator Test, * and ->
 //	vector<int>::reverse_iterator rit_0;
 //	int a = 12;
 //	vector<int>::iterator it_1(&a);
 //	vector<int>::reverse_iterator rit_1(it_1);
 //	rit_0 = rit_1;
 //	std::cout << *rit_0 << std::endl;
 //	struct myStruct test;
 //	test.a = 28;
 //	vector<struct myStruct>::iterator	it_struct(&test);
 //	vector<struct myStruct>::reverse_iterator	rit_struct(it_struct);
 //	std::cout << rit_struct->a << std::endl;

	//Using rbegin and end to test simple use case operators
	vector<int>	myvector;

	for (int i = 0; i <= 10; i++)
		myvector.push_back(i);
	vector<int>::reverse_iterator	it = myvector.rbegin();
	vector<int>::reverse_iterator	ite = myvector.rend();

	for (; it != ite; it++)
		std::cout << "vector value : [" << *it << "]" << std::endl;

	//Testing reverse_iterator member functions (overload of operators)
	vector<int>::reverse_iterator	it2 = myvector.rbegin() + 4;
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

	//Testing reverse_iterator comparisons
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

	it = myvector.rbegin();
	
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

	//Testing const reverse_iterators
	const vector<int>				myconstvector;
	vector<int>::const_reverse_iterator		cit = myconstvector.rbegin();
	cit++;
	vector<int>::const_reverse_iterator		crend = myconstvector.rend();
	crend--;

	vector<int>::const_reverse_iterator		cit2;
	cit2 = myvector.rbegin();
	cit2++;
	std::cout << "const vector value : [" << *cit2 << "]" << std::endl;

	//Testing const reverse_iterators construction from non-const reverse_iterator
	vector<int>::const_reverse_iterator		cit3 = myvector.rbegin();
	cit3++;
	vector<int>::const_reverse_iterator		cit4 = myvector.rend();
	cit4--;

	//Testing comparison of const and non-const reverse_iterator
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

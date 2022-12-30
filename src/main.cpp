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

	vector<int>::iterator it_0;
	int a = 12;
	vector<int>::iterator it_1(&a);
	it_0 = it_1;
	std::cout << *it_0 << std::endl;
	struct myStruct test;
	test.a = 28;
	vector<struct myStruct>::iterator	it_struct(&test);
	std::cout << it_struct->a << std::endl;
}

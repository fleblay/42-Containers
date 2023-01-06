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

#include <string>
int main(void)
{
	signal(SIGSEGV, signal_handler);

	vector<std::string>	v1;
	v1.push_back("numero 1");
	v1.push_back("numero 2");
	v1.push_back("numero 3");

	vector<std::string> v2;
	v2.push_back("Init");
	vector<std::string>::iterator it1 = v2.begin() + 1;

	v2.insert(it1, v1.begin(), v1.end());

	for (vector<std::string>::iterator it = v2.begin(); it != v2.end(); it++)
		std::cout << *it << std::endl;
}

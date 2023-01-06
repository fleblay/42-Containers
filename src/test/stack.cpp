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
#include "stack.hpp"
#include <stack>

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

	stack<int> s1;
	stack<int> s2;

	for (int i = 1; i < 10 ; i++)
		s2.push(i);

	std::cout << s1.empty() << std::endl;

	s1.push(44);
	s1.push(28);
	s1.push(6);
	s1.push(-2);

	s1.pop();

	std::cout << s1.empty() << std::endl;
	std::cout << s1.size() << std::endl;
	std::cout << s1.top() << std::endl;

	std::cout << (s1 < s2) << std::endl;
	std::cout << (s1 > s2) << std::endl;
	std::cout << (s1 == s2) << std::endl;
	std::cout << (s1 != s2) << std::endl;
	std::cout << (s1 <= s2) << std::endl;
	std::cout << (s1 >= s2) << std::endl;
}

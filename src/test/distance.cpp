#include "vector.hpp"
#include <vector>
#include "containers.hpp"
#include <stdexcept>
#include <iostream>
#include <csignal>
#include <cstdlib>
#include "is_integral.hpp"
#include "enable_if.hpp"

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

	//Forward (or better) Iterator

	for (int i = 0; i <= 10; i++)
		myvect.push_back(i);
	vector<int>::difference_type dist = ::distance(myvect.begin(), myvect.end());
	std::cout << "Distance : " << dist <<  std::endl;

	//Input Iterator
	std::stringstream	text;
	text	<< "42" << std::endl
			<< "84" << std::endl
			<< "21" << std::endl;

	std::istream_iterator<int> iit (text);
	std::istream_iterator<int> eos;

	vector<int>::difference_type dist2 = ::distance(iit, eos);
	std::cout << "Distance 2: " << dist2 << std::endl;
}

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

	std::stringstream	text;
	text	<< "42" << std::endl
			<< "84" << std::endl
			<< "21" << std::endl;

	std::stringstream	textCopy;
	textCopy	<< "42" << std::endl
				<< "84" << std::endl
				<< "21" << std::endl;

	//std::istream_iterator<int> iit (std::cin);
	std::istream_iterator<int> iit (text);
	std::istream_iterator<int> iit2 (textCopy);
	std::istream_iterator<int> eos;

	while (iit != eos)
	{
		std::cout << "value : [" << *iit << "]" << std::endl;
		iit++;
	}
	vector<int>	myvect;
	//myvect.assign(iit2, eos);
	// assign et verifier le contenu de myvect;
}

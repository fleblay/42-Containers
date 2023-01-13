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

template<typename T>
//Si T n'est pas integral, la fonction sera definie comme make_vector<T>(NOTYPE size), ce qui ne veut
//rien dire
void	make_vector(typename enable_if<is_integral<T>::value, int >::type size)
{
	std::cout << "T is integral" << std::endl;
	vector<int>	myvector;
	for (int i = 0; i < size; i++)
		myvector.push_back(i);
}

template<typename T>
void	make_vector(typename enable_if<!is_integral<T>::value, int >::type size)
{
	std::cout << "T is not integral" << std::endl;
	vector<int>	myvector;
	for (int i = 0; i < size * 2; i++)
		myvector.push_back(i);
}

int main(void)
{
	signal(SIGSEGV, signal_handler);

	make_vector<float>(3);
	make_vector<int>(3);
}

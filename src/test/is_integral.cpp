#include "vector.hpp"
#include <vector>
#include "containers.hpp"
#include <stdexcept>
#include <iostream>
#include <csignal>
#include <cstdlib>
#include "is_integral.hpp"

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


	std::cout << "char : " << is_integral<char>::value << std::endl;
	std::cout << "bool " << is_integral<bool>::value << std::endl;
	std::cout << "char " << is_integral<char>::value << std::endl;
	//std::cout << "char16_t " << is_integral<char16_t>::value << std::endl;
	//std::cout << "char32_t " << is_integral<char32_t>::value << std::endl;
	std::cout << "wchar_t " << is_integral<wchar_t>::value << std::endl;
	std::cout << "signed char " << is_integral<signed char>::value << std::endl;
	std::cout << "short int " << is_integral<short int>::value << std::endl;
	std::cout << "int " << is_integral<int>::value << std::endl;
	std::cout << "long int " << is_integral<long int>::value << std::endl;
	std::cout << "long long int " << is_integral<long long int>::value << std::endl;
	std::cout << "unsigned char " << is_integral<unsigned char>::value << std::endl;
	std::cout << "unsigned short int " << is_integral<unsigned short int>::value << std::endl;
	std::cout << "unsigned int " << is_integral<unsigned int>::value << std::endl;
	std::cout << "unsigned long int " << is_integral<unsigned long int>::value << std::endl;
	std::cout << "unsigned long long int " << is_integral<unsigned long long int>::value << std::endl;
	std::cout << "float : " << is_integral<float>::value << std::endl;
	std::cout << "double : " << is_integral<double>::value << std::endl;

	std::cout << "char : " << is_integral<char>() << std::endl;
	std::cout << "bool " << is_integral<bool>() << std::endl;
	std::cout << "char " << is_integral<char>() << std::endl;
	//std::cout << "char16_t " << is_integral<char16_t>() << std::endl;
	//std::cout << "char32_t " << is_integral<char32_t>() << std::endl;
	std::cout << "wchar_t " << is_integral<wchar_t>() << std::endl;
	std::cout << "signed char " << is_integral<signed char>() << std::endl;
	std::cout << "short int " << is_integral<short int>() << std::endl;
	std::cout << "int " << is_integral<int>() << std::endl;
	std::cout << "long int " << is_integral<long int>() << std::endl;
	std::cout << "long long int " << is_integral<long long int>() << std::endl;
	std::cout << "unsigned char " << is_integral<unsigned char>() << std::endl;
	std::cout << "unsigned short int " << is_integral<unsigned short int>() << std::endl;
	std::cout << "unsigned int " << is_integral<unsigned int>() << std::endl;
	std::cout << "unsigned long int " << is_integral<unsigned long int>() << std::endl;
	std::cout << "unsigned long long int " << is_integral<unsigned long long int>() << std::endl;
	std::cout << "float : " << is_integral<float>() << std::endl;
	std::cout << "double : " << is_integral<double>() << std::endl;
}

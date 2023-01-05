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

int main(void)
{
	signal(SIGSEGV, signal_handler);


	vector<int>	myvect;
	vector<int>	myvect2;

	for (int i = 0; i < 4; i++)
		myvect.push_back(i);
	for (int i = 0; i < 6; i++)
	{
		if (i != 3)
			myvect2.push_back(i);
		else
			myvect2.push_back(i - 2);
	}
	vector<int> myvect3(myvect);

	std::cout << "== : " << std::endl;
	std::cout << (myvect == myvect2) << std::endl;
	std::cout << (myvect == myvect3) << std::endl;
	std::cout << (myvect2 == myvect3) << std::endl;
	std::cout << "------------------" << std::endl;

	std::cout << "< : " << std::endl;
	std::cout << (myvect < myvect2) << std::endl;
	std::cout << (myvect < myvect3) << std::endl;
	std::cout << (myvect2 < myvect3) << std::endl;
	std::cout << "------------------" << std::endl;

	std::cout << "> : " << std::endl;
	std::cout << (myvect > myvect2) << std::endl;
	std::cout << (myvect > myvect3) << std::endl;
	std::cout << (myvect2 > myvect3) << std::endl;
	std::cout << "------------------" << std::endl;

	std::cout << "!= : " << std::endl;
	std::cout << (myvect != myvect2) << std::endl;
	std::cout << (myvect != myvect3) << std::endl;
	std::cout << (myvect2 != myvect3) << std::endl;
	std::cout << "------------------" << std::endl;

	std::cout << ">= : " << std::endl;
	std::cout << (myvect >= myvect2) << std::endl;
	std::cout << (myvect >= myvect3) << std::endl;
	std::cout << (myvect2 >= myvect3) << std::endl;
	std::cout << "------------------" << std::endl;

	std::cout << "<= : " << std::endl;
	std::cout << (myvect <= myvect2) << std::endl;
	std::cout << (myvect <= myvect3) << std::endl;
	std::cout << (myvect2 <= myvect3) << std::endl;
	std::cout << "------------------" << std::endl;
}

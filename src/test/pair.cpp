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
#include "rbtree.hpp"
#include "pair.hpp"

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

	pair<int, char>	p1;
	pair<long, int>	p2(p1);

	pair<long, int>	p3(1L, 43);
	pair<int, char>	p4;
	p4 = p1;

	pair<long, int>	p5(2L, 43);
	pair<long, int>	p6(3L, 22);
	pair<long, int>	p7(p5);

	pair<long, int>	p8 = make_pair<long, int>(8L, 21);

	std::cout << p8 << std::endl;

	std::cout << "--------------------" << std::endl;
	std::cout << (p5 > p6) << std::endl;
	std::cout << (p5 < p6) << std::endl;
	std::cout << (p5 == p6) << std::endl;
	std::cout << (p5 != p6) << std::endl;
	std::cout << (p5 >= p6) << std::endl;
	std::cout << (p5 <= p6) << std::endl;

	std::cout << "--------------------" << std::endl;
	std::cout << (p3 > p6) << std::endl;
	std::cout << (p3 < p6) << std::endl;
	std::cout << (p3 == p6) << std::endl;
	std::cout << (p3 != p6) << std::endl;
	std::cout << (p3 >= p6) << std::endl;
	std::cout << (p3 <= p6) << std::endl;

	std::cout << "--------------------" << std::endl;
	std::cout << (p5 > p7) << std::endl;
	std::cout << (p5 < p7) << std::endl;
	std::cout << (p5 == p7) << std::endl;
	std::cout << (p5 != p7) << std::endl;
	std::cout << (p5 >= p7) << std::endl;
	std::cout << (p5 <= p7) << std::endl;
	std::cout << "--------------------" << std::endl;
}

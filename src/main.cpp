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
	//Test Right uncle is RED
	rbtree<int> tree;

	tree.insert(5);
	tree.insert(3);
	tree.insert(10);
	tree.insert(2);

	std::cout << "----------" << std::endl;
	tree.print();

	//Test Left uncle is RED
	rbtree<int> tree2;

	tree2.insert(5);
	tree2.insert(3);
	tree2.insert(10);
	tree2.insert(12);

	std::cout << "----------" << std::endl;
	tree2.print();

	//Test right right 
	rbtree<int> tree3;

	tree3.insert(5);
	tree3.insert(3);
	tree3.insert(10);
	tree3.insert(12);
	tree3.insert(13);

	std::cout << "----------" << std::endl;
	tree3.print();

	//Test right left 
	rbtree<int> tree4;

	tree4.insert(5);
	tree4.insert(3);
	tree4.insert(10);
	tree4.insert(12);
	tree4.insert(11);

	std::cout << "----------" << std::endl;
	tree4.print();

	//Test Multiple 
	rbtree<int> tree5;
	tree5.insert(5);
	tree5.insert(3);
	tree5.insert(10);
	tree5.insert(12);
	tree5.insert(14);
	tree5.insert(19);
	tree5.insert(1);
	tree5.insert(2);
	tree5.insert(18);
	tree5.insert(22);
	tree5.insert(23);
	tree5.insert(24);
	tree5.insert(25);
	tree5.insert(27);
	tree5.insert(26);


	std::cout << "----------" << std::endl;
	tree5.print();
}

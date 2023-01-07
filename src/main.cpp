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
	rbtree<int> tree;

	tree.insert(1);
	tree.insert(10);
	tree.insert(5);
	tree.insert(15);
	tree.insert(13);
	tree.insert(20);

	tree.print();
	std::cout << "----------" << std::endl;

	tree.leftRotate(tree.getRoot()->right);
	tree.print();
	std::cout << "----------" << std::endl;

	tree.rightRotate(tree.getRoot()->right);
	tree.print();
}

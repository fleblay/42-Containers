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

	/*
	rbtree<int> t1;
	std::cout << t1.isOk() << std::endl;

	t1.insert(1);
	t1.print();
	std::cout << t1.isOk() << std::endl;

	t1.deleteNode(1);
	t1.print();

	std::cout << "----------" << std::endl;
	*/

	rbtree<int> t2;
	std::cout << t2.isOk() << std::endl;

	t2.insert(2);
	t2.insert(1);
	t2.insert(9);
	t2.insert(7);
	t2.insert(6);
	t2.insert(8);
	t2.insert(11);

	t2.print();
	t2.deleteNode(7);
	std::cout << t2.isOk() << std::endl;
	t2.print();


	std::cout << "----------" << std::endl;

	/*
	rbtree<int> t3;
	std::cout << t3.isOk() << std::endl;

	t3.insert(2);
	t3.insert(3);
	t3.print();

	t3.deleteNode(3);
	std::cout << t3.isOk() << std::endl;
	t3.print();

	std::cout << "----------" << std::endl;

	rbtree<int> t4;
	std::cout << t4.isOk() << std::endl;

	t4.insert(20);
	t4.insert(30);
	t4.insert(10);
	t4.insert(5);
	t4.print();

	t4.deleteNode(10);
	std::cout << t4.isOk() << std::endl;
	t4.print();

	std::cout << "----------" << std::endl;

	rbtree<int> t5;
	std::cout << t5.isOk() << std::endl;

	t5.insert(20);
	t5.insert(30);
	t5.insert(10);
	t5.insert(5);
	t5.insert(8);
	t5.insert(6);
	t5.insert(9);
	t5.print();

	t5.deleteNode(5);
	std::cout << t5.isOk() << std::endl;
	t5.print();
	*/

	/*
	rbtree<int> tree;
	tree.insert(959);
	tree.insert(485);
	tree.insert(675);
	tree.insert(560);
	tree.insert(676);
	tree.insert(382);
	tree.insert(528);
	tree.insert(693);
	tree.insert(817);
	tree.insert(318);
	tree.insert(182);
	tree.insert(936);
	tree.insert(488);
	tree.insert(274);
	tree.insert(72);
	tree.insert(229);
	tree.insert(656);
	tree.insert(479);
	tree.insert(753);
	tree.insert(845);
	tree.insert(156);
	tree.insert(65);
	tree.insert(423);
	tree.insert(303);
	tree.insert(504);
	tree.insert(394);
	tree.insert(467);
	tree.insert(583);
	tree.insert(450);
	tree.insert(550);
	tree.insert(894);
	std::cout << "----------" << std::endl;
	std::cout << "OK ?? : " <<  tree.isOk() << std::endl;
	//tree.print();
	*/

	/*
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
	tree5.insert(20);


	std::cout << "----------" << std::endl;
	tree5.print();

	if (tree5.findNode(22) != NULL)
		std::cout << "OK" << std::endl;
	if (tree5.findNode(44) == NULL)
		std::cout << "OK" << std::endl;

	std::cout <<  "value found : " << *(tree5.findNode(22)->data) << std::endl;

	*/
	srand(time(NULL));
	for (int i = 0; i < 100; i++)
	{
		rbtree<int> tree6;
		int toDel = rand() % 20;
		for (int i = 0; i < 20; i++)
		{
			int toAdd = rand() % 10000;
			if (i == toDel)
				toDel = toAdd;
			if (tree6.findNode(toAdd) == NULL)
			{
				tree6.insert(toAdd);
			}
		}
		std::cout << tree6.isOk() << std::endl;
		std::cout << *(tree6.findMin()->data) << std::endl;
		std::cout << *(tree6.findMax()->data) << std::endl;
		tree6.deleteNode(toDel);
	}
	std::cout << "----------" << std::endl;


}

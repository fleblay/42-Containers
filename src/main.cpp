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
#include "map.hpp"

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

template <class T>
struct myCustomLess : std::less<T>
{
	myCustomLess(void)
	{
		std::cout << "mycustom less instance" << std::endl;
	}
	bool operator() (const T& x, const T& y) const
	{
		std::cout << "mycustom less comparison" << std::endl;
		return (std::less<T>::operator()(x, y));
	}
};

//Dans le vrai map, on utilisera la fonction template de comparaison a la place de std::less
template <typename T, typename U>
struct myCustomLess< pair<T,U> > : std::less<T>
{
	myCustomLess(void)
	{
		//std::cout << "mycustom less instance for pairs" << std::endl;
	}
	bool operator() (const pair<T,U> &x, const pair<T,U> &y) const
	{
		//std::cout << "mycustom less comparison for pairs" << std::endl;
		return (std::less<T>::operator()(x.first, y.first));
	}
};

#include <string>
int main(void)
{

	map<char, int> m1;

	map<char, int>::iterator it = m1.begin();
	map<char, int>::iterator it2;
	it2 = it;
	map<char, int>::iterator it3(it2);

	/*
	//rbtree<pair<int, int>, std::less<int> > t2;
	rbtree<pair<int, float>, myCustomLess< pair<int, float> > > t2;

	std::cout << t2.isOk() << std::endl;

	pair<int, float> p1(1, 2);
	pair<int, float> p2(2, 4);
	pair<int, float> p3(3, 6);
	pair<int, float> p4(4, 8);
	pair<int, float> p5(5, 10);

	t2.insert(p1);
	t2.insert(p2);
	t2.insert(p3);
	t2.insert(p4);
	t2.insert(p5);

	t2.print();
	std::cout << "--------------------" << std::endl;
	std::cout << "deleting :" << p4 << std::endl;
	t2.deleteNode(p4);
	std::cout << t2.isOk() << std::endl;
	t2.print();
	*/

}

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
#include <map>

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

template <typename K, typename V>
void printInfo(const map<K, V> &to_print)
{
	std::cout	<< "Map"
				<< " size : [" << to_print.size() << "]"
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
	map<char, int> m2;

	pair<char, int>	p1 = make_pair<char, int>('e', 42);
	pair<char, int>	p2 = make_pair<char, int>('z', 21);
	pair<char, int>	p3 = make_pair<char, int>('a', 84);
	pair<char, int>	p4 = make_pair<char, int>('b', 12);
	pair<char, int>	p5 = make_pair<char, int>('c', 8);
	pair<char, int>	p6 = make_pair<char, int>('d', 333);
	pair<char, int>	p7 = make_pair<char, int>('e', 100);
	pair<char, int>	p8 = make_pair<char, int>('f', 666);
	pair<char, int>	p9 = make_pair<char, int>('g', 1);

	m1.insert(p1);
	m1.insert(p2);
	m1.insert(p3);
	m1.insert(p4);
	m1.insert(p5);
	m1.insert(p6);

	m2.insert(p7);
	m2.insert(p8);
	m2.insert(p9);

	map<char, int>::iterator it = m1.begin();
	map<char, int>::iterator ite = m1.end();

	for (; it != ite; it++)
		std::cout << *it << std::endl;
	it = m1.begin();

	std::cout << "--------------------" << std::endl;

	map<char, int>::iterator it2 = m2.begin();
	map<char, int>::iterator ite2 = m2.end();

	for (; it2 != ite2; it2++)
		std::cout << *it2 << std::endl;
	it2 = m2.begin();

	std::cout << "--------------------" << std::endl;

	std::cout << "swapping values" << std::endl;
	m1.swap(m2);

	for (it=m1.begin();  it != m1.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "-------STOP PRINT 1---------" << std::endl;

	it2 = m2.begin();
	for (; it2 != m2.end(); it2++)
	{
		std::cout << *it2 << std::endl;
	}
	return (0);
}

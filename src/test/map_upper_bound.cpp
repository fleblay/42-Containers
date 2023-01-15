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

template <typename K, typename V>
void printMap(const map<K, V> &to_print)
{
	std::cout	<< "Map"
				<< " size : [" << to_print.size() << "]"
				<< std::endl;
	for (typename map<K, V>::const_iterator it = to_print.begin(); it != to_print.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "--------------------" << std::endl;
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

	pair<char, int>	p2 = make_pair<char, int>('y', 21);
	pair<char, int>	p3 = make_pair<char, int>('a', 84);
	pair<char, int>	p4 = make_pair<char, int>('b', 12);
	pair<char, int>	p5 = make_pair<char, int>('c', 8);
	pair<char, int>	p1 = make_pair<char, int>('e', 42);
	pair<char, int>	p7 = make_pair<char, int>('f', 666);
	pair<char, int>	p8 = make_pair<char, int>('g', 1);
	pair<char, int>	p6 = make_pair<char, int>('x', 333);
	pair<char, int>	p9 = make_pair<char, int>('t', 13);

	m1.insert(p1);
	m1.insert(p2);
	m1.insert(p3);
	m1.insert(p4);
	m1.insert(p5);
	m1.insert(p6);
	m1.insert(p7);
	m1.insert(p8);
	m1.insert(p9);

	if (m1.upper_bound('a') != m1.end())
		std::cout << "a upper bound : " << *(m1.upper_bound('a')) << std::endl;
	if (m1.upper_bound('c') != m1.end())
		std::cout << "c upper bound : " << *(m1.upper_bound('c')) << std::endl;
	if (m1.upper_bound('d') != m1.end())
		std::cout << "d upper bound : " << *(m1.upper_bound('d')) << std::endl;
	if (m1.upper_bound('e') != m1.end())
		std::cout << "e upper bound : " << *(m1.upper_bound('e')) << std::endl;
	if (m1.upper_bound('z') != m1.end())
		std::cout << "z upper bound : " << *(m1.upper_bound('z')) << std::endl;
	else
		std:: cout << "no upper" << std::endl;
	// constructeur par copy a faire avant puis operateur= puis test sur une const map
	// Const version
	const map<char, int> m2(++(m1.begin()), m1.end());
	if (m2.upper_bound('a') != m2.end())
		std::cout << "a upper bound : " << *(m2.upper_bound('a')) << std::endl;
	if (m2.upper_bound('c') != m2.end())
		std::cout << "c upper bound : " << *(m2.upper_bound('c')) << std::endl;
	if (m2.upper_bound('d') != m2.end())
		std::cout << "d upper bound : " << *(m2.upper_bound('d')) << std::endl;
	if (m2.upper_bound('e') != m2.end())
		std::cout << "e upper bound : " << *(m2.upper_bound('e')) << std::endl;
	if (m2.upper_bound('z') != m2.end())
		std::cout << "z upper bound : " << *(m2.upper_bound('z')) << std::endl;
	else
		std:: cout << "no upper" << std::endl;
}

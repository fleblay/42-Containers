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

bool predicate (int c1, int c2)
{
	return (c1 == c2);
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

	pair<char, int>	p1 = make_pair<char, int>('b', 42);
	pair<char, int>	p2 = make_pair<char, int>('c', 21);

	pair<char, int>	p3 = make_pair<char, int>('f', 100);
	pair<char, int>	p4 = make_pair<char, int>('g', 200);
	pair<char, int>	p5 = make_pair<char, int>('h', -100);
	pair<char, int>	p6 = make_pair<char, int>('i', 8200);
	pair<char, int>	p7 = make_pair<char, int>('j', 300);

	pair<char, int>	p8 = make_pair<char, int>('m', 89);
	pair<char, int>	p9 = make_pair<char, int>('n', 189);
	pair<char, int>	p10 = make_pair<char, int>('o', 666);
	pair<char, int>	p11 = make_pair<char, int>('p', 777);
	pair<char, int>	p12 = make_pair<char, int>('q', 555);

	pair<char, int>	p13 = make_pair<char, int>('s', 111);
	pair<char, int>	p14 = make_pair<char, int>('t', 999);
	pair<char, int>	p15 = make_pair<char, int>('u', 222);

	pair<char, int>	p16 = make_pair<char, int>('x', 88);

	m1.insert(p1);
	m1.insert(p2);
	m1.insert(p3);
	m1.insert(p4);
	m1.insert(p5);
	m1.insert(p6);
	m1.insert(p7);
	m1.insert(p8);
	m1.insert(p9);
	m1.insert(p10);
	m1.insert(p11);
	m1.insert(p12);
	m1.insert(p13);
	m1.insert(p14);
	m1.insert(p15);
	m1.insert(p16);

	if (m1.lower_bound('a') != m1.end())
		std::cout << "a lower bound : " << *(m1.lower_bound('a')) << std::endl;
	if (m1.lower_bound('c') != m1.end())
		std::cout << "c lower bound : " << *(m1.lower_bound('c')) << std::endl;
	if (m1.lower_bound('d') != m1.end())
		std::cout << "d lower bound : " << *(m1.lower_bound('d')) << std::endl;
	if (m1.lower_bound('e') != m1.end())
		std::cout << "e lower bound : " << *(m1.lower_bound('e')) << std::endl;
	if (m1.lower_bound('o') != m1.end())
		std::cout << "o lower bound : " << *(m1.lower_bound('o')) << std::endl;
	if (m1.lower_bound('z') != m1.end())
		std::cout << "z lower bound : " << *(m1.lower_bound('z')) << std::endl;
	else
		std:: cout << "no lower" << std::endl;
	// constructeur par copy a faire avant puis operateur= puis test sur une const map
	// Const version
	const map<char, int> m2(++(m1.begin()), m1.end());
	if (m2.lower_bound('a') != m2.end())
		std::cout << "a lower bound : " << *(m2.lower_bound('a')) << std::endl;
	if (m2.lower_bound('c') != m2.end())
		std::cout << "c lower bound : " << *(m2.lower_bound('c')) << std::endl;
	if (m2.lower_bound('d') != m2.end())
		std::cout << "d lower bound : " << *(m2.lower_bound('d')) << std::endl;
	if (m2.lower_bound('e') != m2.end())
		std::cout << "e lower bound : " << *(m2.lower_bound('e')) << std::endl;
	if (m2.lower_bound('o') != m2.end())
		std::cout << "o lower bound : " << *(m2.lower_bound('o')) << std::endl;
	if (m2.lower_bound('z') != m2.end())
		std::cout << "z lower bound : " << *(m2.lower_bound('z')) << std::endl;
	else
		std:: cout << "no lower" << std::endl;
}

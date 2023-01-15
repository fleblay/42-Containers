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

	pair<map<char, int>::iterator, map<char, int>::iterator> eq1 = m1.equal_range('a');
	pair<map<char, int>::iterator, map<char, int>::iterator> eq2 = m1.equal_range('c');
	pair<map<char, int>::iterator, map<char, int>::iterator> eq3 = m1.equal_range('d');
	pair<map<char, int>::iterator, map<char, int>::iterator> eq4 = m1.equal_range('e');
	pair<map<char, int>::iterator, map<char, int>::iterator> eq5 = m1.equal_range('z');
	if (eq1.first != eq1.second)
		std::cout << "a equal_range : " << *(eq1.first)<< std::endl;
	else
		std:: cout << "no equal" << std::endl;
	if (eq2.first != eq2.second)
		std::cout << "c equal_range : " << *(eq2.first)<< std::endl;
	else
		std:: cout << "no equal" << std::endl;
	if (eq3.first != eq3.second)
		std::cout << "d equal_range : " << *(eq3.first)<< std::endl;
	else
		std:: cout << "no equal" << std::endl;
	if (eq4.first != eq4.second)
		std::cout << "e equal_range : " << *(eq4.first)<< std::endl;
	else
		std:: cout << "no equal" << std::endl;
	if (eq5.first != eq5.second)
		std::cout << "z equal_range : " << *(eq5.first)<< std::endl;
	else
		std:: cout << "no equal" << std::endl;
	// constructeur par copy a faire avant puis operateur= puis test sur une const map
	// Const version
	const map<char, int> m2(++(m1.begin()), m1.end());
	pair<map<char, int>::const_iterator, map<char, int>::const_iterator> ceq1 = m2.equal_range('a');
	pair<map<char, int>::const_iterator, map<char, int>::const_iterator> ceq2 = m2.equal_range('c');
	pair<map<char, int>::const_iterator, map<char, int>::const_iterator> ceq3 = m2.equal_range('d');
	pair<map<char, int>::const_iterator, map<char, int>::const_iterator> ceq4 = m2.equal_range('e');
	pair<map<char, int>::const_iterator, map<char, int>::const_iterator> ceq5 = m2.equal_range('z');
	if (ceq1.first != ceq1.second)
		std::cout << "a cequal_range : " << *(ceq1.first)<< std::endl;
	else
		std:: cout << "no cequal" << std::endl;
	if (ceq2.first != ceq2.second)
		std::cout << "c cequal_range : " << *(ceq2.first)<< std::endl;
	else
		std:: cout << "no cequal" << std::endl;
	if (ceq3.first != ceq3.second)
		std::cout << "d cequal_range : " << *(ceq3.first)<< std::endl;
	else
		std:: cout << "no cequal" << std::endl;
	if (ceq4.first != ceq4.second)
		std::cout << "e cequal_range : " << *(ceq4.first)<< std::endl;
	else
		std:: cout << "no cequal" << std::endl;
	if (ceq5.first != ceq5.second)
		std::cout << "z cequal_range : " << *(ceq5.first)<< std::endl;
	else
		std:: cout << "no cequal" << std::endl;
}

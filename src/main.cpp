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
#include <list> // for testing
#include <set>
#include "set.hpp"

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

template <typename T>
void printSet(const set<T> &to_print)
{
	std::cout	<< "set"
				<< " size : [" << to_print.size() << "]"
				<< std::endl;
	for (typename set<T>::const_iterator it = to_print.begin(); it != to_print.end(); it++)
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

template <class T>
void	is_empty(T const &st)
{
	std::cout << "is_empty: " << st.empty() << std::endl;
}

int main(void)
{
	map<char, int> m1;

	pair<char, int>	p1 = make_pair<char, int>('e', 42);
	pair<char, int>	p2 = make_pair<char, int>('z', 21);
	pair<char, int>	p3 = make_pair<char, int>('a', 84);
	pair<char, int>	p4 = make_pair<char, int>('b', 12);
	pair<char, int>	p5 = make_pair<char, int>('c', 8);
	pair<char, int>	p6 = make_pair<char, int>('d', 333);
	pair<char, int>	p7 = make_pair<char, int>('e', 100); // should fail
	pair<char, int>	p8 = make_pair<char, int>('f', 666);
	pair<char, int>	p9 = make_pair<char, int>('g', 1);

	pair<map<char, int>::iterator, bool> res1 = m1.insert(p1);
	pair<map<char, int>::iterator, bool> res2 = m1.insert(p2);
	pair<map<char, int>::iterator, bool> res3 = m1.insert(p3);
	pair<map<char, int>::iterator, bool> res4 = m1.insert(p4);
	pair<map<char, int>::iterator, bool> res5 = m1.insert(p5);
	pair<map<char, int>::iterator, bool> res6 = m1.insert(p6);
	pair<map<char, int>::iterator, bool> res7 = m1.insert(p7);
	pair<map<char, int>::iterator, bool> res8 = m1.insert(p8);
	pair<map<char, int>::iterator, bool> res9 = m1.insert(p9);

	//m1.clear();
	for (map<char, int>::iterator it = m1.begin(); it != m1.end();)
	{
		m1.erase(it->first);
		it = m1.begin();
	}
	
	printMap(m1);

	m1.insert(p1);
	m1.insert(p2);
	m1.insert(p3);
	m1.insert(p4);
	m1.insert(p5);
	m1.insert(p6);

	return (0);
}

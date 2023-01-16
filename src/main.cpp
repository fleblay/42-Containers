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

struct myStruct
{
	int a;
};

int		main(void)
{
	/*
	map<char, int>	mymap;

	pair<char, int>	p2 = make_pair<char, int>('x', 21);
	pair<char, int>	p3 = make_pair<char, int>('a', 84);
	pair<char, int>	p4 = make_pair<char, int>('b', 12);
	pair<char, int>	p5 = make_pair<char, int>('c', 8);
	pair<char, int>	p6 = make_pair<char, int>('d', 333);
	pair<char, int>	p7 = make_pair<char, int>('e', 100);
	pair<char, int>	p8 = make_pair<char, int>('f', 666);
	pair<char, int>	p9 = make_pair<char, int>('g', 1);
	mymap.insert(p2);
	mymap.insert(p3);
	mymap.insert(p4);
	mymap.insert(p5);
	mymap.insert(p6);
	mymap.insert(p7);
	mymap.insert(p8);
	mymap.insert(p9);

	for (map<char, int>::const_reverse_iterator crit = mymap.rbegin(); crit != mymap.rend(); crit++)
	{
		std::cout << "[" << crit->first << "] [" << crit->second << "]" << std::endl;
	}

	*/
	signal(SIGSEGV, signal_handler);

	//Simple Iterator Test, * and ->
	vector<int>::iterator it_0;
	int a = 12;
	vector<int>::iterator it_1(&a);
	it_0 = it_1;
	std::cout << *it_0 << std::endl;
	struct myStruct test;
	test.a = 28;
	vector<struct myStruct>::iterator	it_struct(&test);
	std::cout << it_struct->a << std::endl;

	//Using begin and end to test simple use case operators
	vector<int>	myvector;

	for (int i = 0; i <= 10; i++)
		myvector.push_back(i);
	vector<int>::iterator	it = myvector.begin();
	vector<int>::iterator	ite = myvector.end();

	for (; it != ite; it++)
		std::cout << "vector value : [" << *it << "]" << std::endl;

	//Testing iterator member functions (overload of operators)
	vector<int>::iterator	it2 = myvector.begin() + 4;
	std::cout << "vector value : [" << (*it2++) << "]" << std::endl;
	std::cout << "vector value : [" << *it2 << "]" << std::endl;
	std::cout << "vector value : [" << *(it2--) << "]" << std::endl;
	std::cout << "vector value : [" << *(++it2) << "]" << std::endl;
	std::cout << "vector value : [" << *(--it2) << "]" << std::endl;
	std::cout << "vector value : [" << *(it2 + 3) << "]" << std::endl;
	std::cout << "vector value : [" << *(it2 += 3) << "]" << std::endl;
	std::cout << "vector value : [" << *(it2 - 2) << "]" << std::endl;
	std::cout << "vector value : [" << *(it2 -= 1) << "]" << std::endl;
	std::cout << "vector value : [" << it2[3] << "]" << std::endl;
	std::cout << "diff value : [" << it2 - it << "]" << std::endl;
	std::cout << "vector value : [" << *(3 + it2) << "]" << std::endl;

	//Testing iterator comparisons
	if (it == it2)
		std::cout << "same" << std::endl;
	if (it != it2)
		std::cout << "diff" << std::endl;
	if (it >= it2)
		std::cout << "ge" << std::endl;
	if (it <= it2)
		std::cout << "le" << std::endl;
	if (it > it2)
		std::cout << "gt" << std::endl;
	if (it < it2)
		std::cout << "lt" << std::endl;

	it = myvector.begin();
	
	if (it == it2)
		std::cout << "same" << std::endl;
	if (it != it2)
		std::cout << "diff" << std::endl;
	if (it >= it2)
		std::cout << "ge" << std::endl;
	if (it <= it2)
		std::cout << "le" << std::endl;
	if (it > it2)
		std::cout << "gt" << std::endl;
	if (it < it2)
		std::cout << "lt" << std::endl;

	//Testing const iterators
	const vector<int>				myconstvector;
	vector<int>::const_iterator		cit = myconstvector.begin();
	cit++;
	vector<int>::const_iterator		cend = myconstvector.end();
	cend--;

	vector<int>::const_iterator		cit2;
	cit2 = myvector.begin();
	cit2++;
	std::cout << "const vector value : [" << *cit2 << "]" << std::endl;

	//Testing const iterators construction from non-const iterator
	vector<int>::const_iterator		cit3 = myvector.begin();
	cit3++;
	vector<int>::const_iterator		cit4 = myvector.end();
	cit4--;

	//Testing comparison of const and non-const iterator
	if (cit == it2)
		std::cout << "same" << std::endl;
	if (cit != it2)
		std::cout << "diff" << std::endl;
	if (cit >= it2)
		std::cout << "ge" << std::endl;
	if (cit <= it2)
		std::cout << "le" << std::endl;
	if (cit > it2)
		std::cout << "gt" << std::endl;
	if (cit < it2)
		std::cout << "lt" << std::endl;
	return (0);
}

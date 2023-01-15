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
	pair<const char, int>	*p;

	p = m1.get_allocator().allocate(5);
	int psize = sizeof(map<char, int>::value_type) * 5;

	std::cout << "Successfull allocation of " << psize << "bytes" << std::endl;

	m1.get_allocator().deallocate(p, 5);

	return (0);
}

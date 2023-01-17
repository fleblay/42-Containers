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
	set<int>	myset;
	set<int>	myset4;

	myset.insert(2);
	myset.insert(3);
	myset.insert(4);
	myset.insert(5);
	myset.insert(6);
	myset.insert(7);
	myset.insert(8);
	myset.insert(9);

	myset4.insert(20);
	myset4.insert(30);
	myset4.insert(40);
	myset4.insert(50);
	myset4.insert(60);
	myset4.insert(70);
	myset4.insert(80);
	myset4.insert(90);

	set<int>	myset2(myset);
	set<int>	myset3(++myset.begin(), myset.end());
	printSet(myset2);
	printSet(myset3);

	for( set<int>::reverse_iterator rit = myset.rbegin(); rit != myset.rend(); rit++)
		std::cout << *rit << std::endl;

	std::cout << myset.empty() << std::endl;
	std::cout << myset.size() << std::endl;
	std::cout << myset.max_size() << std::endl;

	myset.insert(10);
	myset.insert(myset4.begin(), 12);
	myset.insert(myset4.begin(), myset4.end());
	printSet(myset);

	myset.erase(++myset.begin());
	myset.erase(12);
	myset.insert(++(myset.begin()), --(myset.end()));

	myset4.swap(myset);
	printSet(myset);
	printSet(myset4);

	myset.clear();
	printSet(myset);

	std::cout << *(myset4.find(70)) << std::endl;
	std::cout << myset4.count(60) << std::endl;
	std::cout << myset4.count(65) << std::endl;

	std::cout << *(myset4.upper_bound(70)) << std::endl;
	std::cout << *(myset4.lower_bound(70)) << std::endl;
	std::cout << *(myset4.equal_range(70).first) << std::endl;

	std::cout << (myset == myset4) << std::endl;
	std::cout << (myset != myset4) << std::endl;
	std::cout << (myset < myset4) << std::endl;
	std::cout << (myset > myset4) << std::endl;
	std::cout << (myset <= myset4) << std::endl;
	std::cout << (myset >= myset4) << std::endl;
}

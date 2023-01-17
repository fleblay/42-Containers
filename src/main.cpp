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
#include <sys/time.h>

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

unsigned int get_exec_time(struct timeval start, struct timeval end)
{
	return (end.tv_sec * 1000000 + end.tv_usec - start.tv_sec * 1000000 - start.tv_usec);
}

int main(void)
{
	struct timeval start;
	struct timeval end;
	unsigned int time_ft = 0;
	unsigned int time_std = 0;
	float ratio = 0;

	srand(time(NULL));

	std::vector<int>	data_pool;
	for (int i = 0; i < 100000 ; i++)
		data_pool.push_back(rand());

	std::map<int, int>	m1;
	ft::map<int, int>	m2;

	gettimeofday(&start, NULL);
	for (int i = 0; i < 100000 ; i++)
		m1.insert(std::make_pair<int, int>(data_pool[i], data_pool[i]));
	gettimeofday(&end, NULL);
	time_std = get_exec_time(start, end);

	gettimeofday(&start, NULL);
	for (int i = 0; i < 100000 ; i++)
		m2.insert(ft::make_pair<int, int>(data_pool[i], data_pool[i]));
	gettimeofday(&end, NULL);
	time_ft = get_exec_time(start, end);

	ratio = (float)time_ft/time_std;

	std::cout << "ft::map.insert() is : [" << ratio << "] slower than std" << std::endl;
	std::cout << "--------------------" << std::endl;

	return (0);
}

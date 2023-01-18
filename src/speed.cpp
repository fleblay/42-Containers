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

std::string	get_color(float ratio)
{
	if (ratio < 5)
		return ("\x1b[32m");
	if (ratio < 20)
		return ("\x1b[33m");
	return ("\x1b[31m");

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

	//MAP insert
	std::cout << "MAP insert" << std::endl;
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
	std::cout << "time_ft : [" << time_ft << "]" << std::endl;
	std::cout << "time_std : [" << time_std << "]" << std::endl;

	std::cout << "ft::map.insert() is : [" << get_color(ratio) << ratio << "\x1b[0m] times slower than std" << std::endl;
	std::cout << "--------------------" << std::endl;

	//MAP find
	std::cout << "MAP find" << std::endl;

	gettimeofday(&start, NULL);
	for (int i = 0; i < 100000 ; i++)
		m1.find(data_pool[i]);
	gettimeofday(&end, NULL);
	time_std = get_exec_time(start, end);

	gettimeofday(&start, NULL);
	for (int i = 0; i < 100000 ; i++)
		m2.find(data_pool[i]);
	gettimeofday(&end, NULL);
	time_ft = get_exec_time(start, end);

	ratio = (float)time_ft/time_std;
	std::cout << "time_ft : [" << time_ft << "]" << std::endl;
	std::cout << "time_std : [" << time_std << "]" << std::endl;

	std::cout << "ft::map.fin() is : [" << get_color(ratio) << ratio << "\x1b[0m] times slower than std" << std::endl;
	std::cout << "--------------------" << std::endl;

	//MAP copy
	std::cout << "MAP copy" << std::endl;

	gettimeofday(&start, NULL);
	std::map<int, int>	m3(m1);
	gettimeofday(&end, NULL);
	time_std = get_exec_time(start, end);

	gettimeofday(&start, NULL);
	ft::map<int, int>	m4(m2);
	gettimeofday(&end, NULL);
	time_ft = get_exec_time(start, end);

	ratio = (float)time_ft/time_std;
	std::cout << "time_ft : [" << time_ft << "]" << std::endl;
	std::cout << "time_std : [" << time_std << "]" << std::endl;

	std::cout << "ft::map copy constructor is : [" << get_color(ratio) << ratio << "\x1b[0m] times slower than std" << std::endl;
	std::cout << "--------------------" << std::endl;

	//MAP erase
	std::cout << "MAP erase" << std::endl;

	gettimeofday(&start, NULL);
	for (int i = 0; i < 100000 ; i++)
		m1.erase(data_pool[i]);
	gettimeofday(&end, NULL);
	time_std = get_exec_time(start, end);

	gettimeofday(&start, NULL);
	for (int i = 0; i < 100000 ; i++)
		m2.erase(data_pool[i]);
	gettimeofday(&end, NULL);
	time_ft = get_exec_time(start, end);

	ratio = (float)time_ft/time_std;
	std::cout << "time_ft : [" << time_ft << "]" << std::endl;
	std::cout << "time_std : [" << time_std << "]" << std::endl;

	std::cout << "ft::map.erase() is : [" << get_color(ratio) << ratio << "\x1b[0m] times slower than std" << std::endl;
	std::cout << "--------------------" << std::endl;

	//vector insert
	std::cout << "vector insert" << std::endl;
	std::vector<int>	v1;
	ft::vector<int>		v2;

	gettimeofday(&start, NULL);
	for (int i = 0; i < 100000 ; i++)
		v1.push_back(data_pool[i]);
	gettimeofday(&end, NULL);
	time_std = get_exec_time(start, end);

	gettimeofday(&start, NULL);
	for (int i = 0; i < 100000 ; i++)
		v2.push_back(data_pool[i]);
	gettimeofday(&end, NULL);
	time_ft = get_exec_time(start, end);

	ratio = (float)time_ft/time_std;
	std::cout << "time_ft : [" << time_ft << "]" << std::endl;
	std::cout << "time_std : [" << time_std << "]" << std::endl;

	std::cout << "ft::vector.push_back() is : [" << get_color(ratio) << ratio << "\x1b[0m] times slower than std" << std::endl;
	std::cout << "--------------------" << std::endl;

	//vector erase
	std::cout << "vector erase" << std::endl;

	gettimeofday(&start, NULL);
	for (int i = 0; i < 100000 ; i+= 1000)
		v1.erase(v1.begin());
	gettimeofday(&end, NULL);
	time_std = get_exec_time(start, end);

	gettimeofday(&start, NULL);
	for (int i = 0; i < 100000 ; i+= 1000)
		v2.erase(v2.begin());
	gettimeofday(&end, NULL);
	time_ft = get_exec_time(start, end);

	ratio = (float)time_ft/time_std;
	std::cout << "time_ft : [" << time_ft << "]" << std::endl;
	std::cout << "time_std : [" << time_std << "]" << std::endl;

	std::cout << "ft::vector.erase() is : [" << get_color(ratio) << ratio << "\x1b[0m] times slower than std" << std::endl;
	std::cout << "--------------------" << std::endl;

	//vector erase range
	std::cout << "vector erase range" << std::endl;

	gettimeofday(&start, NULL);
		v1.erase(v1.begin() + 2, v1.begin() + 5000);
	gettimeofday(&end, NULL);
	time_std = get_exec_time(start, end);

	gettimeofday(&start, NULL);
		v2.erase(v2.begin() + 2, v2.begin() + 5000);
	gettimeofday(&end, NULL);
	time_ft = get_exec_time(start, end);

	ratio = (float)time_ft/time_std;
	std::cout << "time_ft : [" << time_ft << "]" << std::endl;
	std::cout << "time_std : [" << time_std << "]" << std::endl;

	std::cout << "ft::vector.erase() range version is : [" << get_color(ratio) << ratio << "\x1b[0m] times slower than std" << std::endl;
	std::cout << "--------------------" << std::endl;

	//set insert
	std::cout << "set insert" << std::endl;
	std::set<int>	s1;
	ft::set<int>	s2;

	gettimeofday(&start, NULL);
	for (int i = 0; i < 100000 ; i++)
		s1.insert(data_pool[i]);
	gettimeofday(&end, NULL);
	time_std = get_exec_time(start, end);

	gettimeofday(&start, NULL);
	for (int i = 0; i < 100000 ; i++)
		s2.insert(data_pool[i]);
	gettimeofday(&end, NULL);
	time_ft = get_exec_time(start, end);

	ratio = (float)time_ft/time_std;
	std::cout << "time_ft : [" << time_ft << "]" << std::endl;
	std::cout << "time_std : [" << time_std << "]" << std::endl;

	std::cout << "ft::set.insert() is : [" << get_color(ratio) << ratio << "\x1b[0m] times slower than std" << std::endl;
	std::cout << "--------------------" << std::endl;

	//set find
	std::cout << "set find" << std::endl;

	gettimeofday(&start, NULL);
	for (int i = 0; i < 100000 ; i++)
		s1.find(data_pool[i]);
	gettimeofday(&end, NULL);
	time_std = get_exec_time(start, end);

	gettimeofday(&start, NULL);
	for (int i = 0; i < 100000 ; i++)
		s2.find(data_pool[i]);
	gettimeofday(&end, NULL);
	time_ft = get_exec_time(start, end);

	ratio = (float)time_ft/time_std;
	std::cout << "time_ft : [" << time_ft << "]" << std::endl;
	std::cout << "time_std : [" << time_std << "]" << std::endl;

	std::cout << "ft::set.fin() is : [" << get_color(ratio) << ratio << "\x1b[0m] times slower than std" << std::endl;
	std::cout << "--------------------" << std::endl;

	//set copy
	std::cout << "set copy" << std::endl;

	gettimeofday(&start, NULL);
	std::set<int>	s3(s1);
	gettimeofday(&end, NULL);
	time_std = get_exec_time(start, end);

	gettimeofday(&start, NULL);
	ft::set<int>	s4(s2);
	gettimeofday(&end, NULL);
	time_ft = get_exec_time(start, end);

	ratio = (float)time_ft/time_std;
	std::cout << "time_ft : [" << time_ft << "]" << std::endl;
	std::cout << "time_std : [" << time_std << "]" << std::endl;

	std::cout << "ft::set copy constructor is : [" << get_color(ratio) << ratio << "\x1b[0m] times slower than std" << std::endl;
	std::cout << "--------------------" << std::endl;

	//set erase
	std::cout << "set erase" << std::endl;

	gettimeofday(&start, NULL);
	for (int i = 0; i < 100000 ; i++)
		s1.erase(data_pool[i]);
	gettimeofday(&end, NULL);
	time_std = get_exec_time(start, end);

	gettimeofday(&start, NULL);
	for (int i = 0; i < 100000 ; i++)
		s2.erase(data_pool[i]);
	gettimeofday(&end, NULL);
	time_ft = get_exec_time(start, end);

	ratio = (float)time_ft/time_std;
	std::cout << "time_ft : [" << time_ft << "]" << std::endl;
	std::cout << "time_std : [" << time_std << "]" << std::endl;

	std::cout << "ft::set.erase() is : [" << get_color(ratio) << ratio << "\x1b[0m] times slower than std" << std::endl;
	std::cout << "--------------------" << std::endl;

	//stack insert
	std::cout << "stack insert" << std::endl;
	std::stack<int>	k1;
	ft::stack<int>		k2;

	gettimeofday(&start, NULL);
	for (int i = 0; i < 100000 ; i++)
		k1.push(data_pool[i]);
	gettimeofday(&end, NULL);
	time_std = get_exec_time(start, end);

	gettimeofday(&start, NULL);
	for (int i = 0; i < 100000 ; i++)
		k2.push(data_pool[i]);
	gettimeofday(&end, NULL);
	time_ft = get_exec_time(start, end);

	ratio = (float)time_ft/time_std;
	std::cout << "time_ft : [" << time_ft << "]" << std::endl;
	std::cout << "time_std : [" << time_std << "]" << std::endl;

	std::cout << "ft::stack.push_back() is : [" << get_color(ratio) << ratio << "\x1b[0m] times slower than std" << std::endl;
	std::cout << "--------------------" << std::endl;

	//stack copy
	std::cout << "stack copy" << std::endl;

	gettimeofday(&start, NULL);
	std::stack<int>	k3(k1);
	gettimeofday(&end, NULL);
	time_std = get_exec_time(start, end);

	gettimeofday(&start, NULL);
	ft::stack<int>	k4(k2);
	gettimeofday(&end, NULL);
	time_ft = get_exec_time(start, end);

	ratio = (float)time_ft/time_std;
	std::cout << "time_ft : [" << time_ft << "]" << std::endl;
	std::cout << "time_std : [" << time_std << "]" << std::endl;

	std::cout << "ft::stack copy constructor is : [" << get_color(ratio) << ratio << "\x1b[0m] times slower than std" << std::endl;
	std::cout << "--------------------" << std::endl;

	//stack erase
	std::cout << "stack erase" << std::endl;

	gettimeofday(&start, NULL);
	for (int i = 0; i < 100000 ; i+= 10)
		k1.pop();
	gettimeofday(&end, NULL);
	time_std = get_exec_time(start, end);

	gettimeofday(&start, NULL);
	for (int i = 0; i < 100000 ; i+= 10)
		k2.pop();
	gettimeofday(&end, NULL);
	time_ft = get_exec_time(start, end);

	ratio = (float)time_ft/time_std;
	std::cout << "time_ft : [" << time_ft << "]" << std::endl;
	std::cout << "time_std : [" << time_std << "]" << std::endl;

	std::cout << "ft::stack.pop() is : [" << get_color(ratio) << ratio << "\x1b[0m] times slower than std" << std::endl;
	std::cout << "--------------------" << std::endl;


	return (0);

}

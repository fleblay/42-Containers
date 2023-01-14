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
	std::cout << "p1 : ok ? -> " << res1.second << ", value -> " << *(res1.first) << std::endl;
	std::cout << "p2 : ok ? -> " << res2.second << ", value -> " << *(res2.first) << std::endl;
	std::cout << "p3 : ok ? -> " << res3.second << ", value -> " << *(res3.first) << std::endl;
	std::cout << "p4 : ok ? -> " << res4.second << ", value -> " << *(res4.first) << std::endl;
	std::cout << "p5 : ok ? -> " << res5.second << ", value -> " << *(res5.first) << std::endl;
	std::cout << "p6 : ok ? -> " << res6.second << ", value -> " << *(res6.first) << std::endl;
	std::cout << "p7 : ok ? -> " << res7.second << ", value -> " << *(res7.first) << std::endl;
	std::cout << "p8 : ok ? -> " << res8.second << ", value -> " << *(res8.first) << std::endl;
	std::cout << "p9 : ok ? -> " << res9.second << ", value -> " << *(res9.first) << std::endl;
	return (0);
}

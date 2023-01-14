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
	//Iterator

	map<char, int> m1;

	map<char, int>::iterator it = m1.begin();
	map<char, int>::iterator it2;
	it2 = it;
	map<char, int>::iterator it3(it2);
	(void)it3;

	std::cout << "--------1-----------" << std::endl;

	//Const Iterator
	const map<char, int> m2;
	map<char, int>::const_iterator cit = m2.begin();
	map<char, int>::const_iterator cit2;
	cit2 = cit;
	map<char, int>::const_iterator cit3(cit2);
	(void)cit3;

	std::cout << "--------2-----------" << std::endl;
	//Conversion Iterator<->Const Iterator

	map<char, int>::const_iterator convit;
	convit = m1.begin();

	map<char, int>::const_iterator convit2(m1.begin());

	std::cout << "--------3-----------" << std::endl;

	//Inserting pairs to check value of iterator begin
	pair<char, int>	p1 = make_pair<char, int>('e', 42);
	pair<map<char, int>::iterator, bool>	pres1 = m1.insert(p1);
	std::cout << pres1.second << std::endl;
	std::cout << "--------4-----------" << std::endl;

	pair<map<char, int>::iterator, bool>	pres2 = m1.insert(p1);
	std::cout << pres2.second << std::endl;
	std::cout << "--------5-----------" << std::endl;

	pair<char, int>	p2 = make_pair<char, int>('z', 21);
	pair<char, int>	p3 = make_pair<char, int>('a', 84);
	pair<char, int>	p4 = make_pair<char, int>('b', 12);
	pair<char, int>	p5 = make_pair<char, int>('c', 8);
	pair<char, int>	p6 = make_pair<char, int>('d', 333);
	pair<char, int>	p7 = make_pair<char, int>('e', 100);
	pair<char, int>	p8 = make_pair<char, int>('f', 666);
	pair<char, int>	p9 = make_pair<char, int>('g', 1);
	m1.insert(p2);
	m1.insert(p3);
	m1.insert(p4);
	m1.insert(p5);
	m1.insert(p6);
	m1.insert(p7);
	m1.insert(p8);
	m1.insert(p9);

	std::cout << "--------6-----------" << std::endl;
	map<char, int>::iterator it4 = m1.begin();

	std::cout << *it4 << std::endl;
	std::cout << it4->first << std::endl;
	std::cout << it4->second << std::endl;

	std::cout << "--------7-----------" << std::endl;
	map<char, int>::const_iterator it5 = m1.begin();
	std::cout << *it5 << std::endl;
	std::cout << it5->first << std::endl;
	std::cout << it5->second << std::endl;

	std::cout << "--------8-----------" << std::endl;

	//Comparison
	map<char, int>::iterator it6 = m1.begin();
	map<char, int>::iterator it7 = m1.begin();
	map<char, int>::const_iterator cit6 = m1.begin();

	std::cout << (it6 == it7) << std::endl;
	std::cout << (it6 == cit6) << std::endl;
	std::cout << (it6 != it7) << std::endl;
	std::cout << (it6 != cit6) << std::endl;

	std::cout << "--------9-----------" << std::endl;
	//Comparison const
	map<char, int>::const_iterator ccit6 = m2.begin();
	map<char, int>::const_iterator ccit7 = m2.begin();

	std::cout << (ccit6 == ccit7) << std::endl;
	std::cout << (ccit6 != ccit7) << std::endl;

	std::cout << "--------10-----------" << std::endl;

	//++ et --
	map<char, int>::iterator it8 = m1.begin();
	std::cout << "*it8 : " << *it8 << std::endl;
	std::cout << "*++it8 : " << *++it8 << std::endl;
	std::cout << "*--it8 : " << *--it8 << std::endl;
	std::cout << "*(it8++) : " << *(it8++) << std::endl;
	std::cout << "*it8 : " << *it8 << std::endl;
	std::cout << "*(it8--) : " << *(it8--) << std::endl;
	std::cout << "*it8 : " << *it8 << std::endl;

	std::cout << "--------11-----------" << std::endl;

	//end et ++
	map<char, int>::iterator it9 = m1.begin();
	map<char, int>::iterator ite = m1.end();
	while (it9 != ite)
	{
		std::cout << "it9 value : " << *it9 << std::endl;
		++it9;
	}
	std::cout << "--------12-----------" << std::endl;
	//Const ++ et --
	map<char, int>::const_iterator it10 = m1.begin();
	std::cout << "*it10 : " << *it10 << std::endl;
	std::cout << "*++it10 : " << *++it10 << std::endl;
	std::cout << "*--it10 : " << *--it10 << std::endl;
	std::cout << "*(it10++) : " << *(it10++) << std::endl;
	std::cout << "*it10 : " << *it10 << std::endl;
	std::cout << "*(it10--) : " << *(it10--) << std::endl;
	std::cout << "*it10 : " << *it10 << std::endl;

	std::cout << "--------13-----------" << std::endl;

	//end et ++
	map<char, int>::const_iterator it11 = m1.begin();
	map<char, int>::const_iterator cite = m1.end();
	while (it11 != cite)
	{
		std::cout << "it11 value : " << *it11 << std::endl;
		++it11;
	}
	std::cout << "--------14-----------" << std::endl;

	//Reverse
	//++ et --
	map<char, int>::reverse_iterator rit8 = m1.rbegin();
	std::cout << "*rit8 : " << *rit8 << std::endl;
	std::cout << "*++rit8 : " << *++rit8 << std::endl;
	std::cout << "*--rit8 : " << *--rit8 << std::endl;
	std::cout << "*(rit8++) : " << *(rit8++) << std::endl;
	std::cout << "*rit8 : " << *rit8 << std::endl;
	std::cout << "*(rit8--) : " << *(rit8--) << std::endl;
	std::cout << "*rit8 : " << *rit8 << std::endl;

	std::cout << "--------15-----------" << std::endl;

	//end et ++
	map<char, int>::reverse_iterator rit9 = m1.rbegin();
	map<char, int>::reverse_iterator rite = m1.rend();
	while (rit9 != rite)
	{
		std::cout << "rit9 value : " << std::endl;
		std::cout << *rit9 << std::endl;
		++rit9;
	}
	std::cout << "--------16-----------" << std::endl;

	//Const Reverse
	//++ et --
	map<char, int>::const_reverse_iterator rit10 = m1.rbegin();
	std::cout << "*rit10 : " << *rit10 << std::endl;
	std::cout << "*++rit10 : " << *++rit10 << std::endl;
	std::cout << "*--rit10 : " << *--rit10 << std::endl;
	std::cout << "*(rit10++) : " << *(rit10++) << std::endl;
	std::cout << "*rit10 : " << *rit10 << std::endl;
	std::cout << "*(rit10--) : " << *(rit10--) << std::endl;
	std::cout << "*rit10 : " << *rit10 << std::endl;

	std::cout << "--------17-----------" << std::endl;

	//end et ++
	map<char, int>::const_reverse_iterator rit11 = m1.rbegin();
	map<char, int>::const_reverse_iterator crite = m1.rend();
	while (rit11 != crite)
	{
		std::cout << "rit11 value : " << std::endl;
		std::cout << *rit11 << std::endl;
		++rit11;
	}
	std::cout << "--------18-----------" << std::endl;

	//empty vector

	map<char, int> m4;

	map<char, int>::iterator mit1 = m4.begin();
	map<char, int>::iterator mite1 = m4.end();

	map<char, int>::const_iterator cmit1 = m4.begin();
	map<char, int>::const_iterator cmite1 = m4.end();

	map<char, int>::reverse_iterator rmit1 = m4.rbegin();
	map<char, int>::reverse_iterator rmite1 = m4.rend();

	map<char, int>::const_reverse_iterator crmit1 = m4.rbegin();
	map<char, int>::const_reverse_iterator crmite1 = m4.rend();

	for (; mit1 != mite1; mit1++)
		std::cout << *mit1 << std::endl;
	for (; cmit1 != cmite1; cmit1++)
		std::cout << *cmit1 << std::endl;
	for (; rmit1 != rmite1; rmit1++)
		std::cout << *rmit1 << std::endl;
	for (; crmit1 != crmite1; crmit1++)
		std::cout << *crmit1 << std::endl;

	std::cout << "--------------------" << std::endl;
}

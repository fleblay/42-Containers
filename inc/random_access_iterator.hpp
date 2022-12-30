#ifndef RANDOM_ACCESS_ITERATOR_H
# define RANDOM_ACCESS_ITERATOR_H

# include "iterator.hpp"
# include <cstddef>

namespace ft
{
	template<typename Iter>
	class random_access_iterator : public iterator<ft::random_access_iterator_tag, Iter> // changer ft par std pour tester algo
	{
		private	:
		Iter	_curentElemPtr;

		public	:
		random_access_iterator(void);
		random_access_iterator(const Iter &initValue);
		random_access_iterator(const random_access_iterator &src);
		random_access_iterator &operator=(const random_access_iterator &rhs);
		virtual ~random_access_iterator(void);
		const Iter 	&base(void);

		reference				operator*(void);
		reference				operator->(const difference_type &offset);
		random_access_iterator	&operator++(void); // pre-increment
		random_access_iterator	&operator--(void); // pre-decrement
		random_access_iterator	operator++(int);
		random_access_iterator	operator--(int);
		random_access_iterator	operator+(const difference_type &offset) const;
		random_access_iterator	operator-(const difference_type &offset) const;
		difference_type			operator-(const random_access_iterator &rhs) const;
		random_access_iterator	&operator+=(const difference_type &offset); // compound assignement
		random_access_iterator	&operator-=(const difference_type &offset); // compound assignement
		reference				operator[](const difference_type &offset);
	};

	template<typename IterL, typename IterR>
	bool	operator==(const random_access_iterator<IterL> &lhs,
			const random_access_iterator<IterR> &rhs)
	{ return (lhs.base() == rhs.base()); }
	//A faire via des template pour comparer avec les const et volatiles
	//TODO
	//overload de operator+ avec friend pour difference_type
}

#endif

#ifndef RANDOM_ACCESS_ITERATOR_H
# define RANDOM_ACCESS_ITERATOR_H

# include "iterator.hpp"
# include <cstddef>

namespace ft
{
	template<class T>
	class random_access_iterator : public iterator<ft::random_access_iterator_tag, T> // changer ft par std pour tester algo
	{
		public	:
		random_access_iterator(pointer initValue = NULL);
		random_access_iterator(const random_access_iterator &src);
		random_access_iterator &operator=(const random_access_iterator &rhs);
		virtual ~random_access_iterator(void);

		bool					operator==(const random_access_iterator &rhs) const;
		bool					operator!=(const random_access_iterator &rhs) const;
		reference				operator*(void);
		reference				operator->(const difference_type &offset);
		random_access_iterator	&operator++(void); // pre-increment
		random_access_iterator	&operator--(void); // pre-decrement
		random_access_iterator	operator++(int);
		random_access_iterator	operator--(int);
		random_access_iterator	operator+(const difference_type &offset) const;
		random_access_iterator	operator-(const difference_type &offset) const;
		difference_type			operator-(const random_access_iterator &rhs) const;
		bool					operator<(const random_access_iterator &rhs) const;
		bool					operator>(const random_access_iterator &rhs) const;
		bool					operator<=(const random_access_iterator &rhs) const;
		bool					operator>=(const random_access_iterator &rhs) const;
		random_access_iterator	&operator+=(const difference_type &offset); // compound assignement
		random_access_iterator	&operator-=(const difference_type &offset); // compound assignement
		reference				operator[](const difference_type &offset);


		//TODO
		//overload de operator+ avec friend pour difference_type

		private	:
		pointer	_curentElemPtr;
	};

}

#endif

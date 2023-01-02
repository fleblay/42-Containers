#ifndef RANDOM_ACCESS_ITERATOR_T
# define RANDOM_ACCESS_ITERATOR_T

# ifndef RANDOM_ACCESS_ITERATOR_H
#  error __FILE__ should only be included via random_access_iterator.hpp
# endif

#include "containers.hpp" // DEBUG
#include <iostream> // for printer

namespace ft
{
	template<typename Iter>
	random_access_iterator<Iter>::random_access_iterator(void)
	{
		DEBUG_PRINT("ft::random_access_iterator : default constructor")
		_curentElemPtr = Iter();
		return ;
	}

	template<typename Iter>
	random_access_iterator<Iter>::random_access_iterator(const Iter &initValue)
	{
		DEBUG_PRINT("ft::random_access_iterator : parametric constructor")
		_curentElemPtr = Iter(initValue);
		return ;
	}

	template<typename Iter> template <typename IterR>
	random_access_iterator<Iter>::random_access_iterator(const random_access_iterator<IterR> &src)
	{
		DEBUG_PRINT("ft::random_access_iterator : copy constructor")
		if (*this != src)
			*this = src;
		return ;
	}

	template<typename Iter> template <typename IterR>
	random_access_iterator<Iter> &random_access_iterator<Iter>::operator=(const random_access_iterator<IterR> &rhs)
	{
		DEBUG_PRINT("ft::random_access_iterator : assignation overload")
		this->_curentElemPtr = rhs.base();
		return *this;
	}

	template<typename Iter>
	random_access_iterator<Iter>::~random_access_iterator(void)
	{
		DEBUG_PRINT("ft::random_access_iterator : default destructor")
		_curentElemPtr = Iter();
		return ;
	}

	template<typename Iter>
	const Iter &random_access_iterator<Iter>::base(void) const
	{
		DEBUG_PRINT("ft::random_access_iterator : base")
		return (_curentElemPtr);
	}

	template<typename Iter>
	typename random_access_iterator<Iter>::reference	random_access_iterator<Iter>::operator*(void)
	{
		DEBUG_PRINT("ft::random_access_iterator : operator*")
		return (*_curentElemPtr);
	}

	template<typename Iter>
	typename random_access_iterator<Iter>::pointer	random_access_iterator<Iter>::operator->(void)
	{
		DEBUG_PRINT("ft::random_access_iterator : operator->")
		return (_curentElemPtr);
	}

	template<typename Iter>
	random_access_iterator<Iter> &random_access_iterator<Iter>::operator++(void)
	{
		DEBUG_PRINT("ft::random_access_iterator : pre-increment")
		++_curentElemPtr;
		return *this;
	}

	template<typename Iter>
	random_access_iterator<Iter> &random_access_iterator<Iter>::operator--(void)
	{
		DEBUG_PRINT("ft::random_access_iterator : pre-decrement")
		--_curentElemPtr;
		return *this;
	}

	template<typename Iter>
	random_access_iterator<Iter> random_access_iterator<Iter>::operator++(int)
	{
		DEBUG_PRINT("ft::random_access_iterator : post-increment")
		random_access_iterator	tmp(_curentElemPtr);
		++_curentElemPtr;
		return tmp;
	}

	template<typename Iter>
	random_access_iterator<Iter> random_access_iterator<Iter>::operator--(int)
	{
		DEBUG_PRINT("ft::random_access_iterator : post-decrement")
		random_access_iterator	tmp(_curentElemPtr);
		--_curentElemPtr;
		return tmp;
	}

	template<typename Iter>
	random_access_iterator<Iter>	random_access_iterator<Iter>::operator+(const difference_type &offset) const
	{
		DEBUG_PRINT("ft::random_access_iterator : operator+")
		random_access_iterator	tmp(_curentElemPtr + offset);
		return tmp;
	}

	template<typename Iter>
	random_access_iterator<Iter>	random_access_iterator<Iter>::operator-(const difference_type &offset) const
	{
		DEBUG_PRINT("ft::random_access_iterator : operator-")
		random_access_iterator	tmp(_curentElemPtr - offset);
		return tmp;
	}

	template<typename Iter>
	typename random_access_iterator<Iter>::difference_type	random_access_iterator<Iter>::operator-(const random_access_iterator &rhs) const
	{
		DEBUG_PRINT("ft::random_access_iterator : difference operator-")
		return (_curentElemPtr - rhs._curentElemPtr);
	}

	template<typename Iter>
	random_access_iterator<Iter> &random_access_iterator<Iter>::operator+=(const difference_type &offset)
	{
		DEBUG_PRINT("ft::random_access_iterator : compound assignement +=")
		_curentElemPtr += offset;
		return *this;
	}

	template<typename Iter>
	random_access_iterator<Iter> &random_access_iterator<Iter>::operator-=(const difference_type &offset)
	{
		DEBUG_PRINT("ft::random_access_iterator : compound assignement -=")
		_curentElemPtr -= offset;
		return *this;
	}

	template<typename Iter>
	typename random_access_iterator<Iter>::reference	random_access_iterator<Iter>::operator[](const difference_type &offset)
	{
		DEBUG_PRINT("ft::random_access_iterator : operator[]")
		return (_curentElemPtr[offset]);
	}

	//Implementation dans le hpp car ne fonctionne pas ici
	//Forward declaration de la fonction template a faire avant de la friend

	template<typename IterL, typename IterR>
	bool	operator==(const random_access_iterator<IterL> &lhs,
			const random_access_iterator<IterR> &rhs)
	{
		DEBUG_PRINT("ft::random_access_iterator : operator==")
		return (lhs.base() == rhs.base());
	}

	template<typename IterL, typename IterR>
	bool	operator!=(const random_access_iterator<IterL> &lhs,
			const random_access_iterator<IterR> &rhs)
	{
		DEBUG_PRINT("ft::random_access_iterator : operator!=")
		return (lhs.base() != rhs.base());
	}

	template<typename IterL, typename IterR>
	bool	operator>(const random_access_iterator<IterL> &lhs,
			const random_access_iterator<IterR> &rhs)
	{
		DEBUG_PRINT("ft::random_access_iterator : operator>")
		return (lhs.base() > rhs.base());
	}

	template<typename IterL, typename IterR>
	bool	operator<(const random_access_iterator<IterL> &lhs,
			const random_access_iterator<IterR> &rhs)
	{
		DEBUG_PRINT("ft::random_access_iterator : operator<")
		return (lhs.base() < rhs.base());
	}

	template<typename IterL, typename IterR>
	bool	operator>=(const random_access_iterator<IterL> &lhs,
			const random_access_iterator<IterR> &rhs)
	{
		DEBUG_PRINT("ft::random_access_iterator : operator>=")
		return (lhs.base() >= rhs.base());
	}

	template<typename IterL, typename IterR>
	bool	operator<=(const random_access_iterator<IterL> &lhs,
			const random_access_iterator<IterR> &rhs)
	{
		DEBUG_PRINT("ft::random_access_iterator : operator<=")
		return (lhs.base() <= rhs.base());
	}

};
#endif


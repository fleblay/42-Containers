#ifndef REVERSE_ITERATOR_T
# define REVERSE_ITERATOR_T

# ifndef REVERSE_ITERATOR_H
#  error __FILE__ should only be included via reverse_iterator.hpp
# endif

#include "containers.hpp" // DEBUG
#include <iostream> // for printer

namespace ft
{
	template<typename Iter>
	reverse_iterator<Iter>::reverse_iterator(void)
	{
		DEBUG_PRINT("ft::reverse_iterator : default constructor")
		_nonReverseIter = Iter();
		return ;
	}

	template<typename Iter>
	reverse_iterator<Iter>::reverse_iterator(iterator_type initValue)
	{
		DEBUG_PRINT("ft::reverse_iterator : parametric constructor")
		_nonReverseIter = Iter(initValue);
		return ;
	}

	template<typename Iter> template <typename IterR>
	reverse_iterator<Iter>::reverse_iterator(const reverse_iterator<IterR> &src)
	{
		DEBUG_PRINT("ft::reverse_iterator : copy constructor")
		if (*this != src)
			*this = src;
		return ;
	}

	template<typename Iter> template <typename IterR>
	reverse_iterator<Iter> &reverse_iterator<Iter>::operator=(const reverse_iterator<IterR> &rhs)
	{
		DEBUG_PRINT("ft::reverse_iterator : assignation overload")
		this->_nonReverseIter = rhs.base();
		return *this;
	}

	template<typename Iter>
	reverse_iterator<Iter>::~reverse_iterator(void)
	{
		DEBUG_PRINT("ft::reverse_iterator : default destructor")
		_nonReverseIter = Iter();
		return ;
	}

	template<typename Iter>
	typename reverse_iterator<Iter>::iterator_type reverse_iterator<Iter>::base(void) const
	{
		DEBUG_PRINT("ft::reverse_iterator : base")
		return (_nonReverseIter);
	}

	template<typename Iter>
	typename reverse_iterator<Iter>::reference	reverse_iterator<Iter>::operator*(void) const
	{
		DEBUG_PRINT("ft::reverse_iterator : operator*")
		iterator_type tmp = _nonReverseIter;
		return (*--tmp);
	}

	template<typename Iter>
	typename reverse_iterator<Iter>::pointer	reverse_iterator<Iter>::operator->(void) const
	{
		DEBUG_PRINT("ft::reverse_iterator : operator->")
		return (&(operator*()));
	}

	template<typename Iter>
	reverse_iterator<Iter> &reverse_iterator<Iter>::operator++(void)
	{
		DEBUG_PRINT("ft::reverse_iterator : pre-increment")
		--_nonReverseIter;
		return *this;
	}

	template<typename Iter>
	reverse_iterator<Iter> &reverse_iterator<Iter>::operator--(void)
	{
		DEBUG_PRINT("ft::reverse_iterator : pre-decrement")
		++_nonReverseIter;
		return *this;
	}

	template<typename Iter>
	reverse_iterator<Iter> reverse_iterator<Iter>::operator++(int)
	{
		DEBUG_PRINT("ft::reverse_iterator : post-increment")
		reverse_iterator	tmp(_nonReverseIter);
		--_nonReverseIter;
		return tmp;
	}

	template<typename Iter>
	reverse_iterator<Iter> reverse_iterator<Iter>::operator--(int)
	{
		DEBUG_PRINT("ft::reverse_iterator : post-decrement")
		reverse_iterator	tmp(_nonReverseIter);
		++_nonReverseIter;
		return tmp;
	}

	template<typename Iter>
	reverse_iterator<Iter>	reverse_iterator<Iter>::operator+(difference_type offset) const
	{
		DEBUG_PRINT("ft::reverse_iterator : operator+")
		reverse_iterator	tmp(_nonReverseIter - offset);
		return tmp;
	}

	template<typename Iter>
	reverse_iterator<Iter>	reverse_iterator<Iter>::operator-(difference_type offset) const
	{
		DEBUG_PRINT("ft::reverse_iterator : operator-")
		reverse_iterator	tmp(_nonReverseIter + offset);
		return tmp;
	}

	template<typename Iter>
	typename reverse_iterator<Iter>::difference_type	reverse_iterator<Iter>::operator-(const reverse_iterator &rhs) const
	{
		DEBUG_PRINT("ft::reverse_iterator : difference operator-")
		return (rhs._nonReverseIter - _nonReverseIter);
	}

	template<typename Iter>
	reverse_iterator<Iter> &reverse_iterator<Iter>::operator+=(difference_type offset)
	{
		DEBUG_PRINT("ft::reverse_iterator : compound assignement +=")
		_nonReverseIter -= offset;
		return *this;
	}

	template<typename Iter>
	reverse_iterator<Iter> &reverse_iterator<Iter>::operator-=(difference_type offset)
	{
		DEBUG_PRINT("ft::reverse_iterator : compound assignement -=")
		_nonReverseIter += offset;
		return *this;
	}

	template<typename Iter>
	typename reverse_iterator<Iter>::reference	reverse_iterator<Iter>::operator[](difference_type offset) const
	{
		DEBUG_PRINT("ft::reverse_iterator : operator[]")
		return (*(*this + offset));
	}

	//Implementation dans le hpp car ne fonctionne pas ici
	//Forward declaration de la fonction template a faire avant de la friend

	template<typename IterL, typename IterR>
	bool	operator==(const reverse_iterator<IterL> &lhs,
			const reverse_iterator<IterR> &rhs)
	{
		DEBUG_PRINT("ft::reverse_iterator : operator==")
		return (lhs.base() == rhs.base());
	}

	template<typename IterL, typename IterR>
	bool	operator!=(const reverse_iterator<IterL> &lhs,
			const reverse_iterator<IterR> &rhs)
	{
		DEBUG_PRINT("ft::reverse_iterator : operator!=")
		return (lhs.base() != rhs.base());
	}

	template<typename IterL, typename IterR>
	bool	operator>(const reverse_iterator<IterL> &lhs,
			const reverse_iterator<IterR> &rhs)
	{
		DEBUG_PRINT("ft::reverse_iterator : operator>")
		return (lhs.base() < rhs.base());
	}

	template<typename IterL, typename IterR>
	bool	operator<(const reverse_iterator<IterL> &lhs,
			const reverse_iterator<IterR> &rhs)
	{
		DEBUG_PRINT("ft::reverse_iterator : operator<")
		return (lhs.base() > rhs.base());
	}

	template<typename IterL, typename IterR>
	bool	operator>=(const reverse_iterator<IterL> &lhs,
			const reverse_iterator<IterR> &rhs)
	{
		DEBUG_PRINT("ft::reverse_iterator : operator>=")
		return (lhs.base() <= rhs.base());
	}

	template<typename IterL, typename IterR>
	bool	operator<=(const reverse_iterator<IterL> &lhs,
			const reverse_iterator<IterR> &rhs)
	{
		DEBUG_PRINT("ft::reverse_iterator : operator<=")
		return (lhs.base() >= rhs.base());
	}

};
#endif



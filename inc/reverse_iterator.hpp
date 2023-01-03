#ifndef REVERSE_ITERATOR_H
# define REVERSE_ITERATOR_H

# include "iterator.hpp"
# include <cstddef>
# include "containers.hpp"

namespace ft
{
	//Iter is a random_access_iterator, or a const variant
	template<typename Iter>
	class reverse_iterator : public ft::iterator<ft::random_access_iterator_tag, Iter>
	{
		public	:
		typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<Iter>::value_type value_type;
		typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
		typedef typename ft::iterator_traits<Iter>::reference reference;
		typedef typename ft::iterator_traits<Iter>::pointer pointer;
		typedef Iter iterator_type;

		private	:
		Iter	_nonReverseIter;

		public	:
		reverse_iterator(void);
		explicit reverse_iterator(iterator_type initValue);
		template<typename IterR>
		reverse_iterator(const reverse_iterator<IterR> &src);
		template<typename IterR>
		reverse_iterator &operator=(const reverse_iterator<IterR> &rhs);
		virtual ~reverse_iterator(void);

		iterator_type	base(void) const;

		reference			operator*(void) const;
		pointer				operator->(void) const;
		reverse_iterator	&operator++(void);
		reverse_iterator	&operator--(void);
		reverse_iterator	operator++(int);
		reverse_iterator	operator--(int);
		reverse_iterator	operator+(difference_type offset) const;
		reverse_iterator	operator-(difference_type offset) const;
		difference_type			operator-(const reverse_iterator &rhs) const;
		reverse_iterator	&operator+=(difference_type offset);
		reverse_iterator	&operator-=(difference_type offset);
		reference				operator[](difference_type offset) const;
		friend reverse_iterator	operator+(difference_type offset, const reverse_iterator &rhs)
		{
			DEBUG_PRINT("ft::reverse_iterator : friend operator+")
			return (reverse_iterator(rhs.base() - offset));
		}
	};

	template<typename IterL, typename IterR>
	bool	operator==(const reverse_iterator<IterL> &lhs,
			const reverse_iterator<IterR> &rhs);
	template<typename IterL, typename IterR>
	bool	operator!=(const reverse_iterator<IterL> &lhs,
			const reverse_iterator<IterR> &rhs);
	template<typename IterL, typename IterR>
	bool	operator>(const reverse_iterator<IterL> &lhs,
			const reverse_iterator<IterR> &rhs);
	template<typename IterL, typename IterR>
	bool	operator<(const reverse_iterator<IterL> &lhs,
			const reverse_iterator<IterR> &rhs);
	template<typename IterL, typename IterR>
	bool	operator>=(const reverse_iterator<IterL> &lhs,
			const reverse_iterator<IterR> &rhs);
	template<typename IterL, typename IterR>
	bool	operator<=(const reverse_iterator<IterL> &lhs,
			const reverse_iterator<IterR> &rhs);
}

# include "reverse_iterator.tpp"

#endif

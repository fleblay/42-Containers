#ifndef NODE_ITERATOR_H
# define NODE_ITERATOR_H

# include "iterator.hpp"
# include "rbtree.hpp"
# include <cstddef>
# include "containers.hpp" // for debug

namespace ft
{
	template<typename T>
	class node_iterator : public ft::iterator<std::bidirectional_iterator_tag, T> // changer ft par std pour tester algo
	{
		public	:
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef T										value_type;
		typedef ptrdiff_t								difference_type;
		typedef value_type&							reference;
		typedef value_type*							pointer;
		typedef node<T>* node_pointer;

		private	:
		node_pointer	_root;
		node_pointer	_current;
		node_pointer	_leaf;

		public	:
		node_iterator(void) : _root(NULL), _current(NULL), _leaf(NULL)
		{
			DEBUG_PRINT("ft::node_iterator : default constructor")
		}
		virtual ~node_iterator(void)
		{
			DEBUG_PRINT("ft::node_iterator : default destructor")
		}
		template<typename TR>
		node_iterator(const node_iterator<TR> &src)
		{
			DEBUG_PRINT("ft::node_iterator : copy constructor")
			*this = src;
		}
		template<typename TR>
		node_iterator &operator=(const node_iterator<TR> &rhs)
		{
			DEBUG_PRINT("ft::node_iterator : operator=")
			this->_root = rhs._root;
			this->_current = rhs._current;
			this->_leaf = rhs._leaf;
		}
		/*

		//Fonction pour les operateurs de comparaison
		const T	&base(void) const;

		//Va renvoyer la valeur pointee par _currentElemPtr, ie acceder a la val pointee par le
		//pointer de type iter qui est dans le node_iterator
		reference				operator*(void) const;
		pointer					operator->(void) const ;
		node_iterator	&operator++(void); // pre-increment
		node_iterator	&operator--(void); // pre-decrement
		node_iterator	operator++(int);
		node_iterator	operator--(int);
		node_iterator	operator+(difference_type offset) const;
		node_iterator	operator-(difference_type offset) const;
		difference_type			operator-(const node_iterator &rhs) const;
		node_iterator	&operator+=(difference_type offset); // compound assignement
		node_iterator	&operator-=(difference_type offset); // compound assignement
		reference				operator[](difference_type offset);
		friend node_iterator	operator+(difference_type offset, const node_iterator &rhs)
		{
			DEBUG_PRINT("ft::node_iterator : friend operator+")
			return (node_iterator(rhs.base() + offset));
		}
		*/

	};

	//A faire via des template pour comparer avec les T, avec les const T et volatile T
	/*
	template<typename TL, typename TR>
	bool	operator==(const node_iterator<TL> &lhs,
			const node_iterator<TR> &rhs);
	template<typename TL, typename TR>
	bool	operator!=(const node_iterator<TL> &lhs,
			const node_iterator<TR> &rhs);
	template<typename TL, typename TR>
	bool	operator>(const node_iterator<TL> &lhs,
			const node_iterator<TR> &rhs);
	template<typename TL, typename TR>
	bool	operator<(const node_iterator<TL> &lhs,
			const node_iterator<TR> &rhs);
	template<typename TL, typename TR>
	bool	operator>=(const node_iterator<TL> &lhs,
			const node_iterator<TR> &rhs);
	template<typename TL, typename TR>
	bool	operator<=(const node_iterator<TL> &lhs,
			const node_iterator<TR> &rhs);
	*/
}

#include "node_iterator.tpp"

#endif

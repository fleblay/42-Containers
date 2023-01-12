#ifndef CONST_NODE_ITERATOR_H
# define CONST_NODE_ITERATOR_H

# include "iterator.hpp"
# include "rbtree.hpp"
# include <cstddef>
# include "containers.hpp" // for debug
# include "node_iterator.hpp" // for construction of const_node_iterator from node_iterator

namespace ft
{
	template<typename T>
	class const_node_iterator : public ft::iterator<std::bidirectional_iterator_tag, T>
	{
		public	:
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef T									value_type;
		typedef ptrdiff_t							difference_type;
		typedef const value_type&					reference;
		typedef const value_type*					pointer;
		typedef node<T>								node_type;
		typedef const node_type*					const_node_pointer;

		private	:
		const_node_pointer	_current;

		public	:
		const_node_iterator(void) : _current(NULL)
		{
			DEBUG_PRINT("ft::CONST_node_iterator : default constructor")
		}

		//to test
		const_node_iterator(const const_node_pointer &initValue) : _current(initValue)
		{
			DEBUG_PRINT("ft::CONST_node_iterator : parametric constructor")
		}

		virtual ~const_node_iterator(void)
		{
			DEBUG_PRINT("ft::CONST_node_iterator : default destructor")
		}

		const_node_iterator(const const_node_iterator &src)
		{
			DEBUG_PRINT("ft::CONST_node_iterator : copy constructor")
			*this = src;
		}

		//to test
		const const_node_pointer &base(void) const
		{
			DEBUG_PRINT("ft::CONST_node_iterator : base")
			return (_current);
		}

		const_node_iterator &operator=(const const_node_iterator &rhs)
		{
			DEBUG_PRINT("ft::CONST_node_iterator : operator=")
			this->_current = rhs._current;
			return (*this);
		}

		//From normal to const
		const_node_iterator &operator=(const node_iterator<T> &rhs)
		{
			DEBUG_PRINT("ft::CONST_node_iterator : operator= from node_iterator")
			this->_current = rhs.base();
			return (*this);
		}

		const_node_iterator(const node_iterator<T> &src)
		{
			DEBUG_PRINT("ft::CONST_node_iterator : copy constructor from node_iterator")
			this->_current = src.base();
			*this = src;
		}

		reference	operator*(void) const
		{
			DEBUG_PRINT("ft::CONST_node_iterator : operator*")
			return (*(_current->data));
		}	
	};
}

#endif


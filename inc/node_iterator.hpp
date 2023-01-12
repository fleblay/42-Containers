#ifndef NODE_ITERATOR_H
# define NODE_ITERATOR_H

# include "iterator.hpp"
# include "rbtree.hpp"
# include <cstddef>
# include "containers.hpp" // for debug

namespace ft
{
	template<typename T>
	class node_iterator : public ft::iterator<std::bidirectional_iterator_tag, T>
	{
		public	:
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef T									value_type;
		typedef ptrdiff_t							difference_type;
		typedef value_type&							reference;
		typedef value_type*							pointer;
		typedef node<T>								node_type;
		typedef node_type*							node_pointer;

		private	:
		node_pointer	_current;

		public	:
		node_iterator(void) :_current(NULL)
		{
			DEBUG_PRINT("ft::node_iterator : default constructor")
		}

		//to test
		node_iterator(const node_pointer &initValue) : _current(initValue)
		{
			DEBUG_PRINT("ft::node_iterator : parametric constructor")
		}

		virtual ~node_iterator(void)
		{
			DEBUG_PRINT("ft::node_iterator : default destructor")
		}

		const node_pointer &base(void) const
		{
			DEBUG_PRINT("ft::node_iterator : base")
			return (_current);
		}

		node_iterator(const node_iterator &src)
		{
			DEBUG_PRINT("ft::node_iterator : copy constructor")
			*this = src;
		}

		node_iterator &operator=(const node_iterator &rhs)
		{
			DEBUG_PRINT("ft::node_iterator : operator=")
			this->_current = rhs._current;
			return (*this);
		}

		reference	operator*(void) const
		{
			DEBUG_PRINT("ft::node_iterator : operator*")
			return (*(_current->data));
		}	
	};
}

#endif

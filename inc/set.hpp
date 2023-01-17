#ifndef SET_H
# define SET_H

# include <memory>
# include "reverse_iterator.hpp"
# include "is_integral.hpp"
# include "enable_if.hpp"
# include "rbtree.hpp"
# include "node_iterator.hpp"
# include "const_node_iterator.hpp"
# include <iterator> //For the tags
#include "lexicographical_compare.hpp"
#include "equal.hpp"

namespace ft
{
	template < class T,
			 class Compare = std::less<T>,
			 class Alloc = std::allocator<T>
			 >
	class set
	{
		//TYPES
		public	:
		typedef	T													key_type;
		typedef	T													value_type;
		typedef Compare												key_compare;
		typedef Compare												value_compare;

		typedef	Alloc												allocator_type;
		typedef	typename allocator_type::reference					reference;
		typedef	typename allocator_type::const_reference			const_reference;
		typedef	typename allocator_type::pointer					pointer;
		typedef	typename allocator_type::const_pointer				const_pointer;

		typedef	typename ft::const_node_iterator<value_type>				iterator;
		typedef	typename ft::const_node_iterator<value_type>		const_iterator;

		typedef	typename ft::reverse_iterator<iterator>				reverse_iterator;
		typedef	typename ft::reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef	typename allocator_type::difference_type			difference_type;
		typedef	typename allocator_type::size_type					size_type;

		typedef typename ft::rbtree<value_type, value_compare>		tree;

		//CONSTRUCTOR AND DESTRUCTOR

		public	:
		explicit set(const key_compare &comp = key_compare(),
				const allocator_type &alloc = allocator_type()) :
			_comp(comp),
			_alloc(alloc),
			_tree(_comp)
		{
			DEBUG_PRINT("ft::set default constructor")
		}

		template <class InputIterator>
		set(InputIterator first, InputIterator last,
				const key_compare &comp = key_compare(),
				const allocator_type &alloc = allocator_type()) :
			_comp(comp),
			_alloc(alloc),
			_tree(_comp)
		{
			DEBUG_PRINT("ft::set range constructor")
			insert(first, last);
		}

		set(const set &x) :
			_comp(value_compare()),
			_alloc(allocator_type()),
			_tree(_comp)
		{
			DEBUG_PRINT("ft::set copy constructor")
			*this = x;
		}

		~set(void)
		{
			DEBUG_PRINT("ft::set default destructor")
			_tree.destroyTree();
		}

		set	&operator=(const set &x)
		{
			DEBUG_PRINT("ft::set operator=")
			this->_comp = x._comp;
			this->_alloc = x._alloc;
			_tree.destroyTree();
			_tree.createLeaf();
			insert(x.begin(), x.end());
			return (*this);
		}

		//FUNCTIONS : ITERATOR
		public	:

		iterator				end(void)
		{
			DEBUG_PRINT("ft::set : end")
			return iterator(_tree.getEnd(), _tree.getRoot(), _tree.getEnd());
		}

		const_iterator			end(void) const
		{
			DEBUG_PRINT("ft::set : const end")
			return const_iterator(_tree.getEnd(), _tree.getRoot(), _tree.getEnd());
		}

		iterator				begin(void)
		{
			DEBUG_PRINT("ft::set : begin")
			if (empty())
				return (end());
			else
				return iterator(_tree.findMin(), _tree.getRoot(), _tree.getEnd());
		}

		const_iterator			begin(void) const
		{
			DEBUG_PRINT("ft::set : const begin")
			if (empty())
				return (end());
			else
				return const_iterator(_tree.findMin(), _tree.getRoot(), _tree.getEnd());
		}

		reverse_iterator		rbegin(void)
		{
			DEBUG_PRINT("ft::set : rbegin")
			return reverse_iterator(end());
		}

		const_reverse_iterator			rbegin(void) const
		{
			DEBUG_PRINT("ft::set : const rbegin")
			return const_reverse_iterator(end());
		}

		reverse_iterator				rend(void)
		{
			DEBUG_PRINT("ft::set : rend")
			return reverse_iterator(begin());
		}

		const_reverse_iterator			rend(void) const
		{
			DEBUG_PRINT("ft::set : const end")
			return const_reverse_iterator(begin());
		}

		//FUNCTIONS : CAPACITY
		bool	empty(void) const
		{
			DEBUG_PRINT("ft::set : empty")
			return (!_tree.getSize());
		}

		size_type	size(void) const
		{
			DEBUG_PRINT("ft::set : size")
			return (_tree.getSize());
		}

		size_type		max_size(void) const
		{
			DEBUG_PRINT("ft::set : max_size")
			return (_tree.max_size());
		}

		//FUNCTIONS : MODIFIERS
		public	:

		pair<iterator, bool>	insert(const value_type &val)
		{
			DEBUG_PRINT("ft::set insert : single element")
			if (_tree.findNode(val))
			{
				DEBUG_PRINT("ft::set insert : T already existed")
				return (ft::make_pair<iterator, bool>(iterator(_tree.findNode(val),_tree.getRoot(), _tree.getEnd()) , false));
			}
			else
			{
				DEBUG_PRINT("ft::set insert : T did not exist -> inserting it")
				_tree.insert(val);
				return (ft::make_pair<iterator, bool>(iterator(_tree.findNode(val),_tree.getRoot(), _tree.getEnd()) , true));
			}
		}

		iterator	insert(iterator position, const value_type &val)
		{
			DEBUG_PRINT("ft::set insert : single element with int")
			(void)position;
			iterator	ret = insert(val).first;
			return (ret);
		}

		template <class InputIterator>
		void	insert(InputIterator first, InputIterator last)
		{
			DEBUG_PRINT("ft::set insert : range")
			for (; first != last; first++)
				insert(*first);
		}

		size_type	erase(const value_type &val)
		{
			DEBUG_PRINT("ft::set erase : key")
			iterator	find = iterator(_tree.findNode(val), _tree.getRoot(), _tree.getEnd());

			if (find.base() == NULL)
				return (0);
			else
			{
				erase(find);
				return (1);
			}
		}

		void	erase(iterator position)
		{
			DEBUG_PRINT("ft::set erase : iterator position")
			_tree.deleteNode(*position);
		}

		void	erase(iterator first, iterator last)
		{
			DEBUG_PRINT("ft::set erase : range")
			for (; first != last; )
				erase(first++->first);
		}

		void	swap(set &x)
		{ 
			DEBUG_PRINT("ft::swap")
			value_compare			tmp_comp = this->_comp;
			allocator_type			tmp_alloc = this->_alloc;

			this->_comp = x._comp;
			this->_alloc = x._alloc;

			x._comp = tmp_comp;
			x._alloc = tmp_alloc;

			_tree.swap(x._tree);
		}

		void	clear(void)
		{
			DEBUG_PRINT("ft::clear")
			_tree.destroyTree();
			_tree = tree(_comp);
		}

		//FUNCTIONS : OBSERVERS

		key_compare key_comp(void) const
		{
			DEBUG_PRINT("ft::key_comp")
			return (key_compare());
		}

		value_compare value_comp(void) const
		{
			DEBUG_PRINT("ft::value_compare")
			return (value_compare());
		}

		//FUNCTIONS : OPERATIONS
		iterator	find(const value_type &val) const
		{
			DEBUG_PRINT("ft::set : find")
			iterator	find = iterator(_tree.findNode(val), _tree.getRoot(), _tree.getEnd());
			if (find.base() != NULL)
				return (find);
			return (end());
		}

		size_type count(const value_type &val) const
		{
			DEBUG_PRINT("ft::set : count")
			if (find(val) != end())
				return (1);
			return (0);
		}

		iterator lower_bound(const value_type &val) const
		{
			DEBUG_PRINT("ft::set : lowerBound")
			iterator	lower = iterator(_tree.lowerBound(val), _tree.getRoot(), _tree.getEnd());
			if (lower.base() != NULL)
				return (lower);
			return (end());
		}


		iterator upper_bound(const value_type &val) const
		{
			DEBUG_PRINT("ft::set : upperBound")
			iterator	upper = lower_bound(val);
			if (upper != end() && *upper == val)
				++upper;
			return (upper);
		}

		pair<iterator,iterator> equal_range(const value_type &val) const
		{
			DEBUG_PRINT("ft::set : equal_range")
			return (pair<iterator, iterator>(lower_bound(val), upper_bound(val)));
		}

		//FUNCTIONS : OPERATIONS

		allocator_type get_allocator(void) const
		{
			return (_alloc);
		}

		//ATTRIBUTES
		private	:

		value_compare			_comp;
		allocator_type			_alloc;
		tree					_tree;

	};

	//FUNCTIONS : NON-MEMBER FUNCTION OVERLOADS
	template <class T, class Compare, class Alloc>
	bool operator==(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
	{
		DEBUG_PRINT("ft::set operator==")
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Compare, class Alloc>
	bool operator<(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
	{
		DEBUG_PRINT("ft::set operator<")
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Compare, class Alloc>
	bool operator!=(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
	{
		DEBUG_PRINT("ft::set operator!=")
		return (!(lhs == rhs));
	}

	template <class T, class Compare, class Alloc>
	bool operator>(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
	{
		DEBUG_PRINT("ft::set operator>")
		return (rhs < lhs);
	}

	template <class T, class Compare, class Alloc>
	bool operator<=(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
	{
		DEBUG_PRINT("ft::set operator<=")
		return (!(rhs < lhs));
	}

	template <class T, class Compare, class Alloc>
	bool operator>=(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
	{
		DEBUG_PRINT("ft::set operator>=")
		return (!(lhs < rhs));
	}
}

#endif


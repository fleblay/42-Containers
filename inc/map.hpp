#ifndef MAP_H
# define MAP_H

# include <memory>
# include "reverse_iterator.hpp"
# include "is_integral.hpp"
# include "enable_if.hpp"
# include "rbtree.hpp"
# include "pair.hpp"
# include "node_iterator.hpp"
# include "const_node_iterator.hpp"
# include <iterator> //For the tags
#include "lexicographical_compare.hpp"
#include "equal.hpp"

namespace ft
{
	template < class Key,
			 class T,
			 class Compare = std::less<Key>,
			 class Alloc = std::allocator<pair <const Key, T> >
			 >
	class map
	{
		//TYPES
		public	:
		typedef	Key													key_type;
		typedef	T													mapped_type;
		typedef	typename ft::pair< const key_type, mapped_type >	value_type;
		typedef Compare												key_compare;

		//Class de comparaison qui definit une fonction membre qui permet de comparer les first
		//d'une pair. On l'instanciera avec la fonction Compare (par defaut Less)
		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class map;
			//friend class ft::rbtree<value_type, value_compare>;

			protected :
			Compare comp; //member of class which is an instance of a comp fx from template parameter Compare
			value_compare (Compare c) : comp(c) {} //default constructor of value_compare class
			//value_compare (const value_compare &src) { comp = src.comp;} //copy constructor of value_compare class

			public  :
			bool operator() (const value_type &x, const value_type &y) const
			{ return comp(x.first, y.first); }
		};

		typedef	Alloc												allocator_type;
		typedef	typename allocator_type::reference					reference;
		typedef	typename allocator_type::const_reference			const_reference;
		typedef	typename allocator_type::pointer					pointer;
		typedef	typename allocator_type::const_pointer				const_pointer;

		typedef	typename ft::node_iterator<value_type>				iterator;
		typedef	typename ft::const_node_iterator<value_type>		const_iterator;

		typedef	typename ft::reverse_iterator<iterator>				reverse_iterator;
		typedef	typename ft::reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef	typename allocator_type::difference_type			difference_type;
		typedef	typename allocator_type::size_type					size_type;

		typedef typename ft::rbtree<value_type, value_compare>		tree;

		//CONSTRUCTOR AND DESTRUCTOR

		public	:
		explicit map(const key_compare &comp = key_compare(),
				const allocator_type &alloc = allocator_type()) :
			_comp(value_compare(comp)),
			_alloc(alloc),
			_tree(_comp)
		{
			DEBUG_PRINT("ft::map default constructor")
		}

		template <class InputIterator>
		map(InputIterator first, InputIterator last,
				const key_compare &comp = key_compare(),
				const allocator_type &alloc = allocator_type()) :
			_comp(value_compare(comp)),
			_alloc(alloc),
			_tree(_comp)
		{
			DEBUG_PRINT("ft::map range constructor")
			insert(first, last);
		}

		map(const map &x) :
			_comp(value_compare(key_compare())),
			_alloc(allocator_type()),
			_tree(_comp)
		{
			DEBUG_PRINT("ft::map copy constructor")
			*this = x;
		}

		~map(void)
		{
			DEBUG_PRINT("ft::map default destructor")
			_tree.destroyTree();
		}

		map	&operator=(const map &x)
		{
			DEBUG_PRINT("ft::map operator=")
			this->_comp = x._comp;
			this->_alloc = x._alloc;
			_tree.destroyTree();
			insert(x.begin(), x.end());
			return (*this);
		}

		//FUNCTIONS : ITERATOR
		public	:

		iterator				begin(void)
		{
			DEBUG_PRINT("ft::map : begin")
			return iterator(_tree.findMin());
		}

		const_iterator			begin(void) const
		{
			DEBUG_PRINT("ft::map : const begin")
			return const_iterator(_tree.findMin());
		}

		iterator				end(void)
		{
			DEBUG_PRINT("ft::map : end")
			if (this->empty())
				return (begin());
			return iterator(_tree.findMax()->right);
		}

		const_iterator			end(void) const
		{
			DEBUG_PRINT("ft::map : const end")
			if (this->empty())
				return (begin());
			return const_iterator(_tree.findMax()->right);
		}

		reverse_iterator		rbegin(void)
		{
			DEBUG_PRINT("ft::map : rbegin")
			return reverse_iterator(end());
		}

		const_reverse_iterator			rbegin(void) const
		{
			DEBUG_PRINT("ft::map : const rbegin")
			return const_reverse_iterator(end());
		}

		reverse_iterator				rend(void)
		{
			DEBUG_PRINT("ft::map : rend")
			return reverse_iterator(begin());
		}

		const_reverse_iterator			rend(void) const
		{
			DEBUG_PRINT("ft::map : const end")
			return const_reverse_iterator(begin());
		}

		//FUNCTIONS : CAPACITY
		bool	empty(void) const
		{
			DEBUG_PRINT("ft::map : empty")
			return (!_tree.getSize());
		}

		size_type	size(void) const
		{
			DEBUG_PRINT("ft::map : size")
			return (_tree.getSize());
		}

		size_type		max_size(void) const
		{
			DEBUG_PRINT("ft::map : max_size")
			return (_alloc.max_size());
		}

		//FUNCTIONS : ELEMENT ACCESS
		mapped_type		&operator[](const key_type &k)
		{
			DEBUG_PRINT("ft::map : operator[]")
			return ((*((this->insert(ft::make_pair(k,mapped_type()))).first)).second);
		}

		//FUNCTIONS : MODIFIERS
		public	:

		pair<iterator, bool>	insert(const value_type &val)
		{
			DEBUG_PRINT("ft::map insert : single element")
			if (_tree.findNode(val))
			{
				DEBUG_PRINT("ft::map insert : Key already existed")
				return (ft::make_pair<iterator, bool>(_tree.findNode(val), false));
			}
			else
			{
				DEBUG_PRINT("ft::map insert : Key did not exist -> inserting it")
				_tree.insert(val);
				return (ft::make_pair<iterator, bool>(_tree.findNode(val), true));
			}
		}

		iterator	insert(iterator position, const value_type &val)
		{
			DEBUG_PRINT("ft::map insert : single element with int")
			(void)position;
			iterator	ret = insert(val).first;
			return (ret);
		}

		template <class InputIterator>
		void	insert(InputIterator first, InputIterator last)
		{
			DEBUG_PRINT("ft::map insert : range")
			for (; first != last; first++)
				insert(*first);
		}

		size_type	erase(const key_type &k)
		{
			DEBUG_PRINT("ft::map erase : key")
			value_type	dummy = value_type(k, mapped_type());
			iterator	find = iterator(_tree.findNode(dummy));

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
			DEBUG_PRINT("ft::map erase : iterator position")
			_tree.deleteNode(*position);
		}

		void	erase(iterator first, iterator last)
		{
			DEBUG_PRINT("ft::map erase : range")
			for (; first != last; )
				erase(first++->first);
		}

		void	swap(map &x)
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
			return (value_compare(key_compare()));
		}

		//FUNCTIONS : OPERATIONS
		iterator	find(const key_type &k)
		{
			DEBUG_PRINT("ft::map : find")
			value_type	dummy = value_type(k, mapped_type());
			iterator	find = iterator(_tree.findNode(dummy));
			if (find.base() != NULL)
				return (find);
			return (end());
		}

		const_iterator	find(const key_type &k) const
		{
			DEBUG_PRINT("ft::map : const find")
			value_type	dummy = value_type(k, mapped_type());
			const_iterator find = const_iterator(_tree.findNode(dummy));
			if (find.base() != NULL)
				return (find);
			return (end());
		}

		size_type count(const key_type &k) const
		{
			DEBUG_PRINT("ft::map : count")
			if (find(k) != end())
				return (1);
			return (0);
		}

		iterator lower_bound(const key_type &k)
		{
			DEBUG_PRINT("ft::map : lowerBound")
			value_type	dummy = value_type(k, mapped_type());
			iterator	lower = iterator(_tree.lowerBound(dummy));
			if (lower.base() != NULL)
				return (lower);
			return (end());
		}

		const_iterator lower_bound(const key_type &k) const
		{
			DEBUG_PRINT("ft::map : const lowerBound")
			value_type	dummy = value_type(k, mapped_type());
			const_iterator	lower = const_iterator(_tree.lowerBound(dummy));
			if (lower.base() != NULL)
				return (lower);
			return (end());
		}

		iterator upper_bound(const key_type &k)
		{
			DEBUG_PRINT("ft::map : upperBound")
			iterator	upper = lower_bound(k);
			if (upper != end() && upper->first == k)
				++upper;
			return (upper);
		}

		const_iterator upper_bound(const key_type &k) const
		{
			DEBUG_PRINT("ft::map : const upperBound")
			const_iterator	upper = lower_bound(k);
			if (upper != end() && upper->first == k)
				++upper;
			return (upper);
		}

		pair<iterator,iterator> equal_range(const key_type &k)
		{
			DEBUG_PRINT("ft::map : equal_range")
			return (pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
		}

		pair<const_iterator,const_iterator> equal_range(const key_type &k) const
		{
			DEBUG_PRINT("ft::map : const equal_range")
			return (pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
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
	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		DEBUG_PRINT("ft::map operator==")
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		DEBUG_PRINT("ft::map operator<")
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		DEBUG_PRINT("ft::map operator!=")
		return (!(lhs == rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		DEBUG_PRINT("ft::map operator>")
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		DEBUG_PRINT("ft::map operator<=")
		return (!(rhs < lhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		DEBUG_PRINT("ft::map operator>=")
		return (!(lhs < rhs));
	}
}

#endif


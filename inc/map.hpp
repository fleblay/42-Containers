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
				const allocator_type &alloc = allocator_type()) :  _comp(value_compare(comp)), _alloc(alloc), _tree(_comp)
		{
			DEBUG_PRINT("ft::map default constructor")
		}

		~map(void)
		{
			DEBUG_PRINT("ft::map default destructor")
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
			return iterator(_tree.findMax()->right);
		}

		const_iterator			end(void) const
		{
			DEBUG_PRINT("ft::map : const end")
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

		//FUNCTIONS : MODIFIERS
		public	:
		pair<iterator, bool>	insert(const value_type &val)
		{
			DEBUG_PRINT("ft::map insert")
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
		//ATTRIBUTES
		private	:

		value_compare			_comp;
		allocator_type			_alloc;
		tree					_tree;

	};
}

#endif


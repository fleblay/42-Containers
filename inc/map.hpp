#ifndef MAP_H
# define MAP_H

# include <memory>
# include "reverse_iterator.hpp"
# include "is_integral.hpp"
# include "enable_if.hpp"
# include "rbtree.hpp"
# include "pair.hpp"
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
		typedef	typename allocator_type::reference					reference; // value_type& for default
		typedef	typename allocator_type::const_reference			const_reference; // const value_type& for default
		typedef	typename allocator_type::pointer					pointer; // value_type* for default
		typedef	typename allocator_type::const_pointer				const_pointer; // const value_type * for default

		typedef	typename ft::random_access_iterator<pointer>		iterator;
		typedef	typename ft::random_access_iterator<const_pointer>	const_iterator;

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

		/*
		explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type());
		template<class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type());
		vector(const vector &x);
		vector	&operator=(const vector &x);
		~vector(void);
		*/

		//FUNCTIONS : ITERATOR
		public	:
		/*
		iterator				begin(void);
		const_iterator			begin(void) const;
		iterator				end(void);
		const_iterator			end(void) const;
		reverse_iterator		rbegin(void);
		const_reverse_iterator	rbegin(void) const;
		reverse_iterator		rend(void);
		const_reverse_iterator	rend(void) const;
		*/

		//FUNCTIONS : CAPACITY

		public	:
		/*
		size_type		size(void) const;
		size_type		max_size(void) const;
		void			resize(size_type n, value_type val = value_type());
		size_type		capacity(void) const;
		bool			empty(void) const;
		void			reserve(size_type n);
		*/

		//FUNCTIONS : ELEMENT ACCESS

		/*
		reference		operator[](size_type n);
		const_reference	operator[](size_type n) const;
		reference		at(size_type n);
		const_reference	at(size_type n) const;
		reference		front(void);
		const_reference	front(void) const;
		reference		back(void);
		const_reference	back(void) const;
		*/

		//FUNCTIONS : MODIFIER

		/*
		void			assign(size_type n, const value_type &val);
		template <class InputIterator>
		void			assign(typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last);
		void			push_back(const value_type &val);
		void			pop_back(void);
		iterator		insert(iterator position, const value_type &val);
		void			insert(iterator position, size_type n, const value_type &val);
//		template <class InputIterator>
//		void			insert(iterator position, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first,
//							InputIterator last);
		template <class InputIterator>
		void			insert(iterator position, InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = 0);
		iterator		erase(iterator position);
		iterator		erase(iterator first, iterator last);
		void			swap(vector &x);
		void			clear(void);

		private	:
		template <class InputIterator>
		void			assign_range(InputIterator first, InputIterator last, std::forward_iterator_tag);
		template <class InputIterator>
		void			assign_range(InputIterator first, InputIterator last, std::input_iterator_tag);
		template <class InputIterator>
		void			insert_range(iterator position, InputIterator first, InputIterator last, std::forward_iterator_tag);
		template <class InputIterator>
		void			insert_range(iterator position, InputIterator first, InputIterator last, std::input_iterator_tag);

		//FUNCTIONS : ALLOCATOR
		allocator_type	get_allocator() const;
		*/

		//ATTRIBUTES
		private	:

		value_compare			_comp;
		allocator_type			_alloc;
		tree					_tree;

	};
	//FUNCTIONS : NON-MEMBER FUNCTION OVERLOADS

	/*
	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

	template <class T, class Alloc>
	void swap(vector<T, Alloc> &x, vector<T, Alloc> &y);
	*/
}

#endif


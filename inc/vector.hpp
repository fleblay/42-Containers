#ifndef VECTOR_H
# define VECTOR_H

# include <memory>
# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		//TYPES
		public	:
		typedef	T													value_type;
		typedef	Alloc												allocator_type;
		typedef	typename allocator_type::reference					reference; // value_type& for default
		typedef	typename allocator_type::const_reference			const_reference; // const value_type& for default
		typedef	typename allocator_type::pointer					pointer; // value_type* for default
		typedef	typename allocator_type::const_pointer				const_pointer; // const value_type * for default
		typedef	typename ft::random_access_iterator<pointer>		iterator; // ft::random_iterator<pointer, vector>
		typedef	typename ft::random_access_iterator<const_pointer>	const_iterator; // ft::random_iterator<pointer, vector>
		typedef	typename ft::reverse_iterator<iterator>				reverse_iterator; // ft::reverse_it<iterator>
		typedef	typename ft::reverse_iterator<const_iterator>		const_reverse_iterator; // ft::reverse_it<iterator>
		typedef	typename allocator_type::difference_type			difference_type;
		typedef	typename allocator_type::size_type					size_type;

		//CONSTRUCTOR AND DESTRUCTOR

		public	:
		explicit vector(const allocator_type &alloc = allocator_type());
		~vector(void);

		//FUNCTIONS : ITERATOR
		public	:
		iterator				begin(void);
		const_iterator			begin(void) const;
		iterator				end(void);
		const_iterator			end(void) const;
		reverse_iterator		rbegin(void);
		const_reverse_iterator	rbegin(void) const;
		reverse_iterator		rend(void);
		const_reverse_iterator	rend(void) const;

		//FUNCTIONS : CAPACITY

		public	:
		size_type		size(void) const;
		size_type		max_size(void) const;
		void			resize(size_type n, value_type val = value_type());
		size_type		capacity(void) const;
		bool			empty(void) const;
		void			reserve(size_type n);

		//FUNCTIONS : ELEMENT ACCESS

		reference		operator[](size_type n);
		const_reference	operator[](size_type n) const;
		reference		at(size_type n);
		const_reference	at(size_type n) const;
		reference		front(void);
		const_reference	front(void) const;
		reference		back(void);
		const_reference	back(void) const;

		//FUNCTIONS : MODIFIER

		void			push_back(const value_type &val);

		//ATTRIBUTES
		private	:
		size_type				_size;
		size_type				_capacity;
		pointer					_data;
		allocator_type			_alloc;

	};
}

# include "vector.tpp"
#endif

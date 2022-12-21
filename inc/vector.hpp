#ifndef VECTOR_H
# define VECTOR_H

# ifndef DEBUG
#  define DEBUG 0
# endif

# include <memory>

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		//TYPES
		public	:
		typedef	T											value_type;
		typedef	Alloc										allocator_type;
		typedef	typename allocator_type::reference			reference;
		typedef	typename allocator_type::const_reference	const_reference;
		typedef	typename allocator_type::pointer			pointer;
		typedef	typename allocator_type::const_pointer		const_pointer;
		typedef	pointer										iterator; // a changer par ft::random_iterator<value_type>
		typedef	const iterator								const_iterator;
		//typedef	todo									reverse_iterator;
		//typedef	todo									const_reverse_iterator;
		typedef	typename allocator_type::difference_type	difference_type;
		typedef	typename allocator_type::size_type			size_type;

		//CONSTRUCTOR AND DESTRUCTOR

		public	:
		explicit vector(const allocator_type &alloc = allocator_type());
		~vector(void);

		//FUNCTIONS

		public	:
		size_type	max_size(void) const;
		void		reserve(size_type n);
		void		push_back(const value_type &val);

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

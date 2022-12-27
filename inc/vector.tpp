#ifndef VECTOR_T
# define VECTOR_T

# ifndef VECTOR_H
#  error __FILE__ should only be included via vector.hpp
# endif

#include "containers.hpp" // DEBUG
#include <iostream> // for printer
#include <new> // for bad_alloc
#include <stdexcept> // for length_error

namespace ft
{
	template <class T, class Alloc>
	vector<T, Alloc>::vector(const allocator_type &alloc) : _size(0), _capacity(0), _data(NULL), _alloc(alloc)
	{
		DEBUG_PRINT("ft::vector : default constructor")
		return ;
	}

	template <class T, class Alloc>
	vector<T, Alloc>::~vector(void)
	{
		DEBUG_PRINT("ft::vector : default destructor")
		for (size_type i = 0; i < _size; i++)
			_alloc.destroy(_data + i);
		_alloc.deallocate(_data, _capacity);
		return ;
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::size_type		vector<T, Alloc>::size(void) const
	{
		return (_size);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::size_type		vector<T, Alloc>::capacity(void) const
	{
		return (_capacity);
	}

	template <class T, class Alloc>
	bool										vector<T, Alloc>::empty(void) const
	{
		return (!_size);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::size_type		vector<T, Alloc>::max_size(void) const
	{
		return (_alloc.max_size());
	}

	template <class T, class Alloc>
	void	vector<T, Alloc>::resize(size_type n, value_type val)
	{
		DEBUG_PRINT("ft::vector : resize")
		if (n < _size)
		{
			for (size_type i = n; i < _size; i++)
				_alloc.destroy(_data + i);
			_size = n;
		}
		else if (n > _size)
		{
			this->reserve(n > _size * 2 ? n : _size * 2);
			for (size_type i = _size; i < n; i++)
				_alloc.construct(_data + i, val);
			_size = n;
		}
	}

	//will throw bad_alloc if allocate fails
	//will throw length_error if n > max_size
	template <class T, class Alloc>
	void	vector<T, Alloc>::reserve(size_type n)
	{
		DEBUG_PRINT("ft::vector : reserve")
		if (n <= _capacity)
			return;
		if (n > this->max_size())
		{
			DEBUG_PRINT("Requested size greater than max_size")
			throw (std::length_error("vector::reserve"));
		}
		try
		{
			pointer		newData;
			size_type	oldSize = _size;

			newData = _alloc.allocate(n);
			while (oldSize-- > 0)
			{
				_alloc.construct(newData + oldSize, *(_data + oldSize));
				_alloc.destroy(_data + oldSize);
			}
			_alloc.deallocate(_data, _capacity);
			_data = newData;
			_capacity = n;
		}
		catch (std::bad_alloc &ba)
		{
			DEBUG_PRINT("ft::vector : bad alloc");
			throw;
		}
	}

	template <class T, class Alloc>
	void	vector<T, Alloc>::push_back(const value_type &val)
	{
		DEBUG_PRINT("ft::vector push_back")
		if (_size == _capacity)
			this->reserve(_size == 0 ? 1 : _size * 2);
		_alloc.construct(_data + _size, val);
		++_size;
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reference	vector<T, Alloc>::operator[](size_type n)
	{
		DEBUG_PRINT("ft::vector operator[]")
		return (*(_data + n));
	}

	template <class T, class Alloc>
	const typename vector<T, Alloc>::reference	vector<T, Alloc>::operator[](size_type n) const
	{
		DEBUG_PRINT("ft::vector const operator[]")
		return (*(_data + n));
	}
};
#endif

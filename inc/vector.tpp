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
	typename vector<T, Alloc>::size_type		vector<T, Alloc>::max_size(void) const
	{
		return (_alloc.max_size());
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
			throw (std::length_error("ft::vector : reserve : requested size greater than max_size"));
		try
		{
			pointer		newData;
			size_type	oldSize = _size;
			size_type	newCapacity = n > _capacity * 2 ? n : _capacity * 2;

			newData = _alloc.allocate(newCapacity);
			while (oldSize-- > 0)
			{
				_alloc.construct(newData + oldSize, *(_data + oldSize));
				_alloc.destroy(_data + oldSize);
			}
			_alloc.deallocate(_data, _capacity);
			_data = newData;
			_capacity = newCapacity;
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
		if (_size + 1 > _capacity)
			this->reserve(_size + 1);
		_alloc.construct(_data + _size, val);
		++_size;
	}
};
#endif

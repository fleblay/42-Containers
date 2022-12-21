#ifndef VECTOR_T
# define VECTOR_T

# ifndef VECTOR_H
#  error __FILE__ should only be included via vector.hpp
# endif

#include <iostream> // for printer
#include <new> // for bad_alloc
#include <stdexcept>

namespace ft
{
	template <class T, class Alloc>
	vector<T, Alloc>::vector(const allocator_type &alloc) : _size(0), _capacity(0), _data(NULL), _alloc(alloc)
	{
		std::cerr << "ft::vector Default Constructor called" << std::endl;
		return ;
	}

	template <class T, class Alloc>
	vector<T, Alloc>::~vector(void)
	{
		std::cerr << "ft::vector Default Destructor called" << std::endl;
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
		std::cerr << "ft::vector reserve" << std::endl;
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
			std::cerr << "_increaseCapacity : bad_alloc : " << ba.what() << std::endl;
			throw;
		}
	}

	template <class T, class Alloc>
	void	vector<T, Alloc>::push_back(const value_type &val)
	{
		std::cout << "ft::vector push_back" << std::endl;
		if (_size + 1 > _capacity)
			this->reserve(_size + 1);
		_alloc.construct(_data + _size, val);
		++_size;
	}
};
#endif

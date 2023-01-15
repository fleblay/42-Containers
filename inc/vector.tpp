#ifndef VECTOR_T
# define VECTOR_T

# ifndef VECTOR_H
#  error __FILE__ should only be included via vector.hpp
# endif

#include "containers.hpp" // DEBUG
#include <iostream> // for printer
#include <new> // for bad_alloc
#include <stdexcept> // for length_error
#include <sstream> // for at -> stringstream error
#include "is_integral.hpp"
#include "enable_if.hpp"
#include "distance.hpp"
#include "lexicographical_compare.hpp"
#include "equal.hpp"

namespace ft
{
	template <class T, class Alloc>
	vector<T, Alloc>::vector(const allocator_type &alloc) : _size(0), _capacity(0), _data(NULL), _alloc(alloc)
	{
		DEBUG_PRINT("ft::vector : default constructor")
		return ;
	}

	template <class T, class Alloc>
	vector<T, Alloc>::vector(size_type n, const value_type &val, const allocator_type &alloc) : _size(0), _capacity(0), _data(NULL), _alloc(alloc)
	{
		DEBUG_PRINT("ft::vector : fill constructor")
		this->assign(n, val);
		return ;
	}

	template <class T, class Alloc> template <class InputIterator>
	vector<T, Alloc>::vector(InputIterator first, InputIterator last, const allocator_type &alloc) : _size(0), _capacity(0), _data(NULL), _alloc(alloc)
	{
		DEBUG_PRINT("ft::vector : range constructor")
		this->assign(first, last);
		return ;
	}

	template <class T, class Alloc>
	vector<T, Alloc>::vector(const vector &x) : _size(0), _capacity(0), _data(NULL)
	{
		DEBUG_PRINT("ft::vector : copy constructor")
		*this = x;
		return ;
	}

	template <class T, class Alloc>
	vector<T,Alloc>	&vector<T, Alloc>::operator=(const vector &x)
	{
		DEBUG_PRINT("ft::vector : operator=")
		if (*this !=x)
		{
			this->assign(x.begin(), x.end());
			this->_alloc = x.get_allocator();
		}
		return (*this);
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
	typename vector<T, Alloc>::iterator			vector<T, Alloc>::begin(void)
	{
		DEBUG_PRINT("ft::vector : begin")
		return (iterator(_data));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_iterator	vector<T, Alloc>::begin(void) const
	{
		DEBUG_PRINT("ft::vector : const begin")
		return (const_iterator(_data));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator			vector<T, Alloc>::end(void)
	{
		DEBUG_PRINT("ft::vector : end")
		return (iterator(_data + _size));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_iterator	vector<T, Alloc>::end(void) const
	{
		DEBUG_PRINT("ft::vector : const end")
		return (const_iterator(_data + _size));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reverse_iterator	vector<T, Alloc>::rbegin(void)
	{
		DEBUG_PRINT("ft::vector : rbegin")
		return (reverse_iterator(iterator(_data + _size)));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reverse_iterator	vector<T, Alloc>::rbegin(void) const
	{
		DEBUG_PRINT("ft::vector : const rbegin")
		return (const_reverse_iterator(iterator(_data + _size)));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reverse_iterator	vector<T, Alloc>::rend(void)
	{
		DEBUG_PRINT("ft::vector : rend")
		return (reverse_iterator(iterator(_data)));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reverse_iterator	vector<T, Alloc>::rend(void) const
	{
		DEBUG_PRINT("ft::vector : const rend")
		return (const_reverse_iterator(iterator(_data)));
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

	template <class T, class Alloc> template <class InputIterator>
	void			vector<T, Alloc>::assign(typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
	{
		DEBUG_PRINT("ft::vector assign : range version")
		typename iterator_traits<InputIterator>::iterator_category	InputIteratorTag;

		assign_range(first, last, InputIteratorTag);
		return ;
	}

	template <class T, class Alloc> template <class InputIterator>
	void			vector<T, Alloc>::assign_range(InputIterator first, InputIterator last, std::forward_iterator_tag)
	{
		DEBUG_PRINT("ft::vector assign : range version : forward_iterator_tag specialisation")
		size_type	n = ft::distance(first, last);
		if (n > _capacity)
			this->reserve(n);
		for (size_type i = 0; i < _size; i++)
			_alloc.destroy(_data + i);
		for (size_type i = 0; i < n; i++, first++)
			_alloc.construct(_data + i, *first);
		_size = n;
	}

	template <class T, class Alloc> template <class InputIterator>
	void			vector<T, Alloc>::assign_range(InputIterator first, InputIterator last, std::input_iterator_tag)
	{
		DEBUG_PRINT("ft::vector assign : range version : input_iterator specialisation")
		for (size_type i = 0; i < _size; i++)
			_alloc.destroy(_data + i);
		_size = 0;
		for (; first != last; first++)
			this->push_back(*first);
	}

	template <class T, class Alloc>
	void	vector<T, Alloc>::assign(size_type n, const value_type &val)
	{
		DEBUG_PRINT("ft::vector assign : fill version")
		if (n > _capacity)
			this->reserve(n);
		for (size_type i = 0; i < _size; i++)
			_alloc.destroy(_data + i);
		for (size_type i = 0; i < n; i++)
			_alloc.construct(_data + i, val);
		_size = n;
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
	void	vector<T, Alloc>::pop_back(void)
	{
		DEBUG_PRINT("ft::vector pop_back")
		if (_size == 0 )
			return ;
		_alloc.destroy(_data + _size - 1);
		--_size;
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator		vector<T, Alloc>::insert(iterator position, const value_type &val)
	{
		DEBUG_PRINT("ft::vector insert : single elem")
		size_type	pos = ft::distance(begin(), position);
		size_type i = _size;
		size_type oldSize = _size;

		if (_size == _capacity)
			this->reserve(_size < 3 ? _size + 1 : _size * 2);
			//this->reserve(_size == 0 ? 1 : _size * 2);
			//this->reserve(_size + 1 >= 2 * _size ? _size + 1 : 2 * _size);
		for (; i > pos; i--)
		{
			if (i < oldSize)
				_alloc.destroy(_data + i);
			_alloc.construct(_data + i, *(_data + i - 1));
		}
		if (i < oldSize)
			_alloc.destroy(_data + i);
		_alloc.construct(_data + i, val);
		++_size;
		return (iterator(_data + i));
	}

	template <class T, class Alloc>
	void	vector<T, Alloc>::insert(iterator position, size_type n, const value_type &val)
	{
		DEBUG_PRINT("ft::vector insert : fill")
		size_type	pos = ft::distance(begin(), position);
		size_type i = _size + n - 1; //fin de l'array
		size_type oldSize = _size;

		if (_size + n > _capacity)
			this->reserve(_size + n > 2 * _size ? _size + n : 2 * _size);
		for (; i > pos + n - 1; i--) // i sup a la fin de l'insert
			{
			if (i < oldSize)
				_alloc.destroy(_data + i);
			_alloc.construct(_data + i, *(_data + i - n));
			}
		for (size_type j = 0; j < n; j++)
		{
			if (i - j < oldSize)
				_alloc.destroy(_data + i);
			_alloc.construct(_data + i - j, val);
		}
		_size += n;
		return ;
	}

	template <class T, class Alloc> template <class InputIterator>
	//void			vector<T, Alloc>::insert(iterator position,
//			typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
	void			vector<T, Alloc>::insert(iterator position, InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type*)
	{
		DEBUG_PRINT("ft::vector insert : range version")
		typename iterator_traits<InputIterator>::iterator_category	InputIteratorTag;
		//typename std::random_access_iterator_tag							InputIteratorTag_DEBUG;
		//typename std::input_iterator_tag							InputIteratorTag_DEBUG;

		insert_range(position, first, last, InputIteratorTag);
		//insert_range(position, first, last, InputIteratorTag_DEBUG);
		return ;
	}

	template <class T, class Alloc> template <class InputIterator>
	void			vector<T, Alloc>::insert_range(iterator position, InputIterator first, InputIterator last,
						std::forward_iterator_tag)
	{
		DEBUG_PRINT("ft::vector insert : range version : forward_iterator_tag specialisation")
		size_type	pos = ft::distance(begin(), position);
		size_type	n = ft::distance(first, last);
		size_type i = _size + n - 1; //fin de l'array

		if (_size + n > _capacity)
			this->reserve(_size + n > 2 * _size ? _size + n : 2 * _size);
		for (; i > pos + n - 1; i--) // i sup a la fin de l'insert
			_alloc.construct(_data + i, *(_data + i - n));
		for (size_type j = 0; j < n; j++)
		{
			_alloc.destroy(_data + i - j);
			_alloc.construct(_data + i - j, *--last);
		}
		_size += n;
		return ;

	}

	template <class T, class Alloc> template <class InputIterator>
	void			vector<T, Alloc>::insert_range(iterator position, InputIterator first, InputIterator last,
						std::input_iterator_tag)
	{
		DEBUG_PRINT("ft::vector insert : range version : input_iterator_tag specialisation")
		iterator	insert_position = position;
		for (; first != last; first++)
		{
			insert_position = this->insert(insert_position, *first);
			insert_position++;
		}
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator		vector<T, Alloc>::erase(iterator position)
	{
		DEBUG_PRINT("ft::vector erase single elem")
		size_type	pos = ft::distance(begin(), position);

		vector tmp(this->begin(), position);
		tmp.insert(tmp.end(), position + 1, this->end());
		*this = tmp;

		return (this->begin() + pos);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator		vector<T, Alloc>::erase(iterator first, iterator last)
	{
		DEBUG_PRINT("ft::vector erase range")

		vector tmp(this->begin(), first);
		size_type	pos = ft::distance(tmp.begin(), tmp.end());
		tmp.insert(tmp.end(), last, this->end());
		*this = tmp;

		return (this->begin() + pos);
	}

	template <class T, class Alloc>
	void	vector<T, Alloc>::swap(vector &x)
	{
		DEBUG_PRINT("ft::vector swap")
		size_type		tmp_size = _size;
		size_type		tmp_capacity = _capacity;
		pointer			tmp_data = _data;
		allocator_type	tmp_alloc = _alloc;

		this->_size = x._size;
		this->_capacity = x._capacity;
		this->_data = x._data;
		this->_alloc = x._alloc;

		x._size = tmp_size;
		x._capacity = tmp_capacity;
		x._data = tmp_data;
		x._alloc = tmp_alloc;

		return ;
	}

	template <class T, class Alloc>
	void			vector<T, Alloc>::clear(void)
	{
		DEBUG_PRINT("ft::vector clear")
		for (size_type i = 0; i < _size; i++)
			_alloc.destroy(_data + i);
		_size = 0;
		return ;
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reference	vector<T, Alloc>::operator[](size_type n)
	{
		DEBUG_PRINT("ft::vector operator[]")
		return (*(_data + n));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reference	vector<T, Alloc>::operator[](size_type n) const
	{
		DEBUG_PRINT("ft::vector const operator[]")
		return (*(_data + n));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reference	vector<T, Alloc>::at(size_type n)
	{
		DEBUG_PRINT("ft::vector at")
		if (n >= _size)
		{
			std::stringstream	oor_what;

			oor_what	<< "vector::_M_range_check: __n (which is "
						<< n
						<< ") >= this->size() (which is "
						<< this->size()
						<< ")";

			throw(std::out_of_range(oor_what.str()));
		}
		return (*(_data + n));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reference	vector<T, Alloc>::at(size_type n) const
	{
		DEBUG_PRINT("ft::vector const at")
		if (n >= _size)
		{
			std::stringstream	oor_what;

			oor_what	<< "vector::_M_range_check: __n (which is "
						<< n
						<< ") >= this->size() (which is "
						<< this->size()
						<< ")";

			throw(std::out_of_range(oor_what.str()));
		}
		return (*(_data + n));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reference	vector<T, Alloc>::front(void)
	{
		DEBUG_PRINT("ft::vector front")
		return (*_data);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reference	vector<T, Alloc>::front(void) const
	{
		DEBUG_PRINT("ft::vector const front")
		return (*_data);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reference	vector<T, Alloc>::back(void)
	{
		DEBUG_PRINT("ft::vector back")
		return (*(_data + _size - 1));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reference	vector<T, Alloc>::back(void) const
	{
		DEBUG_PRINT("ft::vector const back")
		return (*(_data + _size - 1));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::allocator_type	vector<T, Alloc>::get_allocator() const
	{
		DEBUG_PRINT("ft::vector get_allocator")
		return (_alloc);
	}

	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		DEBUG_PRINT("ft::vector operator==")
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		DEBUG_PRINT("ft::vector operator<")
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		DEBUG_PRINT("ft::vector operator!=")
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		DEBUG_PRINT("ft::vector operator>")
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		DEBUG_PRINT("ft::vector operator<=")
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		DEBUG_PRINT("ft::vector operator>=")
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
	{
		DEBUG_PRINT("ft::vector swap overload")
		x.swap(y);
	}
};
#endif

#ifndef DISTANCE_H
# define DISTANCE_H

#include "containers.hpp" //For debug
#include "iterator.hpp" //For tags

namespace ft
{
	template <class InputIterator>
	typename iterator_traits<InputIterator>::difference_type distance_tag(InputIterator first, InputIterator last, std::random_access_iterator_tag)
	{
		
		DEBUG_PRINT("ft::distance : random_access specialisation")
		typename iterator_traits<InputIterator>::difference_type	n = last - first;
		return n;
	}

	template <class InputIterator>
	typename iterator_traits<InputIterator>::difference_type distance_tag(InputIterator first, InputIterator last, std::input_iterator_tag)
	{
		DEBUG_PRINT("ft::distance : input_iterator specialisation")
		typename iterator_traits<InputIterator>::difference_type	n = 0;
		while (first !=last)
		{
			n++;
			first++;
		}
		return n;
	}

	template <class InputIterator>
	typename iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last)
	{
		typename iterator_traits<InputIterator>::iterator_category	InputIteratorTag;
		typename iterator_traits<InputIterator>::difference_type	result;

		result = distance_tag(first, last, InputIteratorTag);
		return result;
	}
}

#endif

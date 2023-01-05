#ifndef LEXICOGRAPHICAL_COMPARE_H
# define LEXICOGRAPHICAL_COMPARE_H

#include "containers.hpp" // For debug

namespace ft
{
	//Renvoie true si la range first1->last1 a 1 elem less que le premier
	//Renvoie false sinon (tous les elem sont identques, ou 1 elem est sup)
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2)
	{
		DEBUG_PRINT("ft::lexicographical_compare default")
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1)
				return false;
			else if (*first1<*first2)
				return true;
			++first1;
			++first2;
		}
		return (first2!=last2);
	}	

	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		DEBUG_PRINT("ft::lexicographical_compare custom")
		while (first1!=last1)
		{
			if (first2==last2 || comp(*first2, *first1))
				return false;
			else if (comp(*first1, *first2))
				return true;
			++first1;
			++first2;
		}
		return (first2!=last2);
	}	
}

#endif

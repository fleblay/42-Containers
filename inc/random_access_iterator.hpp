#ifndef RANDOM_ACCESS_ITERATOR_H
# define RANDOM_ACCESS_ITERATOR_H

# include "iterator.hpp"

namespace ft
{
	template<class T>
	class random_access_iterator : public iterator<random_access_iterator_tag, T>
	{
		public	:
		random_access_iterator(void);
		random_access_iterator(pointer initValue);
		random_access_iterator(const random_access_iterator &src);
		virtual ~random_access_iterator(void);

		private	:
		pointer	_curentElemPtr;
	};
}

#endif

#ifndef ITERATOR_H
# define ITERATOR_H

namespace ft
{
	//Types for the iterator_category
	struct output_iterator_tag
	{};
	struct input_iterator_tag
	{};
	struct forward_iterator_tag : public input_iterator_tag
	{};
	struct bidirectional_iterator_tag : public forward_iterator_tag
	{};
	struct random_access_iterator_tag : public bidirectional_iterator_tag
	{};

	//iterator_traits will be used by algorithm to determine what kind of iterator has
	//been passed to the algorithm. This is done using the member typedef, like
	//std::iterator_traits<Iter>::iterator_category and comparing it with the types above.
	//Depending on the type of Iterator, differents iterator member functions will be
	//available. This way, algo can take advantage of random access iterator for instance.
	//Algorithm will use specialisation of implementation to do so, having a last argument
	//that is the iterator_category. Ex : algo(Iter first, Iter last, std::input_iterator_tag)
	template <class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::iterator_category		iterator_category;
		typedef typename Iterator::value_type				value_type;
		typedef typename Iterator::difference_type			difference_type;
		typedef typename Iterator::pointer					pointer;
		typedef typename Iterator::reference				reference;

	};

	//Specialisation if the Iterator is a T* or a const T*. We don't have to look at
	//the iterator typedef members, we directly know it has the attributes of a pointer
	template <class T>
	struct iterator_traits<T*>
	{
		typedef typename random_access_iterator_tag			iterator_category;
		typedef typename T									value_type;
		typedef typename ptrdiff_t							difference_type;
		typedef typename T*									pointer;
		typedef typename T&									reference;
	};
	template <class T>
	struct iterator_traits<const T*>
	{
		typedef typename random_access_iterator_tag			iterator_category;
		typedef typename T									value_type;
		typedef typename ptrdiff_t							difference_type;
		typedef typename const T*							pointer;
		typedef typename const T&							reference;
	};
	//In order for this to work, Iterator MUST have a valid type for the typedef provided
	//by iterator_traits. The iterator struct has been created to facilitate this. Each
	//Iterator class should inherit from this base class, insuring it to have the proprer
	//typedefs
	template <class Category,
			 class T,
			 class Distance = ptrdiff_t,
			 class Pointer = T*,
			 class Reference = T&>
	struct iterator
	{
		typedef Category									iterator_category;
		typedef T											value_type;
		typedef Distance									difference_type;
		typedef Pointer										pointer;
		typedef Reference									reference;
	}
}

#endif

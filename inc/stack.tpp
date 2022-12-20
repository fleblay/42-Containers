#ifndef STACK_T
# define STACK_T

# ifndef STACK_H
#  error __FILE__ should only be included via stack.hpp
# endif

#include <iostream>

//Constructor & Destructor
template <typename T>
stack<T>::stack(void)
{
	std::cout << "stack Default Constructor called" << std::endl;
	return ;
}

template <typename T>
stack<T>::stack(const stack<T> &rhs)
{
	std::cout << "stack Copy Constructor called" << std::endl;
	*this = rhs;
}

template <typename T>
stack<T>::~stack(void)
{
	std::cout << "stack Default Destructor called" << std::endl;
	return ;
}

//Operator Overload
template <typename T>
stack<T>	&stack<T>::operator=(const stack<T> &rhs)
{
	std::cout << "stack assign operator overloard called" << std::endl;
	if (this == &rhs)
		return (*this);
	this->std::stack<T>::operator=(rhs);
	return (*this);
}

//Member functions
template <typename T>
typename stack<T>::iterator	stack<T>::begin(void)
{
	return (this->c.begin());
}

template <typename T>
typename stack<T>::const_iterator	stack<T>::begin(void) const
{
	return (this->c.begin());
}

template <typename T>
typename stack<T>::reverse_iterator	stack<T>::rbegin(void)
{
	return (this->c.rbegin());
}

template <typename T>
typename stack<T>::const_reverse_iterator	stack<T>::rbegin(void) const
{
	return (this->c.rbegin());
}

template <typename T>
typename stack<T>::iterator	stack<T>::end(void)
{
	return (this->c.end());
}

template <typename T>
typename stack<T>::const_iterator	stack<T>::end(void) const
{
	return (this->c.end());
}

template <typename T>
typename stack<T>::reverse_iterator	stack<T>::rend(void)
{
	return (this->c.rend());
}

template <typename T>
typename stack<T>::const_reverse_iterator	stack<T>::rend(void) const
{
	return (this->c.rend());
}
#endif

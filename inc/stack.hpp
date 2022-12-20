#ifndef STACK_H
# define STACK_H

# ifndef DEBUG
#  define DEBUG 0
# endif


# include <stack>

template <typename T>
class stack : public std::stack<T>
{
	public	:

	typedef typename std::stack<T>::container_type::iterator				iterator;
	typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;


	//Constructor & Destructor
	stack<T>(void);
	stack<T>(const stack<T> &src);
	~stack<T>(void);

	//Operator Overload
	stack<T>	&operator=(const stack<T> &rhs);


	//Member functions
	iterator				begin(void);
	const_iterator			begin(void) const ;
	reverse_iterator		rbegin(void);
	const_reverse_iterator	rbegin(void) const ;
	iterator				end(void);
	const_iterator			end(void) const ;
	reverse_iterator		rend(void);
	const_reverse_iterator	rend(void) const ;

};

#include "stack.tpp"

# endif

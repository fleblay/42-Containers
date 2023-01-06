#ifndef STACK_H
# define STACK_H

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = vector<T> >
	class stack
	{
		//TYPES
		public	:
		typedef T								value_type;
		typedef	Container						container_type;
		typedef typename Container::size_type	size_type;

		//MEMBER FUNCTIONS

		public	:
		explicit stack(const container_type &ctnr = container_type()) : _container(ctnr)
		{};
		~stack(void)
		{};

		bool				empty(void) const
		{return _container.empty();};
		size_type			size(void) const
		{return _container.size();};
		value_type			&top(void)
		{return _container.back();};
		const value_type	&top(void) const
		{return _container.back();};
		void			push(const value_type &val)
		{return _container.push_back(val);};
		void			pop(void)
		{return _container.pop_back();};

		//ATTRIBUTES
		private	:
		container_type			_container;


	//FUNCTIONS : NON-MEMBER FUNCTION OVERLOADS

		friend bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
		{ return lhs._container == rhs._container;}

		friend bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
		{ return lhs._container < rhs._container;}

		friend bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
		{ return lhs._container != rhs._container;}

		friend bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
		{ return lhs._container > rhs._container;}

		friend bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
		{ return lhs._container <= rhs._container;}

		friend bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
		{ return lhs._container >= rhs._container;}
	};
}

#endif


#ifndef PAIR_H
# define PAIR_H

# include "containers.hpp" // for debug print

namespace ft
{
	template <class T1, class T2>
	class pair
	{
		//TYPES
		public	:
		typedef	T1		first_type;
		typedef	T2		second_type;

		//VARIABLES
		public	:
		first_type		first;
		second_type		second;

		//FUNCTION
		public	:
		pair(void) : first(first_type()), second(second_type())
		{ DEBUG_PRINT("ft::pair : default constructor"); }
		template <class U, class V>
		pair(const pair<U, V> &pr) : first(pr.first), second(pr.second)
		{ DEBUG_PRINT("ft::pair : copy constructor"); }
		pair(const first_type &a, const second_type &b) : first(a), second(b)
		{ DEBUG_PRINT("ft::pair : initialization constructor"); }
		pair &operator=(const pair &pr)
		{
			DEBUG_PRINT("ft::pair : operator=");
			this->first = pr.first;
			this->second = pr.second;
			return *this;
		}
	};

	//FUNCTIONS : NON-MEMBER FUNCTION OVERLOADS

	template <class T1, class T2>
	bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{ return lhs.first == rhs.first && lhs.second == lhs.second; }

	template <class T1, class T2>
	bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs);
	{ return lhs.first < rhs.first || (!(rhs.first<lhs.first) && lhs.second < rhs.second); }

	template <class T1, class T2>
	bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs);
	{ return !(lhs == rhs); }

	template <class T1, class T2>
	bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs);
	{ return rhs < lhs; }

	template <class T1, class T2>
	bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs);
	{ return !(rhs < lhs); }

	template <class T1, class T2>
	bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs);
	{ return !(lhs < rhs); }
}

#endif


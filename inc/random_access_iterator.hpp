#ifndef RANDOM_ACCESS_ITERATOR_H
# define RANDOM_ACCESS_ITERATOR_H

# include "iterator.hpp"
# include <cstddef>

namespace ft
{
	template<typename Iter>
	class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, Iter> // changer ft par std pour tester algo
	{
		public	:
		//On rend accessible a la classe (pour les definition de fx) et a l'exterieur
		//les typedefs necessaires a l'utilisation des iterator_traits
		typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<Iter>::value_type value_type;
		typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
		typedef typename ft::iterator_traits<Iter>::reference reference;
		typedef typename ft::iterator_traits<Iter>::pointer pointer;

		private	:
		Iter	_curentElemPtr;

		public	:
		random_access_iterator(void);
		explicit random_access_iterator(const Iter &initValue);
		random_access_iterator(const random_access_iterator<Iter> &src);
		random_access_iterator &operator=(const random_access_iterator &rhs);
		virtual ~random_access_iterator(void);

		//Fonction pour les operateurs de comparaison
		const Iter	&base(void) const;

		//Va renvoyer la valeur pointee par _currentElemPtr, ie acceder a la val pointee par le
		//pointer de type iter qui est dans le random_access_iterator
		reference				operator*(void);
		pointer					operator->(void);
		random_access_iterator	&operator++(void); // pre-increment
		random_access_iterator	&operator--(void); // pre-decrement
		random_access_iterator	operator++(int);
		random_access_iterator	operator--(int);
		random_access_iterator	operator+(const difference_type &offset) const;
		random_access_iterator	operator-(const difference_type &offset) const;
		difference_type			operator-(const random_access_iterator &rhs) const;
		random_access_iterator	&operator+=(const difference_type &offset); // compound assignement
		random_access_iterator	&operator-=(const difference_type &offset); // compound assignement
		reference				operator[](const difference_type &offset);
	};

	//A faire via des template pour comparer avec les Iter, avec les const Iter et volatile Iter
	template<typename IterL, typename IterR>
	bool	operator==(const random_access_iterator<IterL> &lhs,
			const random_access_iterator<IterR> &rhs);
	template<typename IterL, typename IterR>
	bool	operator!=(const random_access_iterator<IterL> &lhs,
			const random_access_iterator<IterR> &rhs);
	template<typename IterL, typename IterR>
	bool	operator>(const random_access_iterator<IterL> &lhs,
			const random_access_iterator<IterR> &rhs);
	template<typename IterL, typename IterR>
	bool	operator<(const random_access_iterator<IterL> &lhs,
			const random_access_iterator<IterR> &rhs);
	template<typename IterL, typename IterR>
	bool	operator>=(const random_access_iterator<IterL> &lhs,
			const random_access_iterator<IterR> &rhs);
	template<typename IterL, typename IterR>
	bool	operator<=(const random_access_iterator<IterL> &lhs,
			const random_access_iterator<IterR> &rhs);
	//TODO
	//overload de operator+ avec friend pour difference_type
}

# include "random_access_iterator.tpp"

#endif
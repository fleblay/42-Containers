#ifndef REVERSE_ITERATOR_H
# define REVERSE_ITERATOR_H

# include "iterator.hpp"
# include <cstddef>
# include "containers.hpp"

namespace ft
{
	template<typename Iter>
	class reverse_iterator : public ft::iterator<ft::random_access_iterator_tag, Iter> // changer ft par std pour tester algo
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
		reverse_iterator(void);
		explicit reverse_iterator(const Iter &initValue);
		template<typename IterR>
		reverse_iterator(const reverse_iterator<IterR> &src);
		template<typename IterR>
		reverse_iterator &operator=(const reverse_iterator<IterR> &rhs);
		virtual ~reverse_iterator(void);

		//Fonction pour les operateurs de comparaison
		const Iter	&base(void) const;

		//Va renvoyer la valeur pointee par _currentElemPtr, ie acceder a la val pointee par le
		//pointer de type iter qui est dans le random_access_iterator
		reference				operator*(void);
		pointer					operator->(void);
		reverse_iterator	&operator++(void); // pre-increment
		reverse_iterator	&operator--(void); // pre-decrement
		reverse_iterator	operator++(int);
		reverse_iterator	operator--(int);
		reverse_iterator	operator+(const difference_type &offset) const;
		reverse_iterator	operator-(const difference_type &offset) const;
		difference_type			operator-(const reverse_iterator &rhs) const;
		reverse_iterator	&operator+=(const difference_type &offset); // compound assignement
		reverse_iterator	&operator-=(const difference_type &offset); // compound assignement
		reference				operator[](const difference_type &offset);
		friend reverse_iterator	operator+(difference_type offset, const reverse_iterator &rhs)
		{	
			return (reverse_iterator(rhs.base() + offset));
		}

	};

	//A faire via des template pour comparer avec les Iter, avec les const Iter et volatile Iter
	template<typename IterL, typename IterR>
	bool	operator==(const reverse_iterator<IterL> &lhs,
			const reverse_iterator<IterR> &rhs);
	template<typename IterL, typename IterR>
	bool	operator!=(const reverse_iterator<IterL> &lhs,
			const reverse_iterator<IterR> &rhs);
	template<typename IterL, typename IterR>
	bool	operator>(const reverse_iterator<IterL> &lhs,
			const reverse_iterator<IterR> &rhs);
	template<typename IterL, typename IterR>
	bool	operator<(const reverse_iterator<IterL> &lhs,
			const reverse_iterator<IterR> &rhs);
	template<typename IterL, typename IterR>
	bool	operator>=(const reverse_iterator<IterL> &lhs,
			const reverse_iterator<IterR> &rhs);
	template<typename IterL, typename IterR>
	bool	operator<=(const reverse_iterator<IterL> &lhs,
			const reverse_iterator<IterR> &rhs);
}

# include "reverse_iterator.tpp"

#endif

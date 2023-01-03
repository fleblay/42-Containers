#ifndef ENABLE_IF_H
# define ENABLE_IF_H

namespace ft
{
	//De base, la structure ne definit pas le typedef "type"
	template<bool Cond, class T = void>
	struct enable_if
	{};
	//Specialisation du template sur un bool "true" -> le typdef est definit
	//On enable_if<true, T>::type sera alors definit comme T et on pourra acceder a cette option de
	//compilation
	template<class T>
	struct enable_if<true, T>
	{
		typedef	T	type;
	};
	//A utiliser avec fx template de type
	//template<typename T>
	//fx(enable_if<ft::is_integral<T>::value, T>::type)
	//Si T est integral, alors, enable_if<true, T>::type sera definit comme T
	//fx(T) sera equivalent a la compilation
}

#endif


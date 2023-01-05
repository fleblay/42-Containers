#ifndef IS_INTEGRAL_H
# define IS_INTEGRAL_H

namespace ft
{
	template <typename T, T v>
	struct integral_constant
	{
		//const because compilation needs it
		const static T value = v;
		typedef T value_type;
		typedef integral_constant<T,v> type;
		//operator bool
		operator T()
		{
			return v;
		}
	};
	// ft::is_integral<int>() retourne meme valeur que ft::is_integral<int>::value

	typedef integral_constant<bool, true>		true_type;
	//true_type::value_type vaut bool
	//true_type() vaut true
	typedef integral_constant<bool, false>		false_type;

	//On peut acceder a ft::is_integral<int>::value (idem que ft::is_integral<int>() car herite de
	//integral_constant qui definit operator bool () qui retourne true ou false pour les false_type
	//et true_type
	template <typename T>
	struct is_integral : public false_type
	{ };

	template <>
	struct is_integral<bool> : public true_type
	{ };

	template <>
	struct is_integral<char> : public true_type
	{ };

	/*
	template <>
	struct is_integral<char16_t> : public true_type
	{ };

	template <>
	struct is_integral<char32_t> : public true_type
	{ };
	*/

	template <>
	struct is_integral<wchar_t> : public true_type
	{ };

	template <>
	struct is_integral<signed char> : public true_type
	{ };

	template <>
	struct is_integral<short int> : public true_type
	{ };

	template <>
	struct is_integral<int> : public true_type
	{ };

	template <>
	struct is_integral<long int> : public true_type
	{ };

	template <>
	struct is_integral<long long int> : public true_type
	{ };

	template <>
	struct is_integral<unsigned char> : public true_type
	{ };

	template <>
	struct is_integral<unsigned short int> : public true_type
	{ };

	template <>
	struct is_integral<unsigned int> : public true_type
	{ };

	template <>
	struct is_integral<unsigned long> : public true_type
	{ };

	template <>
	struct is_integral<unsigned long long int> : public true_type
	{ };
}

#endif

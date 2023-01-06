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

	template <typename T>
	struct remove_cv
	{
		typedef T type;
	};

	template <typename T>
	struct remove_cv<const T>
	{
		typedef T type;
	};

	template <typename T>
	struct remove_cv<volatile T>
	{
		typedef T type;
	};

	//On peut acceder a ft::is_integral<int>::value (idem que ft::is_integral<int>() car herite de
	//integral_constant qui definit operator bool () qui retourne true ou false pour les false_type
	//et true_type
	template <typename T>
	struct is_integral_helper : public false_type
	{ };

	template <>
	struct is_integral_helper<bool> : public true_type
	{ };

	template <>
	struct is_integral_helper<char> : public true_type
	{ };

	//C++ 11 and above -> commented to allow compilation with flag std98
	/*
	template <>
	struct is_integral_helper<char16_t> : public true_type
	{ };

	template <>
	struct is_integral_helper<char32_t> : public true_type
	{ };
	*/

	template <>
	struct is_integral_helper<wchar_t> : public true_type
	{ };

	template <>
	struct is_integral_helper<signed char> : public true_type
	{ };

	template <>
	struct is_integral_helper<short int> : public true_type
	{ };

	template <>
	struct is_integral_helper<int> : public true_type
	{ };

	template <>
	struct is_integral_helper<long int> : public true_type
	{ };

	template <>
	struct is_integral_helper<long long int> : public true_type
	{ };

	template <>
	struct is_integral_helper<unsigned char> : public true_type
	{ };

	template <>
	struct is_integral_helper<unsigned short int> : public true_type
	{ };

	template <>
	struct is_integral_helper<unsigned int> : public true_type
	{ };

	template <>
	struct is_integral_helper<unsigned long> : public true_type
	{ };

	template <>
	struct is_integral_helper<unsigned long long int> : public true_type
	{ };

	template <typename T>
	struct is_integral : public is_integral_helper<typename remove_cv<T>::type>
	{ };

}

#endif

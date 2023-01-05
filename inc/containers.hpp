#ifndef CONTAINERS_H
# define CONTAINERS_H

# include <iostream>

# ifndef NAMESPACE
#  define NAMESPACE ft
# endif

# define COUT(x) std::cout << x << std::endl;
# define CERR(x) std::cerr << x << std::endl;
# define RED_COUT(x) std::cout << "\e[31m" << x << "\e[0m" << std::endl;
# define GREEN_COUT(x) std::cout << "\e[32m" << x << "\e[0m" << std::endl;
# define ORANGE_COUT(x) std::cout << "\e[33m" << x << "\e[0m" << std::endl;

# ifdef DEBUG
#  define DEBUG_PRINT(x) CERR(x)
# else
#  define DEBUG_PRINT(x)
# endif

#endif

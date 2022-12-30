#include <memory>
#include <iostream>

int main(void)
{
	std::allocator<int> myAlloc;

	int a = 12;
	//std::allocator_traits<std::allocator<int> >::pointer test = std::allocator_traits<std::allocator<int> >::pointer();
	//std::allocator_traits<std::allocator<int> >::pointer test = std::allocator_traits<std::allocator<int> >::pointer(&a);
	std::allocator<int>::pointer test = std::allocator_traits<std::allocator<int> >::pointer(&a);

	std::cout << test << std::endl;
	std::cout << &a << std::endl;
	std::cout << *test << std::endl;
	std::cout << "OK" << std::endl;
}

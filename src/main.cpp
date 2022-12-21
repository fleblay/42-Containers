#include "vector.hpp"

using namespace ft;

int main(void)
{
	vector<char>	test;
	std::cerr << "max size : [" << test.max_size() << "]" << std::endl;
	test.~vector();

	vector<int>	myVector;
	std::cerr << "max size : [" << myVector.max_size() << "]" << std::endl;
	myVector.push_back(42);
	myVector.push_back(21);
	return (0);
}

#include "stack.hpp"

int main(void)
{
	stack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	DEBUG && std::cout << "\x1b[33mfirst element is : \x1b[0m" << mstack.top() << std::endl;
	mstack.pop();

	std::cout << "the stack size is now : " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	mstack.push(42);
	mstack.push(-42);
	mstack.push(1024);
	mstack.push(256);

	stack<int>::iterator it = mstack.begin();
	stack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "Now displaying full custom stack" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	stack<int>	copystack(mstack);	
	stack<int>	copystack2;	

	copystack2 = mstack;

	stack<int>::reverse_iterator rit = mstack.rbegin();
	stack<int>::reverse_iterator rite = mstack.rend();
	std::cout << "Now REVERSE displaying full custom stack copy" << std::endl;
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
	return (0);
}

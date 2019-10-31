#include <iostream>

#include "StackAllocator.h"

int main()
{

	StackAllocator<int> stack(10);

	std::cout << stack.m_startOfStack << std::endl;
	std::cout << stack.m_topOfStack << std::endl;

	stack.pushElementOnStack(10);
	stack.pushElementOnStack(9);
	stack.pushElementOnStack(8);
	stack.pushElementOnStack(7);
	stack.pushElementOnStack(6);
	stack.pushElementOnStack(5);
	stack.pushElementOnStack(4);

	std::cout << stack.m_topOfStack << std::endl;

	stack.popElementFromStack();
	stack.popElementFromStack();
	stack.popElementFromStack();
	stack.popElementFromStack();
	stack.popElementFromStack();
	stack.popElementFromStack();

	std::cout << stack.m_topOfStack << std::endl;

	stack.popElementFromStack();
	stack.popElementFromStack();
	stack.popElementFromStack();
	stack.popElementFromStack();
	stack.peekTopElementOfStack();

	std::cout << stack.isEmpty() << std::endl;

	std::cin.get();

}
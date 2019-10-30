#include <iostream>

#include "StackAllocator.h"

int main()
{

	StackAllocator stack(10);

	std::cout << stack.m_maxElements << std::endl;
	std::cout << stack.m_startOfStack << std::endl;
	std::cout << stack.m_topOfStack << std::endl;

	std::cin.get();

}
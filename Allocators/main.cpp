#include <iostream>

#include "StackAllocator.h"
#include "DoubleEndedStackAllocator.h"

int main()
{

	//StackAllocator<int> intStack(10);
	//StackAllocator<std::string> stringStack(10);

	//std::cout << intStack.m_startOfStack << std::endl;
	//std::cout << intStack.m_topOfStack << std::endl;

	//intStack.pushElementOnStack(10);
	//intStack.pushElementOnStack('t');
	//intStack.pushElementOnStack(8.12992f);
	//intStack.pushElementOnStack(7.0);
	//intStack.pushElementOnStack('c');
	//intStack.pushElementOnStack("String");
	//intStack.pushElementOnStack(4);

	//std::cout << stack.m_topOfStack << std::endl;

	//stack.popElementFromStack();
	//stack.popElementFromStack();
	//stack.popElementFromStack();
	//stack.popElementFromStack();
	//stack.popElementFromStack();
	//stack.popElementFromStack();

	//std::cout << stack.m_topOfStack << std::endl;

	//stack.popElementFromStack();
	//stack.popElementFromStack();
	//stack.popElementFromStack();
	//stack.popElementFromStack();
	//stack.peekTopElementOfStack();

	//std::cout << stack.isEmpty() << std::endl;

	DoubleEndedStackAllocator ds(10);
	ds.addElementToRightStack(1);
	ds.addElementToRightStack(2);
	ds.addElementToRightStack(3);
	ds.addElementToRightStack(4);
	ds.addElementToRightStack(5);
	ds.addElementToRightStack(6);

	std::cin.get();

}
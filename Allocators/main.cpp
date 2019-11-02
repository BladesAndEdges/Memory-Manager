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

	//DoubleEndedStackAllocator ds(10);
	//ds.addElementToRightStack(1);
	//ds.addElementToRightStack(2);
	//ds.addElementToRightStack(3);
	//ds.addElementToRightStack(4);

	//std::cout << *(ds.m_rightTopOfStack + 1);
	//ds.addElementToRightStack(5);
	//ds.addElementToRightStack(6);

	DoubleEndedStackAllocator ds(3);
	ds.allocateOnTheLeftStack(1);
	ds.deallocateFromTheLeftStack();
	ds.allocateOnTheLeftStack(2);
	ds.deallocateFromTheLeftStack();
	ds.allocateOnTheLeftStack(3);
	ds.deallocateFromTheLeftStack();
	ds.deallocateFromTheLeftStack();

	std::cin.get();

}
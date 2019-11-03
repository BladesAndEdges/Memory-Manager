#include <iostream>

#include "StackAllocator.h"
#include "DoubleEndedStackAllocator.h"

int main()
{

	DoubleEndedStackAllocator<int> ds(3);
	ds.allocateOnTheLeftStack(1);
	ds.deallocateFromTheLeftStack();
	ds.allocateOnTheLeftStack(2);
	ds.deallocateFromTheLeftStack();
	ds.allocateOnTheLeftStack(3);
	ds.deallocateFromTheLeftStack();

	std::cin.get();

}
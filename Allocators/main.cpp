#include <iostream>

#include "StackAllocator.h"
#include "DoubleEndedStackAllocator.h"
#include "PoolAllocator.h"

int main()
{

	PoolAllocator<int> p(3);
	int *a = p.allocateElementInPool(0);
	int *b = p.allocateElementInPool(1);
	int *c = p.allocateElementInPool(2);
	int *d = p.allocateElementInPool(3);
	std::cin.get();

}
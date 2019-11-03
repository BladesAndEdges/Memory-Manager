#include <iostream>

#include "StackAllocator.h"
#include "DoubleEndedStackAllocator.h"
#include "PoolAllocator.h"

int main()
{

	PoolAllocator p(3);
	uint32_t *a = p.allocateElementInPool(0);
	uint32_t *b = p.allocateElementInPool(1);
	uint32_t *c = p.allocateElementInPool(2);
	uint32_t *d = p.allocateElementInPool(3);
	std::cin.get();
}
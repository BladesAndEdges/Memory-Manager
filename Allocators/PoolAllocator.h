#pragma once

#include <cstdint>
#include <vector>

class PoolAllocator
{

public:

	size_t m_blocksInPool;

	uint32_t* m_blocks;
	bool* m_freeBlocks;

	int m_currentlyFreeBlocks;

	PoolAllocator(size_t blocksRequested);

	uint32_t* allocateElementInPool(uint32_t element);

	void deallocateElementInPool(uint32_t* ptrToElementToBeFreed);

	~PoolAllocator();
};


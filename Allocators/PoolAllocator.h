#pragma once

#include <cstdint>
#include <vector>


template<typename T>
class PoolAllocator
{

public:

	size_t m_blocksInPool;

	T* m_blocks;
	bool* m_freeBlocks;

	int m_currentlyFreeBlocks;

	PoolAllocator(size_t blocksRequested);

	T* allocateElementInPool(T element);

	void deallocateElementInPool(T* ptrToElementToBeFreed);

	bool isEmpty() const;

	~PoolAllocator();
};

#include "PoolAllocator.inl"


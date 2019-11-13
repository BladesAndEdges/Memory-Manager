#pragma once
/*
	This class implements a Pool allocator structure

	Members:

	size_t m_blocksInPool - The amount of blocks that will be available in the memory pool.

	T* m_blocks - A pointer to the beginning location of our allocated memory pool.

	bool* m_freeBlocks - A pointer to an array of boolean values. Equal to the size of the amount of blocks
							int the pool. Made to map a boolean to a block in the memory pool as a way of indicating
							if that block is free for allocation or not.

	uint32_t m_freeBlocks - The amount of free blocks in the pool. 

	Methods:

	PoolAllcoator(size_t blocksRequested) - Divides the allocated memory equally among the blocks requested.

	T* allocatedElementOnPool(T element) allocates an element and returns a pointer to that element

	void deallocateElementInPool(T* ptrToElementToBeFreed) - Using a pointer to that element, deallocates the given block, 
																by marking it as reusable via setting the corresponding value
																in the boolean array to true.

	bool isEmpty() const - returns true if the allocator is currently not allocating any elements. I.e. if all blocks are reusable.
	
*/

#include <cstdint>
#include <vector>


template<typename T>
class PoolAllocator
{

public:

	size_t m_blocksInPool;

	T* m_blocks;
	bool* m_freeBlocks;

	size_t m_currentlyFreeBlocks;

	PoolAllocator(size_t blocksRequested);

	T* allocateElementInPool(const T& element);

	void deallocateElementInPool(T* ptrToElementToBeFreed);

	size_t sizeOfPool() const;

	bool isEmpty() const;

	~PoolAllocator();
};

#include "PoolAllocator.inl"


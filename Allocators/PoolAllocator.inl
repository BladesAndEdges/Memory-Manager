#include <assert.h>
#include "PoolAllocator.h"

/*
	This methods initializes a memory pool, by allocating memory equal to blocksRequested * sizeof(T) 
*/
template<typename T>
PoolAllocator<T>::PoolAllocator(size_t blocksRequested) : m_blocksInPool(blocksRequested), m_currentlyFreeBlocks(m_blocksInPool)
{
	/*Allocate pool memory*/
	m_blocks = new T[m_blocksInPool];

	/*A correspodning boolean array. That maps a boolean in it to a block in the memory pool*/
	m_freeBlocks = new bool[m_blocksInPool];

	/*Initializes them all to true (block is free)*/
	for (int i = 0; i < m_blocksInPool; i++)
	{
		m_freeBlocks[i] = true;
	}
}

/*
	Allocates an element at the first free block found.

	Args:

	T element - the element to be allocated on the pool
*/
template<typename T>
T* PoolAllocator<T>::allocateElementInPool(const T& element)
{
	/*A pointer to the data, that we will later use*/
	T* pointerToData = nullptr;

	/*Make sure there are remaining free block*/
	assert(m_currentlyFreeBlocks > 0);

	/*Traverse the pool, if a free block is found, use it*/
	for (int i = 0; i < m_blocksInPool; i++)
	{
		if (m_freeBlocks[i] == true)
		{
			/*Create a pointer and allocate the element at that index*/
			pointerToData = &m_blocks[i];
			m_blocks[i] = element;

			/*Mark the block as false (being used)*/
			m_freeBlocks[i] = false;

			/*End the loop as we have allocated the element*/
			break;
		}

	}

	m_currentlyFreeBlocks--;

	return pointerToData;
}

/*
	Using the pointer that was used to store the returned value of the correspodning allocation function,
	finds the matching address and marks that blocks as free, so that it may be reused. 

	DOES NOT DELETE THE VALUE THERE THOUGH - Possibly an issue(?)

	Args:

	T* ptrToElementToBeFreed - A pointer that was used to store the return value of an allocate function. 
	
*/
template<typename T>
void PoolAllocator<typename T>::deallocateElementInPool(T* ptrToElementToBeFreed)
{
	assert(m_currentlyFreeBlocks  < m_blocksInPool);

	/*Use address subtraction to get the exact offset*/
	size_t offset = ptrToElementToBeFreed - m_blocks;


	/*Set the deallocated block to true (free)*/
	m_freeBlocks[offset] = true;
	m_currentlyFreeBlocks++;
}

template<typename T>
inline size_t PoolAllocator<T>::sizeOfPool() const
{
	return m_blocksInPool - m_currentlyFreeBlocks;
}

/*
	Checks if there are free blocks remianing
*/
template<typename T>
bool PoolAllocator<T>::isEmpty() const
{
	for (int i = 0; i < m_blocksInPool; i++)
	{
		if (m_freeBlocks[i] == false)
		{
			return false;
		}
	}

	return true;
}

/*
	Deletes the allocated memory
*/
template<typename T>
PoolAllocator<T>::~PoolAllocator()
{
	delete[] m_blocks;
}

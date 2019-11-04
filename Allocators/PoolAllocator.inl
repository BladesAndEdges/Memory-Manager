#include "PoolAllocator.h"
#include <assert.h>


template<typename T>
PoolAllocator<T>::PoolAllocator(size_t blocksRequested) : m_blocksInPool(blocksRequested), m_currentlyFreeBlocks(m_blocksInPool)
{
	m_blocks = new T[m_blocksInPool];
	m_freeBlocks = new bool[m_blocksInPool];

	for (int i = 0; i < m_blocksInPool; i++)
	{
		m_freeBlocks[i] = true;
	}
}

template<typename T>
T* PoolAllocator<T>::allocateElementInPool(T element)
{

	T* pointerToData = nullptr;

	assert(m_currentlyFreeBlocks > 0);

	for (int i = 0; i < m_blocksInPool; i++)
	{
		if (m_freeBlocks[i] == true)
		{
			pointerToData = &m_blocks[i];
			m_blocks[i] = element;
			m_freeBlocks[i] = false;
			break;
		}
	}

	m_currentlyFreeBlocks--;

	return pointerToData;
}

template<typename T>
void PoolAllocator<typename T>::deallocateElementInPool(T* ptrToElementToBeFreed)
{
	assert(m_currentlyFreeBlocks  < m_blocksInPool);

	int offset = ptrToElementToBeFreed - m_blocks;

	//Do something with the previously allocated value or ?
	//Figure out what you do with the value

	m_freeBlocks[offset] = true;
	m_currentlyFreeBlocks++;
}

template<typename T>
bool PoolAllocator<T>::isEmpty() const
{
	return (m_currentlyFreeBlocks == 0);
}

template<typename T>
PoolAllocator<T>::~PoolAllocator()
{
	delete[] m_blocks;
}

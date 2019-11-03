#include "PoolAllocator.h"
#include <assert.h>



PoolAllocator::PoolAllocator(size_t blocksRequested) : m_blocksInPool(blocksRequested), m_currentlyFreeBlocks(m_blocksInPool)
{
	m_blocks = new uint32_t[m_blocksInPool];
	m_freeBlocks = new bool[m_blocksInPool];

	for (int i = 0; i < m_blocksInPool; i++)
	{
		m_freeBlocks[i] = true;
	}
}

uint32_t* PoolAllocator::allocateElementInPool(uint32_t element)
{

	uint32_t* pointerToData = nullptr;

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

void PoolAllocator::deallocateElementInPool(uint32_t* ptrToElementToBeFreed)
{
	assert(m_currentlyFreeBlocks  < m_blocksInPool);

	int offset = ptrToElementToBeFreed - m_blocks;

	//Do something with the previously allocated value or ?

	m_freeBlocks[offset] = true;
	m_currentlyFreeBlocks++;
}

PoolAllocator::~PoolAllocator()
{
	delete[] m_blocks;
}

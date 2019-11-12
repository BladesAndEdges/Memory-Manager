#pragma once

#include "DoubleEndedStackAllocator.h"
#include "StackAllocator.h"
#include "PoolAllocator.h"

#include <exception>

/*

*/

enum class AllocationStrategy
{
	STACK, 
	DOUBLESTACK, 
	POOL
};

enum class DoubleStack
{
	BOTTOM, 
	TOP
};

template<typename T, typename U>
class MemoryManager
{

public:

	StackAllocator<T> m_stack;
	DoubleEndedStackAllocator<T> m_doubleEndedStack;
	PoolAllocator<T> m_poolAllocator;

	AllocationStrategy m_allocationStrategy;

	uint32_t m_elementsManaged;

	inline MemoryManager(AllocationStrategy allocationStrategy, uint32_t amountOfDataInBlocks);

	void allocateElement(const U& element);
	void allocateElement(const U& element, DoubleStack side );

	void deallocateElements();
	void deallocateElements(DoubleStack side);
	U* deallocateElements(uint32_t position);

	bool checkIfActive();

	~MemoryManager();
};

#include "MemoryManager.inl"

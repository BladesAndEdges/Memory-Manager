#pragma once

#include "DoubleEndedStackAllocator.h"
#include "StackAllocator.h"
#include "PoolAllocator.h"

#include <exception>

/*
	Enum class representing what 
	allocation strategy is used.
*/
enum class AllocationStrategy
{
	STACK, 
	DOUBLESTACK, 
	POOL
};

/*
	Enum class for indicating
	where we want to allocate/deallocate
	in the double stack
*/
enum class DoubleStack
{
	BOTTOM, 
	TOP
};

template<typename T>
class MemoryManager
{

public:

	StackAllocator<T> *m_stackAllocator;
	DoubleEndedStackAllocator<T> *m_doubleEndedStackAllocator;
	PoolAllocator<T> *m_poolAllocator;

	AllocationStrategy m_allocationStrategy;

	uint32_t m_elementsManaged;
	size_t m_amountOfDataInBlocks;

	inline MemoryManager(AllocationStrategy allocationStrategy, size_t amountOfDataInBlocks);

	void allocateElement(const T& element);
	void allocateElement(const T& element, DoubleStack side );
	T* allocateElement(const T& element);

	void deallocateElement();
	void deallocateElements(DoubleStack side);
	void deallocateElement(T* position);

	bool checkIfActive();

	~MemoryManager();
};

#include "MemoryManager.inl"

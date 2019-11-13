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

/*
	A Memory Manager class trying to consolidate the created allocator classes
	into one single class. The Memory manager contains pointers to the allocators which
	it takes care of.

	Members: 

	m_stackAllocator - pointer to an StackAllocator
	m_doubleEndedStackAllocator - pointer to a doubleEndedStackAllocator
	m_poolAllocator - pointer to a pool allocator

	m_AllocationStrategy - Used to specify which type of allocator is being used for the memory manager.
	m_elementsManaged - The amount of elements in the memory manager
	m_amountOfDataInBlocks - The amount of memory that will be allocated on the heap

	Methods:

	T* allocateElement(const T& element) - Allocates an element for the Stack and the pool
	void allocateElement(const T& element, DoubleStack side ) - overloaded function for the DoubleEndedStack

	void deallocateElement() - deallocates from the stack
	void deallocateElement(DoubleStack side) - deallocates from the double ended stack
	void deallocateElement(T* position) - deallocates from the pool

	bool checkIfActive() - checks if the memory manager has elements residing in it
*/
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

	T* allocateElement(const T& element);
	void allocateElement(const T& element, DoubleStack side );

	void deallocateElement();
	void deallocateElement(DoubleStack side);
	void deallocateElement(T* position);

	bool checkIfActive();

	~MemoryManager();
};

#include "MemoryManager.inl"

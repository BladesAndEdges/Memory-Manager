#pragma once
#include "MemoryManager.h"
#include <assert.h>

/*
	The constructor takes in the type of allocation strategy that should be used in the memory manager.
	The second argument is the amount of elements that will be set as a maximum for the memory manager to handle.
*/
template<typename T>
inline MemoryManager<T>::MemoryManager(AllocationStrategy allocationStrategy, size_t amountOfDataInBlocks) : m_allocationStrategy(allocationStrategy), 
																												m_amountOfDataInBlocks(amountOfDataInBlocks),
																												m_elementsManaged(0), 
																												m_stackAllocator(nullptr), 
																												m_doubleEndedStackAllocator(nullptr), 
																												m_poolAllocator(nullptr)
																						
{

	/*
		Choose allocation strategy.
	*/
	switch (m_allocationStrategy)
	{
	case AllocationStrategy::STACK:
		m_stackAllocator = new StackAllocator<T>(m_amountOfDataInBlocks);
		break;
	case AllocationStrategy::DOUBLESTACK:
		m_doubleEndedStackAllocator = new DoubleEndedStackAllocator<T>(m_amountOfDataInBlocks);
		break;
	case AllocationStrategy::POOL:
		m_poolAllocator = new PoolAllocator<T>(m_amountOfDataInBlocks);
	default:
		std::exception("Unknown allocation strategy requested.");
		break;
	}
}

/*
	Allocation of an element on the data structure chosen.
*/
template<typename T>
inline T* MemoryManager<T>::allocateElement(const T& element)
{
	switch (m_allocationStrategy)
	{
	case AllocationStrategy::STACK:
		m_stackAllocator->pushElementOnStack(element);
		return nullptr;
		break;
	case AllocationStrategy::POOL:
		return m_poolAllocator->allocateElementInPool(element);
	default:
		std::exception("You might've chosen the DOUBLE-ENDED Stack allocaiton startegy. Please use the corresponding allocation function.");
		return nullptr;
		break;
	}
}

/*
	Allocation on the DoubleEndedStackAlloctor
*/
template<typename T>
inline void MemoryManager<T>::allocateElement(const T& element, DoubleStack side)
{
	switch (side)
	{

	case DoubleStack::BOTTOM:
		m_doubleEndedStackAllocator->allocateOnTheBottomStack(element);
		break;
	case DoubleStack::TOP:
		m_doubleEndedStackAllocator->allocateOnTheTopStack(element);
		break;
	default:
		std::exception("Unknown member of DoubleStack used.");
	}
}

/*
	Due to the differences between the deallocation functions, 
	they had to be overloaded for the different allocation structure.
*/
template<typename T>
inline void MemoryManager<T>::deallocateElement()
{
	m_stackAllocator->popElementFromStack();
}

/*
	We only need to know which side we wish to deallocate from, thus the only argument
	is specified by the given side.
*/
template<typename T>
inline void MemoryManager<T>::deallocateElement(DoubleStack side)
{
	switch (side)
	{
	case DoubleStack::BOTTOM:
		m_doubleEndedStackAllocator->deallocateFromTheBottomStack();
		break;
	case DoubleStack::TOP:
		m_doubleEndedStackAllocator->deallocateFromTheTopStack();
	default:
		std::exception("Unknown member of DoubleStack used.");
	}
}

template<typename T>
inline void MemoryManager<T>::deallocateElement(T* element)
{
	m_poolAllocator->deallocateElementInPool(element);
}

template<typename T>
inline bool MemoryManager<T>::checkIfActive()
{
	/*
		isEmpty() would return true if there are no elements residing in the allocator.
		We return the negation of this as our answer if the memory manager is currently active, i.e. is being
		used and has elements in it.

		So if isEmpty() returns false, then conversely we would see that it returns true for the checkIfActive function
	*/
	switch (m_allocationStrategy)
	{
	case AllocationStrategy::STACK :
		return !(m_stackAllocator->isEmpty());
		break;
	case AllocationStrategy::DOUBLESTACK :
		return !(m_doubleEndedStackAllocator->isEmpty());
		break;
	case AllocationStrategy::POOL:
		return !(m_poolAllocator->isEmpty());
	default:
		return false;
		break;
	}
}

/*
	Delete the memory
	Set all the pointers to nullptr
*/
template<typename T>
inline MemoryManager<T>::~MemoryManager()
{
	switch (m_allocationStrategy)
	{

	case AllocationStrategy::STACK:
		delete m_stackAllocator;
		m_stackAllocator = nullptr;
		break;
	case AllocationStrategy::DOUBLESTACK:
		delete m_doubleEndedStackAllocator;
		m_doubleEndedStackAllocator = nullptr;
	case AllocationStrategy::POOL:
		delete m_poolAllocator;
		m_poolAllocator = nullptr;

	default:
		m_stackAllocator = nullptr;
		m_doubleEndedStackAllocator = nullptr;
		m_poolAllocator= nullptr;
	}
}

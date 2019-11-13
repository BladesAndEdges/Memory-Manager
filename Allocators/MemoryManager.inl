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
		std::cout << "Stack called" << std::endl;
		m_stackAllocator = new StackAllocator<T>(m_amountOfDataInBlocks);
		break;
	case AllocationStrategy::DOUBLESTACK:
		std::cout << "Double Ended Stack" << std::endl;
		m_doubleEndedStackAllocator = new DoubleEndedStackAllocator<T>(m_amountOfDataInBlocks);
		break;
	case AllocationStrategy::POOL:
		std::cout << "Pool Allocator used" << std::endl;
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
inline void MemoryManager<T>::allocateElement(const T& element)
{
	switch (m_allocationStrategy)
	{
	case AllocationStrategy::STACK:
		m_stackAllocator->
		break;
	case AllocationStrategy::POOL:
		std::cout << "Pool Allocator used" << std::endl;
	default:
		std::exception("You might've chosen the DOUBLE-ENDED Stack allocaiton startegy. Please use the corresponding allocation function.");
		break;
	}
}

template<typename T>
inline void MemoryManager<T>::allocateElement(const T& element, DoubleStack side)
{
	switch (side)
	{

	case DoubleStack::BOTTOM:
		break;
	case DoubleStack::TOP:
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
}

template<typename T>
inline void MemoryManager<T>::deallocateElement(DoubleStack side)
{
}

template<typename T>
inline T* MemoryManager<T>::deallocateElement(T* element)
{
}

template<typename T>
inline bool MemoryManager<T>::checkIfActive()
{
	return false;
}

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

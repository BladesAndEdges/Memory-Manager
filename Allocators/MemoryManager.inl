#pragma once
#include "MemoryManager.h"

template<typename T, typename U>
inline MemoryManager<T, U>::MemoryManager(AllocationStrategy allocationStrategy, uint32_t amountOfDataInBlocks) : m_allocationStrategy(allocationStrategy), 
																												m_amountOfDataInBlocks(amountOfDataInBlocks),
																												m_elementsManaged(0)
{
	switch (m_allocationStrategy)
	{
	case AllocationStrategy::STACK:
		std::cout << "Stack called" << std::endl;
		break;
	case AllocationStrategy::DOUBLESTACK:
		std::cout << "Double Ended Stack" << std::endl;
		break;
	case AllocationStrategy::POOL:
		std::cout << "Pool Allocator used" << std::endl;
	default:
		std::exception("Unknown allocation strategy requested.");
		break;
	}
}

template<typename T, typename U>
inline void MemoryManager<T, U>::allocateElement(const U & element)
{
	switch (m_allocationStrategy)
	{
	case AllocationStrategy::STACK:
		std::cout << "Stack called" << std::endl;
		break;
	case AllocationStrategy::POOL:
		std::cout << "Pool Allocator used" << std::endl;
	default:
		std::exception("You might've chosen the DOUBLE-ENDED Stack allocaiton startegy. Please use the corresponding allocation function.");
		break;
	}
}

template<typename T, typename U>
inline void MemoryManager<T, U>::allocateElement(const U & element, DoubleStack side)
{
	switch (side)
	{

	case DoubleStack::BOTTOM:
		break;
	case DoubleStack::TOP:
		break;
	default:
		std::exception("Unknown member of DoubleStack used.")
		break;
	}
}

template<typename T, typename U>
inline void MemoryManager<T, U>::deallocateElements()
{
}

template<typename T, typename U>
inline void MemoryManager<T, U>::deallocateElements(DoubleStack side)
{
}

template<typename T, typename U>
inline U* MemoryManager<T, U>::deallocateElements(uint32_t position)
{
}

template<typename T, typename U>
inline bool MemoryManager<T, U>::checkIfActive()
{
	return false;
}

template<typename T, typename U>
inline MemoryManager<T, U>::~MemoryManager()
{
}

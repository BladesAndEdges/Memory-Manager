#pragma once

#include <cstdint>

template<typename T>
class DoubleEndedStackAllocator
{

public:

	T* m_buffer;
	size_t m_totalBufferCapacity;

	uint32_t m_elementsAllocatedOnLeftStack;
	uint32_t m_elementsAllocatedOnRightStack;

	DoubleEndedStackAllocator(size_t bufferCapacity);

	/*Adding elements to the stacks*/
	void allocateOnTheLeftStack(const T& element);
	void allocateOnTheRightStack(const T& element);


	/*Removing elements from the stacks*/
	void deallocateFromTheLeftStack();
	void deallocateFromTheRightStack();



	bool isEmpty();


	~DoubleEndedStackAllocator();
};

#include "DoubleEndedStackAllocator.inl"


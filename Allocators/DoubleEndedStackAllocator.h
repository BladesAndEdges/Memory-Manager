#pragma once

#include <cstdint>

class DoubleEndedStackAllocator
{

public:

	uint32_t* m_buffer;
	size_t m_totalBufferCapacity;

	uint32_t m_elementsAllocatedOnLeftStack;
	uint32_t m_elementsAllocatedOnRightStack;

	DoubleEndedStackAllocator(size_t bufferCapacity);

	/*Adding elements to the stacks*/
	void allocateOnTheLeftStack(uint32_t element);
	void allocateOnTheRightStack(uint32_t element);


	/*Removing elements from the stacks*/
	void deallocateFromTheLeftStack();
	void deallocateFromTheRightStack();



	bool isEmpty();


	~DoubleEndedStackAllocator();
};

#include "DoubleEndedStackAllocator.inl"


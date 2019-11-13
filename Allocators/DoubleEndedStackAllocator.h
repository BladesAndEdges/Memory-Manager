#pragma once
#include <cstdint>

/*
	A template class created to implement a Double Ended Stack
	Allocator.

	Class Innards:

	m_buffer - A pointer to the locaiton of memory that has been allocated
			   for our data structure.

	m_totalBufferCapacity - The maximum amount of elements the stack can hold
							before overflowing.

	m_elementsAllocatedOnLeftStack - The amount of elements currently residing on the 
									"left" (bottom) side of the stack stack

	m_elementsAllocatedOnLeftStack - The amount of elements currently residing on the
									"right" (top) side of the stack stack

	Methods:

	allocateOnLeftStack(const T& element) - Adds an element to the left(bottom) side of the stack.

	allocateOnRightStack(const T& element) - Adds an element to the right(top) side of the stack.

	deallocateFromTheLeftStack() - Takes out an element from the left(bottom) side of the stack.
	deallocateFromTheRightStack() - Takes out an element from the right(top) side of the stack.

	isEmpty - Returns true if the sum of the elements on the left side and the right side is equal to true.
			  Otherwise returns false.
*/
template<typename T>
class DoubleEndedStackAllocator
{

public:

	T* m_buffer;
	size_t m_totalBufferCapacity;

	uint32_t m_elementsAllocatedOnBottomStack;
	uint32_t m_elementsAllocatedOnTopStack;

	DoubleEndedStackAllocator(size_t bufferCapacity);

	/*Adding elements to the stacks*/
	void allocateOnTheBottomStack(const T& element);
	void allocateOnTheTopStack(const T& element);


	/*Removing elements from the stacks*/
	void deallocateFromTheBottomStack();
	void deallocateFromTheTopStack();

	bool isEmpty();

	uint32_t sizeOfDoubleStack();

	~DoubleEndedStackAllocator();
};

#include "DoubleEndedStackAllocator.inl"


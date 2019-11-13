#include <iostream>
#include <assert.h>
#include "DoubleEndedStackAllocator.h"

/*
	Allocates memory for sizeof(T) * bufferCapacity amount of elements. 
	Intializes the amount of elements set on both the left and right side to zero.
*/
template<typename T>
DoubleEndedStackAllocator<T>::DoubleEndedStackAllocator(size_t bufferCapacity) : m_totalBufferCapacity(bufferCapacity),
m_elementsAllocatedOnBottomStack(0),
m_elementsAllocatedOnTopStack(0)
{
	m_buffer = new T[m_totalBufferCapacity];
}

/*
	Allocation on the bottom side of the stack.

	Params:
	const T& element - the element that will be stored at the bottom side of the stack.
*/
template<typename T>
void DoubleEndedStackAllocator<T>::allocateOnTheBottomStack(const T& element)
{
	/*Check if we've reached the maxium stack capacity*/
	assert((m_elementsAllocatedOnBottomStack + m_elementsAllocatedOnTopStack) < m_totalBufferCapacity);

	/*	
		Simply move the offset equal to the amount of elements. 
		This can be done as all the elements present
		are of th same type.
	*/
	*(m_buffer + m_elementsAllocatedOnBottomStack) = element;

	m_elementsAllocatedOnBottomStack++;
}

/*
	Allocation on the top side of the stack.

	Params:
	const T& element - the element that will be stored at the top side of the stack.


	A couple of notes:

	I do understand that it would've been best if the code actually allowed the pop methods to return
	the actual values, but this is an easy fix, so I decided to leave it as it is for simplicity. 
	The goal of the coursework focused on the memory management, and not on the requirements to build a proper
	DoubleEnded stack that can be used with the values inside (?).
*/
template<typename T>
void DoubleEndedStackAllocator<T>::allocateOnTheTopStack(const T& element)
{
	/*
		Since our starting point would be at index 0, the last index would be equal to 
		theAmountTheStackCanStore - 1.
	*/
	size_t offset = m_totalBufferCapacity - 1;

	/*Check if we've reached the maximum stack capacity*/
	assert((m_elementsAllocatedOnBottomStack + m_elementsAllocatedOnTopStack) < m_totalBufferCapacity);

	/*Set the value at that index to the passed element*/
	*(m_buffer + offset - m_elementsAllocatedOnTopStack) = element;

	m_elementsAllocatedOnTopStack++;
}

/*
	Deallocate top element of the bottom stack.
*/
template<typename T>
void DoubleEndedStackAllocator<T>::deallocateFromTheBottomStack()
{	
	/*Check that we will not underflow*/
	assert(m_elementsAllocatedOnBottomStack > 0);

	m_elementsAllocatedOnBottomStack--;
}

/*
	Deallocate element from the top stack
*/
template<typename T>
void DoubleEndedStackAllocator<T>::deallocateFromTheTopStack()
{
	assert(m_elementsAllocatedOnTopStack > 0);
	m_elementsAllocatedOnTopStack--;
}

/*
	Checks if the strucutre holds no elements
*/
template<typename T>
bool DoubleEndedStackAllocator<T>::isEmpty()
{
	return ((m_elementsAllocatedOnTopStack + m_elementsAllocatedOnBottomStack) == 0);
}

template<typename T>
inline uint32_t DoubleEndedStackAllocator<T>::sizeOfDoubleStack()
{
	return m_elementsAllocatedOnBottomStack + m_elementsAllocatedOnTopStack;
}

/*
	Free the preallocated memory
*/
template<typename T>
DoubleEndedStackAllocator<T>::~DoubleEndedStackAllocator()
{
	delete[] m_buffer;
}
#pragma once
#include<cstdint>

/*

	A template class created to implement a Stack Allocation data
	structure. 

	Class Innards:

	m_buffer - A pointer to the locaiton of memory that has been allocated
			   for our data structure.

	m_totalBufferCapacity - The maximum amount of elements the stack can hold 
							before overflowing.

	m_elementsOnStack
	Methods:



*/
template<typename T>
class StackAllocator
{

public:

	T* m_buffer;
	size_t m_totalBufferCapacity;
	uint32_t m_elementsOnStack;

	StackAllocator(size_t capacity);
	~StackAllocator();

	void pushElementOnStack(const T& element);
	void popElementFromStack();

	bool isEmpty() const;

};

#include "StackAllocator.inl"


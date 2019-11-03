#pragma once
#include<cstdint>

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


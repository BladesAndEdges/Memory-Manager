#pragma once
#include<cstdint>

template<typename T>
class StackAllocator
{

public:

	T* m_startOfStack;
	T* m_topOfStack;
	uint32_t m_maxElements;

	uint32_t m_totalUsage;

	StackAllocator(uint32_t capacity);
	~StackAllocator();

	void pushElementOnStack(const T& element);
	void popElementFromStack();

	void peekTopElementOfStack() const;

	bool isEmpty() const;

};

#include "StackAllocator.inl"


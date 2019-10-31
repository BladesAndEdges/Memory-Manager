#pragma once
#include<cstdint>

template<typename T>
class StackAllocator
{

public:

	uint32_t* m_startOfStack;
	uint32_t* m_topOfStack;
	uint32_t m_maxElements;

	uint32_t m_totalUsage;

	StackAllocator(uint32_t size);
	~StackAllocator();

	void pushElementOnStack(const T& element);
	void popElementFromStack();

	void peekTopElementOfStack() const;

	bool isEmpty() const;

};

#include "StackAllocator.inl"


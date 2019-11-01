#pragma once

#include <cstdint>


class DoubleEndedStackAllocator
{

	uint32_t* m_leftStartOfStack;
	uint32_t* m_rightStartOfStack;

	uint32_t* m_leftTopOfStack;
	uint32_t* m_rightTopOfStack;

	size_t m_maxElements;
	uint32_t m_totalUsage;
	uint32_t m_leftOffset;
	uint32_t m_rightOffset;

	uint32_t* m_startOfStack;

public:

	void addElementToLeftStack(uint32_t element);
	void addElementToRightStack(uint32_t element);

	//void popElementOffLeftStack();
	//void popElementOffRightStack();

	//bool isEmpty();
	//bool lestStackIsEmpty();
	//bool rightStackIsEmpty();

	DoubleEndedStackAllocator(size_t capacity);
	~DoubleEndedStackAllocator();
};

#include "DoubleEndedStackAllocator.inl"


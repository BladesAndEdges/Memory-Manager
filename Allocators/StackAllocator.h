#pragma once

#include<cstdint>

class StackAllocator
{

public:

	int* m_startOfStack;
	int* m_topOfStack;
	uint32_t m_maxElements;

	StackAllocator(uint32_t size);
	~StackAllocator();



};


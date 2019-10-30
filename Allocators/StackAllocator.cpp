#include "StackAllocator.h"
#include <assert.h>



StackAllocator::StackAllocator(uint32_t capacity) : m_maxElements(capacity)
{
	m_startOfStack = new int[m_maxElements];
	m_topOfStack = m_startOfStack;
}


StackAllocator::~StackAllocator()
{
	assert(m_startOfStack != nullptr);
	delete[] m_startOfStack;
	m_startOfStack = nullptr;

	assert(m_topOfStack != nullptr);
	m_topOfStack = nullptr;
	
}

#include "DoubleEndedStackAllocator.h"
#include <assert.h>

DoubleEndedStackAllocator::DoubleEndedStackAllocator(size_t bufferCapacity) : m_totalBufferCapacity(bufferCapacity),
																			m_elementsAllocatedOnLeftStack(0),
																			m_elementsAllocatedOnRightStack(0)
{
	m_buffer = new uint32_t[m_totalBufferCapacity];
}

void DoubleEndedStackAllocator::allocateOnTheLeftStack(uint32_t element)
{
	uint32_t offset = m_totalBufferCapacity - 1;

	/*Check if we've reached the maxium stack capacity*/
	assert((m_elementsAllocatedOnLeftStack + m_elementsAllocatedOnRightStack) < m_totalBufferCapacity);

	*(m_buffer + m_elementsAllocatedOnLeftStack) = element;

	m_elementsAllocatedOnLeftStack++;
}

void DoubleEndedStackAllocator::allocateOnTheRightStack(uint32_t element)
{	
	uint32_t offset = m_totalBufferCapacity - 1;

	/*Check if we've reached the maximum stack capacity*/
	assert((m_elementsAllocatedOnLeftStack + m_elementsAllocatedOnRightStack) < m_totalBufferCapacity);

	*(m_buffer + offset - m_elementsAllocatedOnRightStack) = element;

	m_elementsAllocatedOnRightStack++;
}

void DoubleEndedStackAllocator::deallocateFromTheLeftStack()
{
	assert(m_elementsAllocatedOnLeftStack > 0);
	m_elementsAllocatedOnLeftStack--;
}

void DoubleEndedStackAllocator::deallocateFromTheRightStack()
{
	assert(m_elementsAllocatedOnRightStack > 0);
	m_elementsAllocatedOnRightStack--;
}

bool DoubleEndedStackAllocator::isEmpty()
{
	return (m_totalBufferCapacity == 0);
}

DoubleEndedStackAllocator::~DoubleEndedStackAllocator()
{
	delete[] m_buffer;
}



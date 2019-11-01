#include "DoubleEndedStackAllocator.h"
#include <assert.h>

DoubleEndedStackAllocator::DoubleEndedStackAllocator(size_t capacity) : m_maxElements(capacity),
																		m_totalUsage(0),
																		m_leftOffset(0), 
																		m_rightOffset(0)
{
	m_startOfStack = new uint32_t[m_maxElements];
	m_leftTopOfStack = m_startOfStack;
	m_leftStartOfStack = m_startOfStack;


	m_rightTopOfStack = m_startOfStack + m_maxElements;
	m_rightStartOfStack = m_startOfStack + m_maxElements;
}

void DoubleEndedStackAllocator::addElementToLeftStack(uint32_t element)
{
	/*Assert we have not exceeded the maximum capacity of the stack*/
	assert(m_totalUsage < m_maxElements);

	/*Assert we would not be attempting to overwrite a location belonging to the other stack*/
	assert(m_leftStartOfStack != m_rightTopOfStack);

	/*If it is the first insertion*/
	if (m_totalUsage == 0)
	{
		/*
		Store the element given. 
		Update the total usage for the stack, and for the left half as well.
		Do not move the pointer, however, as it points to the start of the block of memory
		allocating the data anyway.
		*/
		*(m_leftStartOfStack + m_leftOffset) = element;
		m_totalUsage++;
		m_leftOffset++;
	}
	/*Further pushes onto the stack increment the pointer*/
	else
	{
		/*
		Similarly, except now we wish to update the pointer as well.
		*/
		*(m_startOfStack + m_leftOffset) = element;
		m_totalUsage++;
		m_leftOffset++;
		m_leftTopOfStack++;
	}

}

void DoubleEndedStackAllocator::addElementToRightStack(uint32_t element)
{
	/*Assert we have not exceeded the maximum capacity of the stack*/
	assert(m_totalUsage < m_maxElements);

	/*Assert we would not be attempting to overwrite a location belonging to the other stack*/
	assert(m_rightTopOfStack != m_leftTopOfStack);

	/*If it is the first insertion*/
	if (m_totalUsage == 0)
	{
		/*
		Store the element given.
		Update the total usage for the stack, and for the left half as well.
		Do not move the pointer, however, as it points to the start of the block of memory
		allocating the data anyway.
		*/
		*(m_rightTopOfStack - m_rightOffset) = element;
		//m_rightTopOfStack--;

		m_totalUsage++;
		m_rightOffset++;
	}
	/*Further pushes onto the stack increment the pointer*/
	else
	{
		/*
		Similarly, except now we wish to update the pointer as well.
		*/
		*(m_rightTopOfStack - m_rightOffset) = element;
		m_rightTopOfStack--;

		m_totalUsage++;
		m_rightOffset++;
	}

}

DoubleEndedStackAllocator::~DoubleEndedStackAllocator()
{
}

#include <iostream>
#include <assert.h>

template<typename T>
DoubleEndedStackAllocator<T>::DoubleEndedStackAllocator(size_t bufferCapacity) : m_totalBufferCapacity(bufferCapacity),
m_elementsAllocatedOnLeftStack(0),
m_elementsAllocatedOnRightStack(0)
{
	m_buffer = new T[m_totalBufferCapacity];
}

template<typename T>
void DoubleEndedStackAllocator<T>::allocateOnTheLeftStack(const T& element)
{
	/*Check if we've reached the maxium stack capacity*/
	assert((m_elementsAllocatedOnLeftStack + m_elementsAllocatedOnRightStack) < m_totalBufferCapacity);

	*(m_buffer + m_elementsAllocatedOnLeftStack) = element;

	m_elementsAllocatedOnLeftStack++;
}

template<typename T>
void DoubleEndedStackAllocator<T>::allocateOnTheRightStack(const T& element)
{
	uint32_t offset = m_totalBufferCapacity - 1;

	/*Check if we've reached the maximum stack capacity*/
	assert((m_elementsAllocatedOnLeftStack + m_elementsAllocatedOnRightStack) < m_totalBufferCapacity);

	*(m_buffer + offset - m_elementsAllocatedOnRightStack) = element;

	m_elementsAllocatedOnRightStack++;
}

template<typename T>
void DoubleEndedStackAllocator<T>::deallocateFromTheLeftStack()
{
	assert(m_elementsAllocatedOnLeftStack > 0);
	m_elementsAllocatedOnLeftStack--;
}

template<typename T>
void DoubleEndedStackAllocator<T>::deallocateFromTheRightStack()
{
	assert(m_elementsAllocatedOnRightStack > 0);
	m_elementsAllocatedOnRightStack--;
}

template<typename T>
bool DoubleEndedStackAllocator<T>::isEmpty()
{
	return (m_totalBufferCapacity == 0);
}

template<typename T>
DoubleEndedStackAllocator<T>::~DoubleEndedStackAllocator()
{
	delete[] m_buffer;
}
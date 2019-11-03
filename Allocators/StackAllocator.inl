#include <iostream>
#include <assert.h>

template<typename T>
StackAllocator<T>::StackAllocator(size_t capacity) : m_totalBufferCapacity(capacity), m_elementsOnStack(0)
{
	m_buffer = new T[m_totalBufferCapacity];
}

template<typename T>
void StackAllocator<T>::pushElementOnStack(const T& element)
{
	/*Check if a stack overflow won't be made*/
	assert(m_elementsOnStack < m_totalBufferCapacity);

	*(m_buffer + m_elementsOnStack) = element;
	m_elementsOnStack++;
}

template<typename T>
void StackAllocator<T>::popElementFromStack()
{
	assert(m_elementsOnStack > 0);
	m_elementsOnStack--;
}

template<typename T>
bool StackAllocator<T>::isEmpty() const
{
	return(m_elementsOnStack == 0);
}

template<typename T>
StackAllocator<T>::~StackAllocator()
{
	assert(m_buffer != nullptr);
	delete[] m_buffer;
	m_buffer = nullptr;
}

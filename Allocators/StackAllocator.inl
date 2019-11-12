#include <iostream>
#include <assert.h>
#include "StackAllocator.h"

/*
	The constructor takes the size as it's argument.

	This decision was made due to the fact that we have a limited amount of memory
	allocated for the stack to use. The user therefore should specify the capacity, representing the amount
	of elements he wishes to store.
*/
template<typename T>
StackAllocator<T>::StackAllocator(size_t capacity) : m_totalBufferCapacity(capacity), m_elementsOnStack(0)
{
	//The preallocated block is of size m_totalBufferCapacity * sizeof(T).
	m_buffer = new T[m_totalBufferCapacity];
}

/*
	A method that adds an element on the stack.

	Params: 

	const T& element - a reference to the element to be stored on the stack.
*/
template<typename T>
void StackAllocator<T>::pushElementOnStack(const T& element)
{
	/*Check if a stack overflow won't be made*/
	assert(m_elementsOnStack < m_totalBufferCapacity);

	/*
	  Use the amount of elements as an offset. Since all elements are of the same 
	  data type, we won't need to worry about the offset being different after every
	  addition of a new element. 
	*/
	*(m_buffer + m_elementsOnStack) = element;

	m_elementsOnStack++;
}

/*
	A method that takes out an element from the stack.
*/
template<typename T>
void StackAllocator<T>::popElementFromStack()
{	
	/*If the stack is empty, make sure we do not underflow*/
	assert(m_elementsOnStack > 0);

	m_elementsOnStack--;
}

/*
	A method that checks the value of m_elementsOnStack.
	Should that value be 0, it returns true.
	Returns false otherwise.
*/
template<typename T>
bool StackAllocator<T>::isEmpty() const
{
	return(m_elementsOnStack == 0);
}

template<typename T>
inline uint32_t StackAllocator<T>::sizeOfStack() const
{
	return m_elementsOnStack;
}

/*
	Delete the memory allocated for the stack
	Set the pointer to nullptr so it would not remain dangling.
*/
template<typename T>
StackAllocator<T>::~StackAllocator()
{
	assert(m_buffer != nullptr);
	delete[] m_buffer;
	m_buffer = nullptr;
}

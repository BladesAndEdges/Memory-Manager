#include <iostream>
#include <assert.h>

template<typename T>
StackAllocator<T>::StackAllocator(uint32_t capacity) : m_maxElements(capacity), m_totalUsage(0)
{
	m_startOfStack = new T[m_maxElements];
	m_topOfStack = m_startOfStack;
}

template<typename T>
void StackAllocator<T>::pushElementOnStack(const T& element)
{
	/*Check if a stack overflow won't be made*/
	assert(m_totalUsage < m_maxElements);

	if (m_totalUsage == 0)
	{
		/*We do not want to move the top pointer if it's the first insertion*/
		*(m_startOfStack + m_totalUsage) = element;
		m_totalUsage++;
	}
	else
	{
		/*We move the top pointer here though*/
		*(m_startOfStack + m_totalUsage) = element;
		m_totalUsage++;
		m_topOfStack++;
	}

	//return?? 
}

template<typename T>
void StackAllocator<T>::popElementFromStack()
{
	assert(m_totalUsage > 0);
	m_topOfStack--;
	m_totalUsage--;
}

template<typename T>
void StackAllocator<T>::peekTopElementOfStack() const
{
	std::cout << "Top of stack is: " << *m_topOfStack << std::endl;
}

template<typename T>
bool StackAllocator<T>::isEmpty() const
{
	return(m_totalUsage == 0);
}

template<typename T>
StackAllocator<T>::~StackAllocator()
{
	assert(m_startOfStack != nullptr);
	delete[] m_startOfStack;
	m_startOfStack = nullptr;

	assert(m_topOfStack != nullptr);
	m_topOfStack = nullptr;
}

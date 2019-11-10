#include "CustomSmartPointer.h"
#include <iostream>

//Creation of the samrt pointer
template<typename T>
CustomSmartPointer<T>::CustomSmartPointer(T* data)
{
	m_internalPointer = data;
	*m_refCounter = 0;
	std::cout << "Constructor called" << std::endl;
	(*m_refCounter)++;
}

template<typename T>
inline CustomSmartPointer<T>::CustomSmartPointer(const CustomSmartPointer & other) : m_internalPointer(other.m_internalPointer), 
																					m_refCounter(other.m_refCounter)
{
	std::cout << "Copy constructor called" << std::endl;
	*(m_refCounter++);
}

template<typename T>
CustomSmartPointer<T>::~CustomSmartPointer()
{
	std::cout << "Destructor called" << std::endl;
	delete m_internalPointer;
	*(m_refCounter)--;
}

template<typename T>
T& CustomSmartPointer<T>::operator*()
{
	return *m_internalPointer;
}

template<typename T>
T* CustomSmartPointer<T>::operator->() 
{
	return m_internalPointer;
}

//
//template<typename T>
//T& CustomSmartPointer<T>::operator*()
//{
//	return *m_internalBuffer;
//}

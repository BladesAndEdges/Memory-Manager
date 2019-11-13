#include "CustomSmartPointer.h"
#include <iostream>

//Creation of the samrt pointer
template<typename T>
CustomSmartPointer<T>::CustomSmartPointer(T* data) : m_internalPointer(data),
													 m_refCounter(&m_refs), 
													m_refs(0)
{
	std::cout << "Constructor called" << std::endl;
}

/*
	Copy constructor
*/
template<typename T>
inline CustomSmartPointer<T>::CustomSmartPointer(const CustomSmartPointer & other) : m_internalPointer(other.m_internalPointer), 
																					m_refCounter(other.m_refCounter),
																					m_refs(other.m_refs)
																					
{
	std::cout << "Copy constructor called" << std::endl;
	(*m_refCounter)++;
}

/*
Destructor. Would delete memory only if no instances that reference it remain
*/
template<typename T>
CustomSmartPointer<T>::~CustomSmartPointer()
{
	std::cout << "Destructor called" << std::endl; // test

	if (*m_refCounter == 0)
	{
		std::cout << "Deleted memory" << std::endl; // testing
		delete m_internalPointer;
		m_internalPointer = nullptr;
	}
	else
	{
		(*m_refCounter)--;
	}
}

/*Overloaded operators*/
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

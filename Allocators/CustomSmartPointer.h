#pragma once

/*
	A class which attempts whose implementation aims to resemble that of
	the c++ shared_ptr. Includes creation, destruction, access to members, and reference counting.

	Members:

	T* m_internalPointer - This is the internal pointer that our class has wrapped around.

	int* m_refCounter - A pointer that is set to the address of m_refs of the ORIGINAL copy, i.e. the m_ref of
						the object that called the constructor. Each reference would create an object with the copy constructor.

	int m_refs - The amount of objects referencing this object.
	
*/

template<typename T>
class CustomSmartPointer
{

public:

	T* m_internalPointer;
	int* m_refCounter;
	int m_refs;

	CustomSmartPointer(T* data);
	CustomSmartPointer(const CustomSmartPointer& other);



	~CustomSmartPointer();

	T& operator*();

	T* operator->();
};

#include "CustomSmartPointer.inl"

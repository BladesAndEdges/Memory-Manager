#pragma once

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

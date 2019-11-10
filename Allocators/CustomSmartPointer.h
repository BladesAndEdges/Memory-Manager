#pragma once

template<typename T>
class CustomSmartPointer
{

public:

	T* m_internalPointer;
	int* m_refCounter;

	CustomSmartPointer(T* data);
	CustomSmartPointer(const CustomSmartPointer& other);


	~CustomSmartPointer();

	T& operator*();

	T* operator->();
};

#include "CustomSmartPointer.inl"

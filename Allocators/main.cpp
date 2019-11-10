/*
	Main.cpp is used as a testing file that carries out tests for specific conditions 
	under which the code may break, or throw exceptions. 

	Error checking has been done for the separate allocators, Custom Smart Pointer and the Memory Manager. 
*/

#include <iostream>

#include "StackAllocator.h" 
#include "DoubleEndedStackAllocator.h" 
#include "PoolAllocator.h"
#include "CustomSmartPointer.h"


/*
	Below I have created global instances of different data 
	types that I have used for the purpose of testing the 
	methods for the allocators.

	I have tried to test it on at least a single pod, struct, class and pointer for each allocator.
*/
struct Vector
{
	int x;
	int y;
};


class Test
{
public:

	int a;
	int b;

	Test(int x, int y) : a(x), b(y) {};
};

void print(CustomSmartPointer<Test> ptr)
{
	int a = ptr->a;

	std::cout << a << std::endl;
}

int main()
{


	std::cout << "Before" << std::endl;

	
		CustomSmartPointer<Test> t = CustomSmartPointer<Test>(new Test(1, 2));
		int ls = t->a;

		std::cout << ls << std::endl;


		print(t);
	
		{
			CustomSmartPointer<Test> cone = t;
			CustomSmartPointer<Test> ctwo = t;
		}


	std::cout << "After" << std::endl;

}
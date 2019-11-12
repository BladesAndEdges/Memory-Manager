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
	float x;
	float y;

	Vector() : x(0.0f), y(0.0f) {};
	Vector(float a, float b) : x(a), y(b) {};
};


class TestClass
{
public:

	int a;
	int b;

	TestClass() : a(0), b(0) {} ;
	TestClass(int x, int y) : a(x), b(y) {};
};

int main()
{

	/*STACK ALLOCATOR*/
	StackAllocator<int> stack(5);

//	/*--------------------------------------------------------------------------------------*/
//	/*
//		1.  Tests the allocation function. Testing to see if the stack will throw an assertion error if
//			we attempt to allcoate more elements than we have specified. 
//			Should throw an assertion error.
//	*/
//
//	stack.pushElementOnStack(1);
//	stack.pushElementOnStack(2);
//	stack.pushElementOnStack(3);
//	stack.pushElementOnStack(4);
//	stack.pushElementOnStack(5);
//	stack.pushElementOnStack(6); // I suggest also commenting out some of these values to assure that it works.
///*---------------------------------------------------------------------------------------*/



///*--------------------------------------------------------------------------------------*/
///*
//	2.  Tests that a stack that has no element yet produces true for isEmpty() and false otherwise
//		Should throw an assertion error.
//*/
//
//	std::cout << std::boolalpha << stack.isEmpty() << std::endl; // confirm stack is empty
//	stack.pushElementOnStack(500);
//	std::cout << std::boolalpha << stack.isEmpty() << std::endl;
//
///*---------------------------------------------------------------------------------------*/



///*--------------------------------------------------------------------------------------*/
///*
//	3.  Tests if deallocating an element from an empty stack, triggers an assertion error.
//*/
//
//	std::cout << std::boolalpha << stack.isEmpty() << std::endl; // confirm stack is empty
//	stack.popElementFromStack();
//
///*---------------------------------------------------------------------------------------*/



///*--------------------------------------------------------------------------------------*/
///*
//	4.  Tests if we can initialize a stack with both pod types and non-pod types.
//*/
//	Vector v(1.0f, 1.0f);
//	TestClass a(0, 1);
//
//	StackAllocator<float> fStack(5);
//
//	StackAllocator<std::string> strStack(5);
//	strStack.pushElementOnStack("Daniel");
//
//	StackAllocator<const char*> chptrStack(5);
//	chptrStack.pushElementOnStack("charPointer");
//
//
//	StackAllocator<Vector> vecStack(5);
//	vecStack.pushElementOnStack(v);
//
//	StackAllocator<TestClass> testStack(5);
//	testStack.pushElementOnStack(a);
//
///*---------------------------------------------------------------------------------------*/



///*--------------------------------------------------------------------------------------*/
//
//	/*5.  Tests the sizeOfStack function.*/
//
//	std::cout << "Stack Is Empty? " << std::boolalpha << stack.isEmpty() << std::endl;
//	std::cout << "SizeOfStack: " << stack.sizeOfStack() << std::endl;
//
//	stack.pushElementOnStack(1);
//
//	std::cout << "Stack Is Empty? " << std::boolalpha << stack.isEmpty() << std::endl;
//	std::cout << "SizeOfStack: " << stack.sizeOfStack() << std::endl;
//
//	stack.popElementFromStack(); 
//
//	std::cout << "Stack Is Empty? " << std::boolalpha << stack.isEmpty() << std::endl;
//	std::cout << "SizeOfStack: " << stack.sizeOfStack() << std::endl;
//
///*---------------------------------------------------------------------------------------*/



/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/

	/*TESTING FOR DOUBLE ENDED STACK ALLOCATOR*/
	DoubleEndedStackAllocator<int> doubleStack(5);

/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/

	/* TESTING FOR POOL ALLOCATOR*/
	PoolAllocator<int> pool(5);


	/*--------------------------------------------------------------------------------------*/
	/*
		1. Tests allocation beyond the maximum elements specified in the constructor.
		Should throw an assertion error.
	*/

	//int* a = pool.allocateElementInPool(1);
	//int* b = pool.allocateElementInPool(2);
	//int* c = pool.allocateElementInPool(3);
	//int* d = pool.allocateElementInPool(4);
	//int* e = pool.allocateElementInPool(5);
	//int* f = pool.allocateElementInPool(6);

	//std::cout << *a << std::endl;
	//std::cout << *b << std::endl;
	//std::cout << *c << std::endl;
	//std::cout << *d << std::endl;
	//std::cout << *e << std::endl;
	//std::cout << *f << std::endl;

	/*---------------------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------------------*/
	/*
		2. Testing for deallocation. A simple explanation as testing would not be possible

		The way I have strucutred the program, I am guarranteed that a request for deallocation
		when all blocks are unused would not do anything. I have to pass a pointer to an element, 
		to the stack. The only way to retrieve such a pointer is to get it returned by a corresponding
		allocate function. So a call to deallocate may be made with a non-valid address, but it would
		neither harm nor really do anything.
	*/
	/*---------------------------------------------------------------------------------------*/

	std::cin.get();

}
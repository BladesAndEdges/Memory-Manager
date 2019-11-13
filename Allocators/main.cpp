/*
	Main.cpp is used as a testing file that carries out tests for specific conditions 
	under which the code may break, or throw exceptions. 

	Error checking has been done for the separate allocators, Custom Smart Pointer and the Memory Manager. 
*/

#include <iostream>

#include "StackAllocator.h" 
#include "DoubleEndedStackAllocator.h" 
#include "PoolAllocator.h"
#include "MemoryManager.h"
#include "CustomSmartPointer.h"

template<typename T>
void print(CustomSmartPointer<T> a)
{
	std::cout << *a << std::endl;
}


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

	/*--------------------------------------------------------------------------------------*/
	

	/*
	1.  Tests the allocation function. Testing to see if the stack would throw an error if we allocate
		    more elements than we are allowed.	

			I suggst the seperate code blocks are run seperately, as you can therefore test to see
			that the individual stacks perform as expected, as well.
	*/

	///*Both stacks used*/
	//doubleStack.allocateOnTheBottomStack(1);
	//doubleStack.allocateOnTheBottomStack(2);
	//doubleStack.allocateOnTheBottomStack(3);
	//doubleStack.allocateOnTheTopStack(1);
	//doubleStack.allocateOnTheTopStack(2);
	//doubleStack.allocateOnTheBottomStack(4); // If you try to allocate on the Top stack, it would also throw and error

	///*Only bottom stack*/
	//doubleStack.allocateOnTheBottomStack(1);
	//doubleStack.allocateOnTheBottomStack(2);
	//doubleStack.allocateOnTheBottomStack(3);
	//doubleStack.allocateOnTheBottomStack(4);
	//doubleStack.allocateOnTheBottomStack(5);
	//doubleStack.allocateOnTheBottomStack(6);

	///*Only top stack*/
	//doubleStack.allocateOnTheTopStack(1);
	//doubleStack.allocateOnTheTopStack(2);
	//doubleStack.allocateOnTheTopStack(3);
	//doubleStack.allocateOnTheTopStack(4);
	//doubleStack.allocateOnTheTopStack(5);
	//doubleStack.allocateOnTheTopStack(6);
	
/*---------------------------------------------------------------------------------------*/



///*--------------------------------------------------------------------------------------*/
//

///*
//	2.  Tests that a stack that has no element yet produces true for isEmpty() and false otherwise
//		Should throw an assertion error.
//*/
//
//	std::cout << std::boolalpha << doubleStack.isEmpty() << std::endl; // confirm stack is empty
//	doubleStack.allocateOnTheBottomStack(1);
//
//	doubleStack.allocateOnTheTopStack(2);
//	std::cout << std::boolalpha << doubleStack.isEmpty() << std::endl;
//
//	doubleStack.deallocateFromTheBottomStack();
//	doubleStack.deallocateFromTheTopStack();
//
//	std::cout << std::boolalpha << doubleStack.isEmpty() << std::endl;
//
//
/////*---------------------------------------------------------------------------------------*/



///*--------------------------------------------------------------------------------------*/
///*
//	3.  Tests if deallocating an element from an empty stack, triggers an assertion error.
//*/
//
//	std::cout << std::boolalpha << stack.isEmpty() << std::endl; // confirm stack is empty
//	//doubleStack.deallocateFromTheBottomStack();
//	//doubleStack.deallocateFromTheTopStack();
//
///*---------------------------------------------------------------------------------------*/



///*--------------------------------------------------------------------------------------*/
//
//
///*
//	4.  Tests if we can initialize a stack with both pod types and non-pod types.
//*/
//	Vector v(1.0f, 1.0f);
//	TestClass a(0, 1);
//
//	DoubleEndedStackAllocator<float> fStack(5);
//
//	DoubleEndedStackAllocator<std::string> strStack(5);
//	strStack.allocateOnTheBottomStack("Daniel");
//
//	DoubleEndedStackAllocator<const char*> chptrStack(5);
//	chptrStack.allocateOnTheTopStack("charPointer");
//
//
//	DoubleEndedStackAllocator<Vector> vecStack(5);
//	vecStack.allocateOnTheBottomStack(v);
//
//	DoubleEndedStackAllocator<TestClass> testStack(5);
//	testStack.allocateOnTheTopStack(a);
//
///*---------------------------------------------------------------------------------------*/



///*--------------------------------------------------------------------------------------*/
//
//	/*5.  Tests the sizeOfStack function.*/
//
//	std::cout << "Stack Is Empty? " << std::boolalpha << doubleStack.isEmpty() << std::endl;
//	std::cout << "SizeOfStack: " << doubleStack.sizeOfDoubleStack() << std::endl;
//
//	stack.pushElementOnStack(1);
//
//	std::cout << "Stack Is Empty? " << std::boolalpha << doubleStack.isEmpty() << std::endl;
//	std::cout << "SizeOfStack: " << doubleStack.sizeOfDoubleStack() << std::endl;
//
//	stack.popElementFromStack(); 
//
//	std::cout << "Stack Is Empty? " << std::boolalpha << doubleStack.isEmpty() << std::endl;
//	std::cout << "SizeOfStack: " << doubleStack.sizeOfDoubleStack() << std::endl;
//
///*---------------------------------------------------------------------------------------*/




/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/

	/* TESTING FOR POOL ALLOCATOR*/
	PoolAllocator<int> pool(5);


	///*--------------------------------------------------------------------------------------*/
	///*
	//	1. Tests allocation beyond the maximum elements specified in the constructor.
	//		Should throw an assertion error.
	//*/

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

	///*---------------------------------------------------------------------------------------*/



	///*--------------------------------------------------------------------------------------*/
	///*
	//	2. Testing for deallocation. A simple explanation as testing would not be possible

	//	The way I have strucutred the program, I am guarranteed that a request for deallocation
	//	when all blocks are unused would not do anything. I have to pass a pointer to an element, 
	//	to the stack. The only way to retrieve such a pointer is to get it returned by a corresponding
	//	allocate function. So a call to deallocate may be made with a non-valid address, but it would
	//	neither harm nor really do anything.

	//	I wanted to the allcator to treat it as the way memory would, once memory is allocated, the value at
	//	that address would not change up until something changes it. Otherwise it remains the same until
	//	modified.

	//	It would, however, trigger an assertion error, if you try to deallocate the same element twice.
	//*/

	//int* a = pool.allocateElementInPool(1);
	//pool.deallocateElementInPool(a);
	//pool.deallocateElementInPool(a);

	///*---------------------------------------------------------------------------------------*/



/*--------------------------------------------------------------------------------------*/


////
///*
//	4.  Tests if we can initialize a pool with both pod types and non-pod types.
//*/
//	Vector v(1.0f, 1.0f);
//	TestClass a(0, 1);
//
//	PoolAllocator<float> fStack(5);
//	fStack.allocateElementInPool(0.0f);
//
//	PoolAllocator<std::string> strStack(5);
//	strStack.allocateElementInPool("Daniel");
//
//	PoolAllocator<const char*> chptrStack(5);
//	chptrStack.allocateElementInPool("charPointer");
//
//
//	PoolAllocator<Vector> vecStack(5);
//	vecStack.allocateElementInPool(v);
//
//	PoolAllocator<TestClass> testStack(5);
//	testStack.allocateElementInPool(a);
//
///*---------------------------------------------------------------------------------------*/



///*--------------------------------------------------------------------------------------*/
//
//	/*5.  Tests the sizeOfStack function.*/
//
//	std::cout << "Pool Is Empty? " << std::boolalpha << pool.isEmpty() << std::endl;
//	std::cout << "SizeOfPool: " << pool.sizeOfPool() << std::endl;
//
//	int* a = pool.allocateElementInPool(1);
//	int* b = pool.allocateElementInPool(2);
//
//	std::cout << "Pool Is Empty? " << std::boolalpha << pool.isEmpty() << std::endl;
//	std::cout << "SizeOfPool: " << pool.sizeOfPool() << std::endl;
//
//	pool.deallocateElementInPool(a);
//	pool.deallocateElementInPool(b);
//
//	std::cout << "Pool Is Empty? " << std::boolalpha << pool.isEmpty() << std::endl;
//	std::cout << "SizeOfPool: " << pool.sizeOfPool() << std::endl;
//
///*---------------------------------------------------------------------------------------*/




///*--------------------------------------------------------------------------------------*/
//
//	/*6. Testing that the allocation does happen onto the pool, i.e. it is the same lement we allocated*/
//
//int* a = pool.allocateElementInPool(1);
//
//std::cout << *a << std::endl;
//std::cout << a << std::endl;
//
////It would allocate it at the very first block
//std::cout << pool.m_blocks[0] << std::endl;
//std::cout << pool.m_blocks << std::endl;
//
//
///*---------------------------------------------------------------------------------------*/




/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/

MemoryManager<int> iMM(AllocationStrategy::STACK, 3);
MemoryManager<Vector> vecMM(AllocationStrategy::DOUBLESTACK, 3);
MemoryManager<TestClass> testMM(AllocationStrategy::POOL, 3);

//// The memory manager is simply a wrapper. The functions it encapsualtes were tested above, and proven to work.//
//// The below code is simply a demonstration, per se, of how it should be used //
/*--------------------------------------------------------------------------------------------------------*/
////1. Testing that we can properly initialize the memory manager.
//
//iMM.allocateElement(1);
//iMM.allocateElement(2);
//iMM.allocateElement(3);
//
//Vector v1(0.0f, 1.0f);
//Vector v2(1.0f, 2.0f);
//Vector v3(2.0f, 3.0f);
//
//vecMM.allocateElement(v1, DoubleStack::BOTTOM);
//vecMM.allocateElement(v2, DoubleStack::TOP);
//vecMM.allocateElement(v3, DoubleStack::TOP);
//
//TestClass t1;
//TestClass t2(1, 1);
//TestClass t3(2, 2);
//
//TestClass* first = testMM.allocateElement(t1);
//TestClass* second = testMM.allocateElement(t2);
//TestClass* third = testMM.allocateElement(t3);
//
//std::cout << first->a << " " << first->b << std::endl;
//std::cout << second->a << " " << second->b << std::endl;
//std::cout << third->a << " " << third->b << std::endl;
/*------------------------------------------------------------------------------------------------*/



/*--------------------------------------------------------------------------------------------------------*/
//2. Demonstrating the allocation function throws an assertion error as it should. Uncomment a code block to test
//		on all of the structures the manager provides. Make sure to comment out the previously tested section.

//iMM.allocateElement(1);
//iMM.allocateElement(2);
//iMM.allocateElement(3);
//iMM.allocateElement(4);

//Vector v1(0.0f, 1.0f);
//Vector v2(1.0f, 2.0f);
//Vector v3(2.0f, 3.0f);
//Vector v4(5.0f, 3.0f);
//
//vecMM.allocateElement(v1, DoubleStack::BOTTOM);
//vecMM.allocateElement(v2, DoubleStack::TOP);
//vecMM.allocateElement(v3, DoubleStack::TOP);
//vecMM.allocateElement(v4, DoubleStack::TOP);

//TestClass t1;
//TestClass t2(0, 1);
//TestClass t3(0, 1);
//TestClass t4(1, 1);

//testMM.allocateElement(t1);
//testMM.allocateElement(t2);
//testMM.allocateElement(t3);
//testMM.allocateElement(t4);
/*------------------------------------------------------------------------------------------------*/



/*------------------------------------------------------------------------------------------------*/
//3. Testing if the memory manager would underflow. All of them should throw an assertion error.

//iMM.deallocateElement();

//vecMM.deallocateElement(DoubleStack::BOTTOM);

//vecMM.deallocateElement(DoubleStack::TOP);

//TestClass* test = new TestClass(2,2);
//testMM.deallocateElement(test);

/*------------------------------------------------------------------------------------------------*/



/*------------------------------------------------------------------------------------------------*/
//4. Checking to see if it detects it as active.

//iMM.deallocateElement();

//vecMM.deallocateElement(DoubleStack::BOTTOM);

//vecMM.deallocateElement(DoubleStack::TOP);

//TestClass* test = new TestClass(2,2);
//testMM.deallocateElement(test);

/*------------------------------------------------------------------------------------------------*/



/*------------------------------------------------------------------------------------------------*/
////5. Testing we can use the value from the memory manager when the pool is selected.
//
//TestClass t1(0, 1);
//
//TestClass* testPtr = testMM.allocateElement(t1);
//
//std::cout << testPtr << std::endl;
//std::cout << testPtr->a << " " << testPtr->b << std::endl;

/*------------------------------------------------------------------------------------------------*/



/*------------------------------------------------------------------------------------------------*/
////6. Checking if the memory manager is still active. 

//std::cout << std::boolalpha << iMM.checkIfActive() << std::endl; // false
//iMM.allocateElement(0);
//std::cout << std::boolalpha << iMM.checkIfActive() << std::endl; // true
//
//Vector v(0.0f, 1.0f);
//
//std::cout << std::boolalpha << vecMM.checkIfActive() << std::endl; // false
//vecMM.allocateElement(v, DoubleStack::BOTTOM);
//std::cout << std::boolalpha << vecMM.checkIfActive() << std::endl; // true
//
//std::cout << std::boolalpha << vecMM.checkIfActive() << std::endl; // true
//vecMM.allocateElement(v, DoubleStack::TOP);
//
//vecMM.deallocateElement(DoubleStack::BOTTOM);
//vecMM.deallocateElement(DoubleStack::TOP);
//std::cout << std::boolalpha << vecMM.checkIfActive() << std::endl; //false
//
//TestClass t(0, 0);
//
//std::cout << std::boolalpha << testMM.checkIfActive() << std::endl; // false
//testMM.allocateElement(t);
//std::cout << std::boolalpha << testMM.checkIfActive() << std::endl; //true

/*--------------------------------------------------------------------------------------------*/
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/



/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/


/*1. Testing the creation and access of teh pointers. Destructors called as well.
	Access, creation, destruction
*/
//{
//	CustomSmartPointer<int> iPtr(new int(10)); // Constructor called
//	CustomSmartPointer<float> fPtr(new float(10.0f)); // Constructor called 
//	CustomSmartPointer<std::string> strPtr(new std::string("Daniel")); // Constructor called
//	CustomSmartPointer<Vector> vecPtr(new Vector(0, 1)); // Constructor called
//	CustomSmartPointer<TestClass> testPtr(new TestClass(1, 0)); // Constructor called
//
//	print(iPtr); // Prints 10, calls copy constructor, then calls it's destructor
//
//
//	std::cout << *iPtr << std::endl;
//	std::cout << *fPtr << std::endl;
//	std::cout << vecPtr->x << std::endl;
//	std::cout << testPtr->a << " " << testPtr->b << std::endl;
//
//} // Five destructors prints, each with a corresponding deleted memory

/*****************************************************************************************************/



/*****************************************************************************************************/
///*2. Testing managed reference counting*/
//{
//	CustomSmartPointer<int> p(new int(10)); //Constructor called
//
//	std::cout << p.m_internalPointer << std::endl; // print the adress of the internal pointer
//	std::cout << *p << std::endl; // Print 10
//
//	{
//		CustomSmartPointer<int> ref1 = p; // Copy constructor called
//		CustomSmartPointer<int> ref2 = p; // Copy constructor called
//
//
//		/*Both should print the same address as that of p*/
//		std::cout << ref1.m_internalPointer << std::endl;
//		std::cout << ref2.m_internalPointer << std::endl;
//
//		/*Both should print 10*/
//		std::cout << *ref1 << std::endl;
//		std::cout << *ref2 << std::endl;
//
//	} // Two destructors of the copies called 
//
//} // Destructor of p called, and memory deleted

/*****************************************************************************************************/



/*****************************************************************************************************/
/*3. Testing that it works for the memory manager as well.*/


/*------------------------With a Stack--------------------------------------------------------------*/
//CustomSmartPointer<MemoryManager<int>> mmPtr(new MemoryManager<int>(AllocationStrategy::STACK, 3));
//std::cout << std::boolalpha << mmPtr->checkIfActive() << std::endl;
//mmPtr->allocateElement(0);
//mmPtr->allocateElement(2);
//mmPtr->allocateElement(3);
//mmPtr->deallocateElement();
//mmPtr->deallocateElement();
//std::cout << std::boolalpha << mmPtr->checkIfActive() << std::endl;

/*-----------------------------------------------------------------------------------------------------*/



/*--------------------------------With a DoubleStack----------------------------------------------------*/

//Vector vec(0.0f, 1.0f);
//
//
//CustomSmartPointer<MemoryManager<Vector>> vecPtr(new MemoryManager<Vector>(AllocationStrategy::DOUBLESTACK, 3));
//std::cout << std::boolalpha << vecPtr->checkIfActive() << std::endl;
//std::cout << std::boolalpha << vecPtr->m_doubleEndedStackAllocator->isEmpty() << std::endl;
//vecPtr->allocateElement(vec, DoubleStack::BOTTOM);
//vecPtr->allocateElement(vec, DoubleStack::BOTTOM);
//vecPtr->allocateElement(vec, DoubleStack::TOP);
//
//std::cout << std::boolalpha << vecPtr->checkIfActive() << std::endl;
//
//vecPtr->deallocateElement(DoubleStack::BOTTOM);
//vecPtr->deallocateElement(DoubleStack::BOTTOM);
//vecPtr->deallocateElement(DoubleStack::TOP);
//
//std::cout << std::boolalpha << vecPtr->checkIfActive() << std::endl;

/*-----------------------------------------------------------------------------------------------------*/



/*---------------------------------With a poll allocator-----------------------------------------------*/

//TestClass one(0, 1);
//TestClass two(1, 2);
//TestClass three(3, 4);
//TestClass four(5, 6);
//
//
//CustomSmartPointer<MemoryManager<TestClass>> testPtr(new MemoryManager<TestClass>(AllocationStrategy::POOL, 3));
//
//std::cout << std::boolalpha << testPtr->checkIfActive() << std::endl;
//CustomSmartPointer<TestClass> t1 = testPtr->allocateElement(one);
//std::cout << t1->a << std::endl;
//std::cout << t1->b << std::endl;
//CustomSmartPointer<TestClass> t2 = testPtr->allocateElement(two);
//std::cout << t2->a << std::endl;
//std::cout << t2->b << std::endl;
//CustomSmartPointer<TestClass> t3 = testPtr->allocateElement(three);
//std::cout << t3->a << std::endl;
//std::cout << t3->b << std::endl;
//
//std::cout << std::boolalpha << testPtr->checkIfActive() << std::endl;

/*-----------------------------------------------------------------------------------------------------*/

std::cin.get();

}
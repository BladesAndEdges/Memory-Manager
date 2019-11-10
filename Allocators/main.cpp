#include <iostream>

#include "StackAllocator.h"
#include "DoubleEndedStackAllocator.h"
#include "PoolAllocator.h"
#include "CustomSmartPointer.h"

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
int main()
{


	std::cout << "Before" << std::endl;

	{
		CustomSmartPointer<Test> t = CustomSmartPointer<Test>(new Test(1, 2));
		CustomSmartPointer<Test> cone = t;
		CustomSmartPointer<Test> ctwo = t;
	}

	std::cout << "After" << std::endl;

	//std::cout << *t << std::endl;

	std::cin.get();

}
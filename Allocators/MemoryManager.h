#pragma once

class MemoryManager
{

public:


	MemoryManager();

	void allocate();
	void deallocate();

	bool checkIfActive();

	~MemoryManager();
};


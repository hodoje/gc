#pragma once

// Represents one element of either occupied or free memory block
typedef struct Memory_heap_block {
	void* dataPtr;
	int dataSize;
	bool mark;
} MEMORY_BLOCK;

// Represents one element of list of free and occupied nodes
typedef struct Node
{
	MEMORY_BLOCK blockData;
	struct Node* next;
} NODE;
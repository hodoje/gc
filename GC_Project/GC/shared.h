#include <Windows.h>
#include <stdlib.h>

#ifndef SHARED_H
#define SHARED_H

// Declarations that resolve undefined declaration errors
struct Heap_manager;
struct Roots_heap_elem;

// Represents one element of the roots heap
typedef struct Roots_heap_elem {
	void* dataPtr;
	int dataSize;
	bool mark;
} ROOT;

// Heap manager
void* Malloc(int nbytes);
void HeapInit(struct Heap_manager** hManager);
void AddRoot(struct Heap_manager** hManager, ROOT** newRoot);
struct Heap_manager* HeapManagerInit();

typedef struct Heap_manager {
	ROOT* rootHeapStart;
	int rootHeapSize;
	void*(*malloc)(int);
	void(*addRoot)(struct Heap_manager**, ROOT**);
} H_MANAGER;

#endif


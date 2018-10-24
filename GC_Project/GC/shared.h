#pragma once
#include <Windows.h>
#include "structs.h"
#include "list.h"
#include "hashset.h"

#ifndef SHARED_H
#define SHARED_H

// Declarations that resolve undefined declaration errors
struct Heap_manager;

// Heap manager
void* Malloc(struct Heap_manager** hManager, int nbytes);
void Free(struct Heap_manager** hManager, void** ptr);
void HeapInit(struct Heap_manager** hManager);
struct Heap_manager* HeapManagerInit();

typedef struct Heap_manager {
	char* heapStart;
	int heapSize;
	NODE* listOfFree;
	HASHSET* hashTableOfOccupied;
	void(*free)(struct Heap_manager**, void**);
	void*(*malloc)(struct Heap_manager**, int);
	HANDLE mallocSemaphore;
} H_MANAGER;

#endif

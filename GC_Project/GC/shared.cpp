#include "shared.h"

#define INITIAL_HEAP_SIZE 2048 * 10
#define INITIAL_HASHTABLE_SIZE INITIAL_HEAP_SIZE / 8

H_MANAGER* HeapManagerInit()
{
	H_MANAGER* hM = (H_MANAGER*)malloc(sizeof(H_MANAGER));
	HeapInit(&hM);
	hM->listOfFree = (NODE*)malloc(sizeof(Node));
	hM->mallocSemaphore = CreateSemaphore(NULL, 1, 1, NULL);

	MEMORY_BLOCK* initialMemoryBlock = (MEMORY_BLOCK*)malloc(sizeof(MEMORY_BLOCK));
	initialMemoryBlock->dataPtr = hM->heapStart;
	initialMemoryBlock->dataSize = hM->heapSize;
	initialMemoryBlock->mark = false;

	hM->listOfFree->blockInfo = *initialMemoryBlock;
	hM->listOfFree->next = NULL;
	hM->hashTableOfOccupied = HashsetInit(INITIAL_HASHTABLE_SIZE);
	hM->malloc = Malloc;
	hM->free = Free;

	return hM;
}

void HeapInit(struct Heap_manager** hManager)
{
	H_MANAGER* hM = *hManager;
	hM->heapStart = (char*)malloc(INITIAL_HEAP_SIZE);
	hM->heapSize = INITIAL_HEAP_SIZE;
}

// Malloc should allocate memory on our custom heap
void* Malloc(struct Heap_manager** hManager, int nbytes)
{
	H_MANAGER* hM = *hManager;
	// Define new memory block data
	MEMORY_BLOCK* mB = (MEMORY_BLOCK*)malloc(sizeof(MEMORY_BLOCK));
	mB->dataPtr = NULL;
	mB->dataSize = nbytes;
	mB->mark = false;

	// Lock while searching a block position and addition to hashset
	WaitForSingleObject(hM->mallocSemaphore, INFINITE);

	// Recalculate new position for free block and its size 
	NODE* firstFittingNode = hM->listOfFree;
	if (ListCount(&hM->listOfFree) == 1)
	{
		mB->dataPtr = firstFittingNode->blockInfo.dataPtr;
		firstFittingNode->blockInfo.dataPtr = (char*)(firstFittingNode->blockInfo.dataPtr) + nbytes;
		firstFittingNode->blockInfo.dataSize = firstFittingNode->blockInfo.dataSize - nbytes;
	}
	else
	{
		// Find the first fit
		while (nbytes > firstFittingNode->blockInfo.dataSize)
		{
			if (firstFittingNode->next == NULL)
			{
				//collect
				// after collect, start again
				// if it fails again, heap is full
			}
			firstFittingNode = firstFittingNode->next;
		}
		mB->dataPtr = firstFittingNode->blockInfo.dataPtr;
		firstFittingNode->blockInfo.dataPtr = (char*)(firstFittingNode->blockInfo.dataPtr) + nbytes;
		firstFittingNode->blockInfo.dataSize = firstFittingNode->blockInfo.dataSize - nbytes;
		if (firstFittingNode->blockInfo.dataSize == 0)
		{
			hM->listOfFree = firstFittingNode->next;
			free(firstFittingNode);
		}
	}

	// Add new node in list of occupied nodes
	// mB argument will be a copy of mB
	HashsetAdd(&hM->hashTableOfOccupied, mB);

	// Free the semaphore so other threads can malloc
	ReleaseSemaphore(hM->mallocSemaphore, 1, NULL);

	return mB->dataPtr;
}

void Free(struct Heap_manager** hManager, void** ptr)
{
	H_MANAGER* hM = *hManager;

	NODE* nodeToFree = HashsetRemove(&hM->hashTableOfOccupied, *ptr);

	// Search where to put the block back
	// Try to find the between
	NODE* freeNodeIterator = hM->listOfFree;
	NODE* previousNode = NULL;
	while (freeNodeIterator->blockInfo.dataPtr < nodeToFree->blockInfo.dataPtr)
	{
		previousNode = freeNodeIterator;
		freeNodeIterator = freeNodeIterator->next;
	}

	// If there is only one block currently free and it's not at the beginning of heap
	// just connect the blocks
	if (previousNode == NULL)
	{
		previousNode = nodeToFree;
		previousNode->next = freeNodeIterator;
		hM->listOfFree = previousNode;

		// Check if nodeToFree and its next node are next to each other
		if ((char*)nodeToFree->blockInfo.dataPtr + nodeToFree->blockInfo.dataSize == freeNodeIterator->blockInfo.dataPtr)
		{
			freeNodeIterator->blockInfo.dataPtr = nodeToFree->blockInfo.dataPtr;
			freeNodeIterator->blockInfo.dataSize = freeNodeIterator->blockInfo.dataSize + nodeToFree->blockInfo.dataSize;
			hM->listOfFree = freeNodeIterator;
			nodeToFree->next = NULL;
			free(nodeToFree);
		}
	}
	else
	{
		previousNode->next = nodeToFree;
		nodeToFree->next = freeNodeIterator;

		// Check if previous and nodeToFree are next to each other
		if ((char*)previousNode->blockInfo.dataPtr + previousNode->blockInfo.dataSize == nodeToFree->blockInfo.dataPtr)
		{
			// If they are increase the size of previous and free nodeToFree
			previousNode->blockInfo.dataSize = previousNode->blockInfo.dataSize + nodeToFree->blockInfo.dataSize;
			nodeToFree->next = NULL;
			free(nodeToFree);
		}
		else if ((char*)nodeToFree->blockInfo.dataPtr + nodeToFree->blockInfo.dataSize == freeNodeIterator->blockInfo.dataPtr)
		{
			// if not, check if nodeToFree and current node are next to each other
			freeNodeIterator->blockInfo.dataPtr = nodeToFree->blockInfo.dataPtr;
			freeNodeIterator->blockInfo.dataSize = freeNodeIterator->blockInfo.dataSize + nodeToFree->blockInfo.dataSize;
			hM->listOfFree = freeNodeIterator;
			nodeToFree->next = NULL;
			free(nodeToFree);
		}
	}
}
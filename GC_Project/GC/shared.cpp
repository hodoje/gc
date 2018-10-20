#include "shared.h"

#define INITIAL_HEAP_SIZE 2048

H_MANAGER* HeapManagerInit()
{
	H_MANAGER* hM = (H_MANAGER*)malloc(sizeof(H_MANAGER));
	HeapInit(&hM);
	hM->listOfFree = (NODE*)malloc(sizeof(Node));

	MEMORY_BLOCK* initialMemoryBlock = (MEMORY_BLOCK*)malloc(sizeof(MEMORY_BLOCK));
	initialMemoryBlock->dataPtr = hM->heapStart;
	initialMemoryBlock->dataSize = hM->heapSize;
	initialMemoryBlock->mark = false;

	hM->listOfFree->blockData = *initialMemoryBlock;
	hM->listOfFree->next = NULL;
	hM->listOfOccupied = NULL;
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
	mB->dataPtr = hM->listOfFree->blockData.dataPtr;
	mB->dataSize = nbytes;
	mB->mark = false;

	// Add new node in list of occupied nodes
	Add(&(hM->listOfOccupied), &mB);	

	// Recalculate new position for free block and its size 
	hM->listOfFree->blockData.dataPtr = (char*)(hM->listOfFree->blockData.dataPtr) + nbytes;
	hM->listOfFree->blockData.dataSize = hM->listOfFree->blockData.dataSize - nbytes;

	return mB->dataPtr;
}

void Free(struct Heap_manager** hManager, void* ptr)
{
	H_MANAGER* hM = *hManager;
	
	NODE* nodeToFree = Remove(&hM->listOfOccupied, ptr);

	// Search where to put the block back
	// Try to find the between
	NODE* LastFreeNodeIterator = hM->listOfFree;
	NODE* previousNode = NULL;
	while(LastFreeNodeIterator->blockData.dataPtr < nodeToFree->blockData.dataPtr)
	{
		previousNode = LastFreeNodeIterator;
		LastFreeNodeIterator = LastFreeNodeIterator->next;
	}

	// If there is only one block currently free and it's not at the beginning of heap
	// just connect the blocks
	if(previousNode == NULL)
	{
		previousNode = nodeToFree;
		previousNode->next = LastFreeNodeIterator;
		hM->listOfFree = previousNode;
		return;
	}

	// Check if previous and nodeToFree are next to each other
	if((char*)previousNode->blockData.dataPtr + previousNode->blockData.dataSize == nodeToFree->blockData.dataPtr)
	{
		// If they are increase the size of previous and free nodeToFree
		previousNode->blockData.dataSize = previousNode->blockData.dataSize + nodeToFree->blockData.dataSize;
		free(nodeToFree);
	}
	// if not, check if nodeToFree and current node are next to each other
	else if((char*)nodeToFree->blockData.dataPtr + nodeToFree->blockData.dataSize == LastFreeNodeIterator->blockData.dataPtr)
	{
		LastFreeNodeIterator->blockData.dataPtr = nodeToFree->blockData.dataPtr;
		LastFreeNodeIterator->blockData.dataSize = LastFreeNodeIterator->blockData.dataSize + nodeToFree->blockData.dataSize;
		free(nodeToFree);
	}
	else
	{
		// Else put nodeToFree between previous and its next which is the currentLastFreeNode
		nodeToFree->next = LastFreeNodeIterator;
		previousNode->next = nodeToFree;
	}
}
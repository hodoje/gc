#include "collector.h"
#include "shared.h"

#define PRAGMA_PACK_FOUR 4
#define POINTER_SIZE 4

void MarkChildren(H_MANAGER** hManager, char* pseudoRoot, int size)
{
	// If size is less than POINTER_SIZE that means a pointer is certainly not stored on that location
	if (size < POINTER_SIZE)
	{
		return;
	}

	H_MANAGER* hM = *hManager;
	HASHSET_ENTRY* hashsetEntry;
	int iterations = size / PRAGMA_PACK_FOUR;

	for (int i = 0; i < iterations; i++)
	{
		// Cast to int* to point to 4 bytes, then dereference it to take the int value and cast it to a pointer
		char* child = (char*)(*((int*)pseudoRoot + i));

		// Check if child is in occupied
		if ((hashsetEntry = HashsetGetElement(&hM->hashTableOfOccupied, child)) != NULL)
		{
			// If yes, mark it and go to his children
			hashsetEntry->blockInfo.mark = true;
			MarkChildren(&hM, (char*)hashsetEntry->blockInfo.dataPtr, hashsetEntry->blockInfo.dataSize);
		}
	}
}

void Mark(H_MANAGER** hManager, struct Collector** collector)
{
	H_MANAGER* hM = *hManager;
	COLLECTOR* col = *collector;
	char* heapStartAddress = hM->heapStart;
	char* heapEndAddress = heapStartAddress + hM->heapSize;

	char* currentPointer = NULL;

	// Simulation of rootset
	for (int i = 0; i < 4; i++)
	{
		// Mark the root		
		currentPointer = col->rootSet[i];
		HASHSET_ENTRY* occupiedHashEntry = HashsetGetElement(&hM->hashTableOfOccupied, currentPointer);
		occupiedHashEntry->blockInfo.mark = true;

		// Check his children and mark if necessary
		MarkChildren(&hM, (char*)occupiedHashEntry->blockInfo.dataPtr, occupiedHashEntry->blockInfo.dataSize);
	}
}

void Sweep(H_MANAGER** hManager)
{
	H_MANAGER* hM = *hManager;
	HASHSET* htoc = hM->hashTableOfOccupied;
	HASHSET_ENTRY* entryToSweepOrUnmark = NULL;
	int htocSize = htoc->size;

	// Iterate over all hashset indexes
	for (int index = 0; index < htocSize; index++)
	{
		// Get the entry if not NULL on that index
		if ((entryToSweepOrUnmark = htoc->buckets[index]) != NULL)
		{
			// If next is not NULL there are more elements on that index that we have to care for
			if (entryToSweepOrUnmark->next != NULL)
			{
				while (entryToSweepOrUnmark != NULL)
				{
					// Save the reference to next because after removing and freeing we won't have the stored information
					HASHSET_ENTRY* next = entryToSweepOrUnmark->next;

					if (entryToSweepOrUnmark->blockInfo.mark == true)
					{
						entryToSweepOrUnmark->blockInfo.mark = false;
					}
					else
					{
						NODE* nodeToFree = HashsetRemove(&htoc, entryToSweepOrUnmark->key);
						hM->free(&hM, &nodeToFree->blockInfo.dataPtr);
					}
					entryToSweepOrUnmark = next;
				}
			}
			// If next is NULL, there are no more elements on that index so we can sweep or unmark with ease
			else
			{
				if (entryToSweepOrUnmark->blockInfo.mark == true)
				{
					entryToSweepOrUnmark->blockInfo.mark = false;
				}
				else
				{
					hM->free(&hM, &entryToSweepOrUnmark->blockInfo.dataPtr);
				}
			}
		}
	}
}

void MarkAndSweep(H_MANAGER** hManager, struct Collector** collector)
{
	H_MANAGER* hM = *hManager;
	COLLECTOR* col = *collector;
	Mark(&hM, &col);
	Sweep(&hM);
}


//struct s1 {
//	int a;
//};
//
//struct s2 {
//	int a;
//	s1* ptr;
//};
//
//struct s3 {
//	s1* ptr1;
//	s2* ptr2;
//};
//
//void GetRootCollection(struct Collector** collector)
//{
//	// SIMULATION
//	H_MANAGER* hManager = HeapManagerInit();
//	int* numArr = (int*)Malloc(&hManager, sizeof(int) * 5);
//	char* str = (char*)Malloc(&hManager, 5);
//	s3* arr = (s3*)Malloc(&hManager, sizeof(s3));
//	arr->ptr1 = (s1*)Malloc(&hManager, sizeof(s1));
//	arr->ptr2 = (s2*)Malloc(&hManager, sizeof(s2));
//	arr->ptr2->ptr = (s1*)Malloc(&hManager, sizeof(s1));
//
//	// Ova provera ide ovde
//	/*if (currentPointer > heapStartAddress && currentPointer < heapEndAddress)
//	{
//
//	}*/
//
//	char* roots[3];
//	roots[0] = (char*)numArr;
//	roots[1] = (char*)str;
//	roots[2] = (char*)arr;
//}

COLLECTOR* CollectorInit()
{
	COLLECTOR* collector = (COLLECTOR*)malloc(sizeof(COLLECTOR));
	/*collector->rootSet = (char*)GetRootCollection;*/
	collector->rootSet[4];
	collector->MarkAndSweep = MarkAndSweep;
	return collector;
}

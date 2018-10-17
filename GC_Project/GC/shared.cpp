#include "shared.h"

H_MANAGER* HeapManagerInit()
{
	H_MANAGER* hM = (H_MANAGER*)malloc(sizeof(H_MANAGER));
	HeapInit(&hM);
	hM->malloc = Malloc;
	hM->addRoot = AddRoot;
	return hM;
}

void HeapInit(struct Heap_manager** hManager)
{
	H_MANAGER* hM = *hManager;
	hM->rootHeapStart = (ROOT*)calloc(1, 100 * sizeof(ROOT));
	hM->rootHeapSize = 100;
}

void* Malloc(int nbytes)
{
	return malloc(nbytes);
}

void AddRoot(struct Heap_manager** hManager, ROOT** newRoot)
{
	H_MANAGER* hM = *hManager;
	ROOT* firstEmpty = hM->rootHeapStart;
	while (firstEmpty->dataPtr != NULL)
	{
		firstEmpty = firstEmpty + 1;
	}
	*firstEmpty = **newRoot;
}
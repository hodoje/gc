#include "collector.h"
#include "shared.h"

void Mark(H_MANAGER** hManager, COLLECTOR** collector)
{
	H_MANAGER* hM = *hManager;
	COLLECTOR* col = *collector;
	char* heapStartAddress = hM->heapStart;
	char* heapEndAddress = heapStartAddress + hM->heapSize;

	for(int i = 0; i < 2; i++)
	{
		NODE* currentNode = hM->listOfOccupied;
		while (currentNode != NULL)
		{
			if
			(
				(char*)currentNode->blockData.dataPtr == col->activePtrs[i] &&
				(currentNode->blockData.dataPtr >= heapStartAddress && currentNode->blockData.dataPtr <= heapEndAddress)
			)
			{
				currentNode->blockData.mark = true;
			}
			currentNode = currentNode->next;
		}
	}
	
}

void Sweep(H_MANAGER** hManager)
{
	H_MANAGER* hM = *hManager;
	NODE* currentNode = NULL;
	NODE* nextOccupied = hM->listOfOccupied;
	while(nextOccupied != NULL)
	{
		currentNode = nextOccupied;
		if(currentNode->blockData.mark == true)
		{
			currentNode->blockData.mark = false;
			nextOccupied = nextOccupied->next;
		}
		else
		{
			// Setting next first because of lost reference if done after free
			nextOccupied = nextOccupied->next;
			hM->free(&hM, currentNode->blockData.dataPtr);
		}
	}
}

void MarkAndSweep(H_MANAGER** hManager, COLLECTOR** collector)
{
	H_MANAGER* hM = *hManager;
	COLLECTOR* col = *collector;
	Mark(&hM, &col);
	Sweep(&hM);
}

COLLECTOR* CollectorInit()
{
	COLLECTOR* collector = (COLLECTOR*)malloc(sizeof(COLLECTOR));
	collector->activePtrs;
	collector->MarkAndSweep = MarkAndSweep;
	return collector;
}
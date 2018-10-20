#include <stdio.h>
#include "shared.h"
#include "allocator.h"
#include "collector.h"

int main()
{
	// Initial HEAP MANAGER testing
	H_MANAGER* hManager = HeapManagerInit();
	int* numArr = (int*)Malloc(&hManager, sizeof(int) * 5);
	int* numArr1 = (int*)Malloc(&hManager, sizeof(int) * 6);
	char* str = (char*)Malloc(&hManager, 5);
	Collector* collector = CollectorInit();
	collector->activePtrs[0] = (char*)numArr;
	collector->activePtrs[1] = str;
	collector->MarkAndSweep(&hManager, &collector);
	NODE* n = hManager->listOfOccupied;
	while(n != NULL)
	{
		if(n->blockData.dataPtr == numArr)
		{
			printf("numArr OC - True\n");
			break;
		}
		n = n->next;
	}

	n = hManager->listOfOccupied;
	while (n != NULL)
	{
		if (n->blockData.dataPtr == numArr1)
		{
			printf("numArr OC - True\n");
			break;
		}
		n = n->next;
	}

	n = hManager->listOfOccupied;
	while (n != NULL)
	{
		if (n->blockData.dataPtr == str)
		{
			printf("str - OC - True\n");
			break;
		}
		n = n->next;
	}

	n = hManager->listOfFree;
	while (n != NULL)
	{
		if (n->blockData.dataPtr == numArr)
		{
			printf("numArr - FR - True\n");
			break;
		}
		n = n->next;
	}

	n = hManager->listOfFree;
	while (n != NULL)
	{
		if (n->blockData.dataPtr == numArr1)
		{
			printf("numArr1 - FR - True\n");
			break;
		}
		n = n->next;
	}

	n = hManager->listOfFree;
	while (n != NULL)
	{
		if (n->blockData.dataPtr == str)
		{
			printf("str - FR - True\n");
			break;
		}
		n = n->next;
	}


	/*for (int i = 0; i < 5; i++)
	{
		numArr[i] = i;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d", numArr[i]);
	}

	for (int i = 0; i < 6; i++)
	{
		numArr1[i] = i + 5;
	}

	for (int i = 0; i < 6; i++)
	{
		printf("%d", numArr1[i]);
	}

	char* strr = "abc\0";
	memcpy(str, strr, 4);
	printf("%s", str);
*/
	getchar();

	return 0;
}

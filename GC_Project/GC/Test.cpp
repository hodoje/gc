#include "shared.h"
#include "allocator.h"
#include <stdio.h>

int main()
{
	// Initial HEAP MANAGER testing
	H_MANAGER* hManager = HeapManagerInit();
	int* numArr = (int*)Malloc(&hManager, sizeof(int) * 5);
	for (int i = 0; i < 5; i++)
	{
		numArr[i] = i;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d", numArr[i]);
	}

	int* numArr1 = (int*)Malloc(&hManager, sizeof(int) * 5);
	for (int i = 0; i < 5; i++)
	{
		numArr1[i] = i + 5;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d", numArr1[i]);
	}

	getchar();

	return 0;
}
#include "list.h"

void Add(NODE** root, MEMORY_BLOCK** data)
{
	NODE* newElemPtr = (NODE*)malloc(sizeof(NODE));
	newElemPtr->blockData = **data;
	newElemPtr->next = NULL;

	// Empty list
	if(*root == NULL)
	{
		*root = newElemPtr;
		return;
	}

	// Non-empty list
	// You wonder why this assignment is done here?
	// If this was done before the check above currentElemPtr and *root would point to NULL
	// And if we, after that, used currentElemPtr in the rest of code, only the memory that it points to would be changed
	// and not the memory where *root points to because NULL is not a valid location to be pointed at
	NODE* currentElemPtr = *root;

	while(currentElemPtr->next != NULL)
	{
		currentElemPtr = currentElemPtr->next;
	}
	currentElemPtr->next = newElemPtr;
}

void Insert(NODE** root, int index, MEMORY_BLOCK** data)
{
	NODE* newElem = (NODE*)malloc(sizeof(NODE));
	newElem->blockData = **data;
	newElem->next = NULL;

	if (Count(&(*root)) <= index)
	{
		return;
	}

	NODE* currentElemPtr = *root;
	NODE* previousElemPtr = NULL;
	int idx = 0;
	while(currentElemPtr != NULL)
	{
		if(idx == index)
		{
			newElem->next = currentElemPtr;
			previousElemPtr->next = newElem;
			return;
		}
		previousElemPtr = currentElemPtr;
		currentElemPtr = currentElemPtr->next;
		idx++;
	}
}

MEMORY_BLOCK* ElementAt(NODE** root, int index)
{
	// Empty list
	if(*root == NULL)
	{
		// Was not defined what to return in case of empty list
		return NULL;
	}

	NODE* currentElemPtr = *root;

	int elemCnt = 0;
	while(currentElemPtr != NULL)
	{
		if(elemCnt == index)
		{
			return &currentElemPtr->blockData;
		}
		currentElemPtr = currentElemPtr->next;
		elemCnt++;
	}

	// If the index is not valid
	return NULL;
}

NODE* RemoveAt(NODE** root, int index)
{
	if(*root == NULL)
	{
		return *root;
	}

	if(Count(root) <= index)
	{
		return NULL;
	}

	NODE* currentElemPtr = *root;
	NODE* previousElemPtr = NULL;
	int idx = 0;
	while(currentElemPtr != NULL)
	{
		if(idx == index)
		{
			NODE* next = currentElemPtr->next;
			//free(currentElemPtr);
			previousElemPtr->next = next;
			//return;
			return currentElemPtr;
		}
		previousElemPtr = currentElemPtr;
		currentElemPtr = currentElemPtr->next;
		idx++;
	}
	return NULL;
}

NODE* Remove(NODE** root, void* ptr)
{
	if (*root == NULL)
	{
		return *root;
	}

	NODE* nodeToRemove = *root;

	if(Count(root) == 1)
	{
		*root = NULL;
		return nodeToRemove;
	}

	// If it's the first node and has no previous nodes
	if(nodeToRemove->blockData.dataPtr == ptr)
	{
		NODE* next = nodeToRemove->next;
		*root = next;
		return nodeToRemove;
	}

	NODE* previousElemPtr = NULL;
	while(nodeToRemove->blockData.dataPtr != ptr)
	{
		previousElemPtr = nodeToRemove;
		nodeToRemove = nodeToRemove->next;
	}
	NODE* next = nodeToRemove->next;
	previousElemPtr->next = next;
	return nodeToRemove;
}

void Clear(NODE** root)
{
	if(*root == NULL)
	{
		return;
	}

	NODE* restOfList = *root;
	while(*root != NULL)
	{
		restOfList = restOfList->next;
		free(*root);
		*root = restOfList;
	}
}

int Count(NODE** root)
{
	if(*root == NULL)
	{
		return 0;
	}

	NODE* currentElemPtr = *root;
	int elemCnt = 0;

	while(currentElemPtr != NULL)
	{
		currentElemPtr = currentElemPtr->next;
		elemCnt++;
	}

	return elemCnt;
}

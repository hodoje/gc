#include "hashmap.h"

HASHMAP* HashmapInit(unsigned int size)
{
	HASHMAP* hashmap = NULL;

	if (size < 1)
	{
		return NULL;
	}

	if ((hashmap = (HASHMAP*)malloc(sizeof(HASHMAP))) == NULL)
	{
		return NULL;
	}
		
	if ((hashmap->buckets = (HASHMAP_ENTRY**)malloc(size * sizeof(HASHMAP_ENTRY*))) == NULL)
	{
		return NULL;
	}
		
	for (int i = 0; i < size; i++)
	{
		hashmap->buckets[i] = NULL;
	}

	hashmap->size = size;

	return hashmap;
}

int HashmapGetIndex(HASHMAP** set, void* key)
{
	int hash = HashmapGetHash(key);

	return (hash % (*set)->size);
}

int HashmapGetHash(void* key)
{
	int hash;

	hash = (int)key / 4;

	return hash;
}

HASHMAP_ENTRY* HashmapCreateEntry(HEAP_BLOCK* newBlock)
{
	HASHMAP_ENTRY* newentry;
	void *key = newBlock->dataPtr;

	if (key == NULL)
	{
		return NULL;
	}

	if ((newentry = (HASHMAP_ENTRY*)malloc(sizeof(HASHMAP_ENTRY))) == NULL)
	{
		return NULL;
	}

	newentry->key = newBlock->dataPtr;
	newentry->blockInfo = newBlock;
	newentry->next = NULL;

	return newentry;
}

void HashmapAdd(HASHMAP** set, HEAP_BLOCK* entry)
{
	int index = 0;
	HASHMAP_ENTRY* newentry = NULL;
	HASHMAP_ENTRY* next = NULL;
	// Last is the last previous element of an entry to be inserted
	HASHMAP_ENTRY* last = NULL;
	void* key = entry->dataPtr;

	index = HashmapGetIndex(set, key);

	// Next is the first entry on particular index
	next = (*set)->buckets[index];

	// Checks if there is already an entry on particular index
	// Iterate to the end of the list until next is NULL
	while (next != NULL && next->key != NULL && (key != next->key))
	{
		last = next;
		next = next->next;
	}
	// After this loop, next is NULL
	// New entry has to be assigned to next

	// Creates new entry based on new memory block
	newentry = HashmapCreateEntry(entry);

	// Case if bucket is empty
	if (next == (*set)->buckets[index])
	{
		(*set)->buckets[index] = newentry;
		newentry->next = NULL;
	}
	// Case if bucket is not empty
	else if (next == NULL)
	{
		last->next = newentry;
	}
	// Place in the middle of the list
	else
	{
		newentry->next = next;
		last->next = newentry;
	}
}

NODE* HashmapRemove(HASHMAP** set, void* key)
{
	int index = 0;
	HASHMAP_ENTRY* elementToRemove = NULL;
	HASHMAP_ENTRY* previous = NULL;

	index = HashmapGetIndex(set, key);

	// Getting the first element of the list
	elementToRemove = (*set)->buckets[index];

	while (elementToRemove != NULL && elementToRemove->key != NULL && (key != elementToRemove->key))
	{
		previous = elementToRemove;
		elementToRemove = elementToRemove->next;
	}
	// After this loop we have the elementToRemove

	if (previous == NULL)
	{
		// Either elementToRemove's next or NULL will be at this index
		(*set)->buckets[index] = elementToRemove->next;
	}
	else
	{
		// Tie up previous and elementToRemove's next
		previous->next = elementToRemove->next;
	}

	// Reference to a node to be added to the H_MANAGER free list
	NODE* nodeForFreeList = (NODE*)malloc(sizeof(NODE));
	nodeForFreeList->blockInfo = *elementToRemove->blockInfo;
	nodeForFreeList->next = NULL;

	return nodeForFreeList;
}

HASHMAP_ENTRY* HashmapGetElement(HASHMAP** set, void* key)
{
	int index = HashmapGetIndex(set, key);
	HASHMAP_ENTRY* entryToReturn = NULL;
	entryToReturn = (*set)->buckets[index];
	if (entryToReturn == NULL)
	{
		return NULL;
	}
	else
	{
		while (entryToReturn != NULL && entryToReturn != NULL && entryToReturn->key != key)
		{
			entryToReturn = entryToReturn->next;
		}
		
		if (entryToReturn == NULL || entryToReturn->key == NULL || entryToReturn->key != key)
		{
			return NULL;
		}
		else
		{
			return entryToReturn;
		}
	}
}

// This function is not needed
void* HashmapLookup(HASHMAP** set, void* key)
{
	int index = 0;
	HASHMAP_ENTRY* entry;

	index = HashmapGetIndex(set, key);

	entry = (*set)->buckets[index];

	while (entry != NULL && entry->key != NULL && entry->key != key)
	{
		entry = entry->next;
	}

	if (entry == NULL || entry->key == NULL || entry->key != key)
		return NULL;
	else
		return &entry->blockInfo;
}
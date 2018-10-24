#include "hashset.h"

HASHSET* HashsetInit(unsigned int size)
{
	HASHSET* hashset = NULL;

	if (size < 1)
		return NULL;

	if ((hashset = (HASHSET*)malloc(sizeof(HASHSET))) == NULL)
		return NULL;

	if ((hashset->buckets = (HASHSET_ENTRY**)malloc(sizeof(HASHSET_ENTRY*)*size)) == NULL)
		return NULL;

	for (int i = 0; i < size; i++)
	{
		hashset->buckets[i] = NULL;
	}

	hashset->size = size;

	return hashset;
}

int HashsetGetIndex(HASHSET** set, void* key)
{
	int hash = HashsetGetHash(key);

	return (hash % (*set)->size);
}

int HashsetGetHash(void* key)
{
	int hash;

	hash = (int)key / 4;

	return hash;
}

HASHSET_ENTRY* HashsetCreateEntry(MEMORY_BLOCK* entry)
{
	HASHSET_ENTRY* newentry;
	void *key = entry->dataPtr;

	if (key == NULL)
		return NULL;

	if ((newentry = (HASHSET_ENTRY*)malloc(sizeof(HASHSET_ENTRY))) == NULL)
		return NULL;

	newentry->key = entry->dataPtr;
	newentry->blockInfo = *entry;
	newentry->next = NULL;

	return newentry;
}

void HashsetAdd(HASHSET** set, MEMORY_BLOCK* entry)
{
	int index = 0;
	HASHSET_ENTRY* newentry = NULL;
	HASHSET_ENTRY* next = NULL;
	// Last is the last previous element of an entry to be inserted
	HASHSET_ENTRY* last = NULL;
	void* key = entry->dataPtr;

	index = HashsetGetIndex(set, key);

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
	newentry = HashsetCreateEntry(entry);

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

NODE* HashsetRemove(HASHSET** set, void* key)
{
	int index = 0;
	HASHSET_ENTRY* elementToRemove = NULL;
	HASHSET_ENTRY* previous = NULL;

	index = HashsetGetIndex(set, key);

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
	nodeForFreeList->blockInfo = elementToRemove->blockInfo;
	nodeForFreeList->next = NULL;

	return nodeForFreeList;
}

HASHSET_ENTRY* HashsetGetElement(HASHSET** set, void* key)
{
	int index = HashsetGetIndex(set, key);
	HASHSET_ENTRY* entryToReturn = NULL;
	entryToReturn = (*set)->buckets[index];
	if (entryToReturn == NULL)
	{
		return NULL;
	}
	else
	{
		while (entryToReturn->key != key)
		{
			entryToReturn = entryToReturn->next;
		}
		return entryToReturn;
	}
}

void* HashsetLookup(HASHSET** set, void* key)
{
	int index = 0;
	HASHSET_ENTRY* entry;

	index = HashsetGetIndex(set, key);

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
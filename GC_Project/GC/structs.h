#pragma once

// Represents one element of either occupied or free memory block
typedef struct Memory_heap_block {
	void* dataPtr;
	int dataSize;
	bool mark;
} MEMORY_BLOCK;

// Represents one element of list of free and occupied nodes
typedef struct Node
{
	MEMORY_BLOCK blockInfo;
	struct Node* next;
} NODE;

// Represents one element of hashset (hashset)
typedef struct Hashset_entry
{
	void* key;
	MEMORY_BLOCK blockInfo;
	struct Hashset_entry* next;
} HASHSET_ENTRY;

// Represents a hashset (hashset)
typedef struct Hashset
{
	unsigned int size;
	struct Hashset_entry** buckets;
	/*unsigned int nentries;
	float loadFactor;*/
} HASHSET;
#pragma once

// Represents one element of either occupied or free heap block
typedef struct Heap_block {
	void* dataPtr;
	int dataSize;
	bool mark;
} HEAP_BLOCK;

// Represents one element of list of free and occupied nodes
typedef struct Node
{
	HEAP_BLOCK blockInfo;
	struct Node* next;
} NODE;

// Represents one element of a hashmap
typedef struct Hashmap_entry
{
	void* key;
	HEAP_BLOCK* blockInfo;
	struct Hashmap_entry* next;
} HASHMAP_ENTRY;

// Represents a hashmap
typedef struct Hashmap
{
	unsigned int size;
	struct Hashmap_entry** buckets;
	/*unsigned int nentries;
	float loadFactor;*/
} HASHMAP;

// Represents and item in Collectors thread collection
typedef struct Thread_collection_item
{
	void* tHandle;
	char* firstThreadStackAddress;
	int threadStackSize;
} THREAD_COLLECTION_ITEM;

// Represents a structure that will be used for CreateThreadWrapper function
// Needs a reference to the Collector
// The rest is the user routine and parameters
typedef struct Thread_function_wrapper_parameters
{
	void* userRoutine;
	void* routineParameters;
} THREAD_FUNCTION_WRAPPER_PARAMETERS;

// This structure is needed because of the partion of "adding new thread handles and getting the thread stack" mechanics
// Follow the code
typedef struct Thread_function_wrapper_parameters_internal_wrapper
{
	struct Collector* collector;
	int currentThreadCollectionItemIndex;
	THREAD_FUNCTION_WRAPPER_PARAMETERS tfwp;
} TFWP_INTERNAL_WRAPPER;
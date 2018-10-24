#pragma once
#include "structs.h"
#include "windows.h"

#ifndef HASHSET_H
#define HASHSET_H

HASHSET* HashsetInit(unsigned int size);
int HashsetGetIndex(HASHSET** hashset, void* key);
int HashsetGetHash(void* key);
HASHSET_ENTRY* HashsetGetElement(HASHSET** hashset, void* key);
HASHSET_ENTRY* HashsetCreateEntry(MEMORY_BLOCK* entry);
void HashsetAdd(HASHSET** hashset, MEMORY_BLOCK* entry);
NODE* HashsetRemove(HASHSET** hashset, void* key);
void* HashsetLookup(HASHSET** hashset, void* key);

#endif // !HASHSET_H
#pragma once
#include "structs.h"
#include "windows.h"

#ifndef HASHMAP_H
#define HASHMAP_H

HASHMAP* HashmapInit(unsigned int size);
int HashmapGetIndex(HASHMAP** hashmap, void* key);
int HashmapGetHash(void* key);
HASHMAP_ENTRY* HashmapGetElement(HASHMAP** hashmap, void* key);
HASHMAP_ENTRY* HashmapCreateEntry(HEAP_BLOCK* entry);
void HashmapAdd(HASHMAP** hashmap, HEAP_BLOCK* entry);
NODE* HashmapRemove(HASHMAP** hashmap, void* key);
void* HashmapLookup(HASHMAP** hashmap, void* key);

#endif // !HASHMAP_H
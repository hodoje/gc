#include <stdlib.h>
#include <Windows.h>
#include "structs.h"

#ifndef LIST_H
#define LIST_H

void Add(NODE** root, MEMORY_BLOCK** element);
void Insert(NODE** root, int index, MEMORY_BLOCK** element);
MEMORY_BLOCK* ElementAt(NODE** root, int index);
NODE* Remove(NODE** root, void* ptr);
NODE* RemoveAt(NODE** root, int index);
int Count(NODE** root);
void Clear(NODE** root);

#endif
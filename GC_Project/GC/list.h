#pragma once
#include <stdlib.h>
#include <Windows.h>
#include "structs.h"

#ifndef LIST_H
#define LIST_H

void ListAdd(NODE** root, MEMORY_BLOCK** element);
void ListInsert(NODE** root, int index, MEMORY_BLOCK** element);
MEMORY_BLOCK* ListElementAt(NODE** root, int index);
NODE* ListRemove(NODE** root, void* ptr);
NODE* ListRemoveAt(NODE** root, int index);
int ListCount(NODE** root);
void ListClear(NODE** root);

#endif
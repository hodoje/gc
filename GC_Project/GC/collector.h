#pragma once
#include "shared.h"

#ifndef COLLECTOR_H
#define COLLECTOR_H

struct Collector;

void GetRootCollection(struct Collector** collector);
void Mark(H_MANAGER** hManager, struct Collector** collector);
void MarkChildren(H_MANAGER** hManager, char* pseudoRoot, int size);
void Sweep(H_MANAGER** hManager);
void MarkAndSweep(H_MANAGER** hManager, struct Collector** collector);
HANDLE CreateThreadWrapper(
	struct Collector** collector,
	LPSECURITY_ATTRIBUTES   lpThreadAttributes,
	SIZE_T                  dwStackSize,
	LPTHREAD_START_ROUTINE  lpStartAddress,
	__drv_aliasesMem LPVOID lpParameter,
	DWORD                   dwCreationFlags,
	LPDWORD                 lpThreadId
);
struct Collector* CollectorInit();

typedef struct Collector {
	char* rootSet[4];
	HANDLE threadArr[10];
	int threadArrIdx;
	void(*MarkAndSweep)(H_MANAGER** hManager, struct Collector**);
} COLLECTOR;

#endif
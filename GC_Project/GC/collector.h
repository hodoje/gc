#pragma once
#include "shared.h"

#ifndef COLLECTOR_H
#define COLLECTOR_H

struct Collector;

bool CloseThreadHandleWrapper(struct Collector** collector, HANDLE tHandle);
void ScaleThreadCollection(struct Collector** collector);
void SuspendAllCurrentProcessThreads(struct Collector** collector);
void ResumeAllCurrentProcessThreads(struct Collector** collector);
DWORD WINAPI ThreadFunctionWrapper(__drv_aliasesMem LPVOID lpParameters);
HANDLE CreateThreadWrapper(struct Collector**				  collector,
								  THREAD_FUNCTION_WRAPPER_PARAMETERS threadFunctionWrapperParameters,
								  LPSECURITY_ATTRIBUTES	          lpThreadAttributes,
								  SIZE_T							  dwStackSize,
								  DWORD							  dwCreationFlags,
								  LPDWORD							  lpThreadId);
THREAD_COLLECTION_ITEM* FindThreadCollectionItem(struct Collector** collector, HANDLE tHandle, int* outIndex);
bool CloseThreadHandleWrapper(struct Collector** collector, HANDLE tHandle);
void ScaleThreadCollection(struct Collector** collector); // NOT IMPLEMENTED

void GetRootCollection(struct Collector** collector, struct Heap_manager** hManager);  // NOT IMPLEMENTED
void MarkChildren(H_MANAGER** hManager, char* pseudoRoot, int size);
void Mark(H_MANAGER** hManager, struct Collector** collector);
void Sweep(H_MANAGER** hManager);
void MarkAndSweep(H_MANAGER** hManager, struct Collector** collector);

struct Collector* CollectorInit();

typedef struct Collector {
	char* rootSet[4];
	THREAD_COLLECTION_ITEM* threadArr;
	int threadArrFirstFreeIdx;
	int threadArrSize;;
	void(*MarkAndSweep)(H_MANAGER** hManager, struct Collector**);
} COLLECTOR;

#endif
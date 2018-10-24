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
struct Collector* CollectorInit();

typedef struct Collector {
	char* rootSet[4];
	void(*MarkAndSweep)(H_MANAGER** hManager, struct Collector**);
} COLLECTOR;

#endif
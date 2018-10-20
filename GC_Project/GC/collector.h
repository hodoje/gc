#pragma once
#include "shared.h"

#ifndef COLLECTOR_H
#define COLLECTOR_H

struct Collector;

void Mark(H_MANAGER** hManager, struct Collector** collector);
void Sweep(H_MANAGER** hManager);
void MarkAndSweep(H_MANAGER** hManager, struct Collector** collector);
struct Collector* CollectorInit();

typedef struct Collector {
	char* activePtrs[2];
	void(*MarkAndSweep)(H_MANAGER** hManager, struct Collector**);
} COLLECTOR;

#endif
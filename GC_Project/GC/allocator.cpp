//#include "allocator.h"
//
//void* Malloc(H_MANAGER** hManager, int nbytes)
//{
//	H_MANAGER* hM = *hManager;
//	ROOT* newRoot = (ROOT*)malloc(sizeof(ROOT));
//	newRoot->dataPtr = malloc(nbytes);
//	newRoot->dataSize = nbytes;
//	newRoot->mark = false;
//	hM->addRoot(&hM, &newRoot);
//	return newRoot->dataPtr;
//}
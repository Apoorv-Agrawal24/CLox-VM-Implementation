#ifndef VM_H
#define VM_H

#include "chunk.h"

typedef struct {
	Chunk* chunk;
} VM;

void initVM(VM* vm);
void freeVM(VM* vm);

#endif
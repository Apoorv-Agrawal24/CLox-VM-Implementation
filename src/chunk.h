#ifndef CHUNK_H
#define CHUNK_H

#include "common.h"
#include "value.h"
#include "line.h"

typedef enum {
	// OpCode, operand
	OP_CONSTANT, 
	// OpCode, operand1, operand2, operand3, operand4
	OP_CONSTANT_LONG,
	OP_RETURN,
} OpCode;

typedef struct {
	int count;
	int capacity;
	uint8_t* code;
	ValueArray constants;
	LineArray lines;
} Chunk;

void initChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
void freeChunk(Chunk* chunk);
int addConstant(Chunk* chunk, Value value);

void writeConstant(Chunk* chunk, Value value, int line);

#endif
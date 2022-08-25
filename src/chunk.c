#include "chunk.h"
#include "memory.h"
#include "value.h"

void initChunk(Chunk* chunk) {
	chunk->count = 0;
	chunk->capacity = 0;
	chunk->code = NULL;
	initValueArray(&chunk->constants);
	initLineArray(&chunk->lines);
}

void writeChunk(Chunk* chunk, uint8_t byte, int line) {
	if (chunk->capacity < chunk->count + 1) {
		int oldCapacity = chunk->capacity;
		chunk->capacity = GROW_CAPACITY(oldCapacity);
		chunk->code = GROW_ARRAY(uint8_t, chunk->code, 
			oldCapacity, chunk->capacity);
	}

	chunk->code[chunk->count] = byte;
	chunk->count++;

	writeLineArray(&chunk->lines, line);
}

void freeChunk(Chunk* chunk) {
	FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
	freeValueArray(&chunk->constants);
	freeLineArray(&chunk->lines);
	initChunk(chunk);
}

int addConstant(Chunk* chunk, Value value) {
	writeValueArray(&chunk->constants, value);
	return chunk->constants.count - 1;
}

void writeConstant(Chunk* chunk, Value value, int line) {
	int constant = addConstant(chunk, value);
	if (constant >= 256) {
		writeChunk(chunk, OP_CONSTANT_LONG, line);
		uint8_t split[4];
		uint32_t num = constant;
		uint32ToUint8(num, split);

		writeChunk(chunk, split[0], line);
		writeChunk(chunk, split[1], line);
		writeChunk(chunk, split[2], line);
		writeChunk(chunk, split[3], line);
		return;
	}
	writeChunk(chunk, OP_CONSTANT, line);
	writeChunk(chunk, constant, line);
}
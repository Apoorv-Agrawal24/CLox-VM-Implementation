#ifndef VALUE_H
#define VALUE_H

#include "common.h"
#include "stdint.h"

typedef double Value;

typedef struct {
	int capacity;
	int count;
	Value* values;
} ValueArray;

void initValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);
void freeValueArray(ValueArray* array);
void printValue(Value value);

// Big Endian
void uint32ToUint8(uint32_t uint32Num, uint8_t* uint8Array);
uint32_t uint8ToUint32(uint8_t* uint8Array);

#endif
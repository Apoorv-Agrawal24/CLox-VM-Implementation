#include <stdio.h>

#include "value.h"
#include "memory.h"

void initValueArray(ValueArray* array) {
	array->values = NULL;
	array->capacity = 0;
	array->count = 0;
}

void writeValueArray(ValueArray* array, Value value) {
	if (array->capacity < array->count + 1) {
		int oldCapacity = array->capacity;
		array->capacity = GROW_CAPACITY(oldCapacity);
		array->values = GROW_ARRAY(Value, array->values,
			oldCapacity, array->capacity);
	}
	array->values[array->count] = value;
	array->count++;
}

void freeValueArray(ValueArray* array) {
	FREE_ARRAY(Value, array->values, array->capacity);
	initValueArray(array);
}

void printValue(Value value) {
	printf("%g", value);
}

void uint32ToUint8(uint32_t uint32Num, uint8_t* uint8Array) {
	// https://stackoverflow.com/questions/6499183/converting-a-uint32-value-into-a-uint8-array4 (Big Endian)


	uint8Array[0] = uint32Num >> 24;
	uint8Array[1] = uint32Num >> 16;
	uint8Array[2] = uint32Num >> 8;
	uint8Array[3] = uint32Num;
}

uint32_t uint8ToUint32(uint8_t* uint8Array) {
	uint32_t converted;

	converted = (uint8Array[0] << 24) | (uint8Array[1] << 16) | (uint8Array[2] << 8) | uint8Array[3];
	return converted;
}
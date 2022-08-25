#include <stdio.h>

#include "line.h"
#include "memory.h"

void initLineArray(LineArray* array) {
	array->lines = NULL;
	array->capacity = 0;
	array->count = 0;
}

void writeLineArray(LineArray* array, int line) {
	if (array->lines != NULL) {
		if (array->lines[array->count - 1] == line) {
			array->lines[array->count - 2] += 1;
			return;
		}
	}	
	if (array->capacity < array->count + 1) {
		int oldCapacity = array->capacity;
		array->capacity = GROW_CAPACITY(oldCapacity);
		array->lines = GROW_ARRAY(int, array->lines,
			oldCapacity, array->capacity);
	}
	array->lines[array->count] = 1;
	array->lines[array->count + 1] = line;
	array->count += 2;
}

void freeLineArray(LineArray* array) {
	FREE_ARRAY(int, array->lines, array->capacity);
	initLineArray(array);
}

int getLine(LineArray* array, int index) {
	int* expanded = NULL;
	int expandedCapacity = 0;
	int expandedCount = 0;

	int pos = 1;

	while (pos < array->count) {
		//printf("%d\n", array->lines[pos]);

		for (int i = 0; i < array->lines[pos - 1]; i++) {
			if (expandedCapacity < expandedCount + 1) {
				int oldCapacity = array->capacity;
				expandedCapacity = GROW_CAPACITY(oldCapacity);
				expanded = GROW_ARRAY(int, expanded, oldCapacity, expandedCapacity);
			}

			expanded[expandedCount] = array->lines[pos];
			expandedCount++;
		}

		pos += 2;
	}
	/*
	pos = 0;
	while (pos < expandedCount) {
		printf("%d\n", expanded[pos]);
		pos++;
	}*/

	return expanded[index];
}
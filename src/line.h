#ifndef LINE_H
#define LINE_H

#include "common.h"

typedef struct {
	int capacity;
	int count;

	// [frequency, val, frequency, val]
	// [2, 3, 4, 5] = 335555
	int* lines;
} LineArray;

void initLineArray(LineArray* array);
void writeLineArray(LineArray* array, int line);
void freeLineArray(LineArray* array);
int getLine(LineArray* array, int index);

#endif
#include "common.h"
#include "chunk.h"
#include "vm.h"

int main(int argc, const char* argv[]) {
	Chunk chunk;
	VM vm;

	initChunk(&chunk);
	initVM(&vm);

	writeConstant(&chunk, 500, 1);
	writeConstant(&chunk, 20, 2);
	writeChunk(&chunk, OP_RETURN, 3);
	disassembleChunk(&chunk, "test_chunk");

	freeVM(&vm);
	freeChunk(&chunk);

	return 0;
}
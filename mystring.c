#include <stdio.h>
#include "mystring.h"

void* mem_copy(void* end, const void* begin, size_t length) {
	const char* begin_pointer = (const char*) begin;
	char* end_pointer = (char*) end;
	for (size_t i = 0; i < length; ++i) {
		*(end_pointer++) = *(begin_pointer++);
	}
	return end;
}

int length_string(const char* str) {
	char element = str[0];
	int length = 0;
	while (element != 0) {
		length++;
		element = str[length];
	}
	return length;
}


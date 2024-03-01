#include <stdio.h>
#include <stdlib.h>
#include "myreadline.h"
#include "mystring.h"

char* readline() {
	char buffer[81] = {0};
	char *my_string = NULL;
	int length = 0;
	int element = 0;
	do {
		element = scanf("%80[^\n]", buffer);
		if (element < 0 || element == EOF) {
			if (!my_string) {
				return 0;
			} else if (element == EOF) {
				return 0;
			}
		} else if (element > 0 && element != EOF) {
			int chunk_len= length_string(buffer);
			int str_len = length + chunk_len;
			my_string = realloc(my_string, str_len + 1);
			mem_copy(my_string + length, buffer, chunk_len);
			length = str_len;
			my_string[str_len] = '\0';
		} else {
			scanf("%*1[\n]");
		}
	} while (element > 0);
	if (length > 0) {
		my_string[length] = '\0';
		return my_string;
	} else {
		my_string = calloc(1, sizeof(char));
		return 0;
	}
}

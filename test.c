#include <stdio.h>
#include <stdlib.h>

#define consonants "BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxz"

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

void cut(char *string, int index) {
	for (int i = index; i < length_string(string); i++) {
		string[i] = string[i + 1];
	}
	string[length_string(string) + 1] = '\0';
}

void delete_spaces(char *string) {
	for (int i = 1; i < length_string(string); i++) {
		if (string[i] == ' ') {
			if (string[i - 1] == ' ') {
				cut(string, i);
				i--;
			} else if (string[0] == ' ') {
				cut(string, 0);
				i--;
			}
		}
	}
	if (string[length_string(string) - 1] == ' ') {
		cut(string, length_string(string) - 1);
	}
}

int consonants_checker(const char *string, char element) {
	for (int i = 0; i < length_string(string); i++) {
		if (string[i] == element) {
			return 1;
		}
	}
	return 0;
}

void changed_string(char *string) {
	for (int i = 0; i < length_string(string); i++) {
		if (consonants_checker(consonants, string[i])) {
			cut(string, i);
			i--;
		}
	}
	if (string[length_string(string) - 1] == ' ') {
		cut(string, length_string(string) - 1);
	}
}

int main() {
	char *stroka;
	while (1) {
		printf("Input Your String:\n");
		stroka = readline();
		printf("\n");
		if (!stroka) {
			printf("End Of Program.\n");
			break;
		}
		delete_spaces(stroka);
		printf("Your String: \"%s\"\n", stroka);
		changed_string(stroka);
		printf("Needed String: \"%s\"\n", stroka);
		free(stroka);
	}
	return 0;
}

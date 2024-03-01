#include <stdio.h>
#include "taskfunctions.h"
#include <string.h>

#define consonants "BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxz"

void cut(char *string, int index) {
	for (int i = index; i < strlen(string); i++) {
		string[i] = string[i + 1];
	}
	string[strlen(string) + 1] = '\0';
}

void delete_spaces(char *string) {
	for (int i = 1; i < strlen(string); i++) {
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
	if (string[strlen(string) - 1] == ' ') {
		cut(string, strlen(string) - 1);
	}
}

int consonants_checker(const char *string, char element) {
	for (int i = 0; i < strlen(string); i++) {
		if (string[i] == element) {
			return 1;
		}
	}
	return 0;
}

void changed_string(char *string) {
	for (int i = 0; i < strlen(string); i++) {
		if (consonants_checker(consonants, string[i])) {
			cut(string, i);
			i--;
		}
	}
}

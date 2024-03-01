#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "myreadline.h"
#include "mystring.h"
#include "taskfunctions.h"

int main() {
	double time_spent = 0.0;
	clock_t begin = clock();
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
		delete_spaces(stroka);
		printf("Needed String: \"%s\"\n", stroka);
		free(stroka);
		printf("\n");
		clock_t end = clock();
		time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
		printf("The Elapsed Time Is %f Seconds.\n", time_spent);
		printf("\n");
	}
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define MAX 128

struct _polinom;
typedef struct _polinom* position;

typedef struct _polinom {
	int coef;
	int exp;
	position next;
}polinom;

int readFile(char* fileName, position p);


int main() {

	polinom head = {
		.coef = 0;
		.exp = 0;
		.next = NULL;
	}
  
  return 0;
}

int readFile(char* fileName, position p) {
	FILE* fp = NULL;
	int co = 0, ex = 0, n = 0;
	char buffer[MAX] = { 0 };
	char line[MAX] = { 0 };
	char* p = NULL;
	fp = fopen(fileName, "r");

	if (fp == NULL) {
		printf("Unable to open file\n");
		return -1;
	}

		/*should the max be at most the size of the array or ...*/
		fgets(buffer, MAX, fp);
		p = buffer;
		while (strlen(p) > 0) {
			sscanf(p, "%d %d %n", &co, &ex, &n);
			p += n;
		}
	
		/*should the max be at most the size of the array or ...*/
		fgets(buffer, MAX, fp);
		p = buffer;
		while (strlen(p) > 0) {
			sscanf(p, "%d %d %n", &co, &ex, &n);
			p += n;
		}


	return 0;
}

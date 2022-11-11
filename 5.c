#include <stdio.h>
#include <stdlib.h>
#include <string>
#define MAX 1024

struct _stack;
typedef struct _stack* position;

typedef struct _stack {
	int el;
	position next;
}stack;


int Push(position p);  // prima zadnji el
int Pop(position p);  // prima prvi 

int main() {
	stack head = { .el = 0, .next = NULL };
	position last = &head;
	char fileName[MAX] = { 0 };
	FILE* fp = NULL;
	char line[MAX] = { 0 };
	int broj = 0;
	int n = 0;

	printf("File name: ");
	scanf(" %s", fileName);

	fp = fopen(fileName, "r");

	if (fp == NULL) {
		printf("Unable to open file\n");
		return -1;
	}
	fscanf(fp, " %s", line);
	while (strlen(line) > 0) {
		if (sscanf(line, " %d %n", &broj, &n) == 1) {
			//push broj
		}
		else {
			// vidi koji je operator: + - * /
			// ako je jedan od ova 4 pop zadnje brojeve 
		}
		line += n;
	}


		fclose(fp);
		return 0;
	}



int Push(position p, position last, int broj)
{
	position el = NULL;
	el = malloc(sizeof(stack));
	if (el == NULL) {
		printf("Unable to allocate memory\n");
		return -1;
	}
	p->next = el->next;
	el->next = NULL;
	el->el = broj;

	last = el;

	return 0;
}

int Pop(position p)
{

	//postavi pokazivace,izbrisat(free)

	return 0;
}

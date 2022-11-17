#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1024

struct _stack;
typedef struct _stack* position;

typedef struct _stack {
	int el;
	position next;
}stack;


int Push(position last, int broj);  // prima zadnji el
int Pop(position p);  // prima prvi 
int StanjeStoga(position p);

int main() {
	stack head = { .el = 0, .next = NULL };
	position last = &head;
	char fileName[MAX] = { 0 };
	FILE* fp = NULL;
	char line[MAX] = { 0 };
	char* pline = NULL;
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
	pline = line;
	while (strlen(pline) > 0) {
		if (sscanf(pline, " %d %n", &broj, &n) == 1) {
			Push(last, broj);
		}
		else {
			// vidi koji je operator: + - * /
			// ako je jedan od ova 4 pop zadnje brojeve 
		}
		pline += n;
	}


		fclose(fp);
		//free all memory allocaated for stack

		return 0;
	}


//p and last are same
int Push(position last, int broj)
{
	position el = NULL, p = last;
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

//isprinta elemente stoga
int StanjeStoga(position p) {
	if (p->next == NULL) {
		printf("Prazni stog");
		return -1;
	}
	while (p->next != NULL) {
		printf("%d\n", p->next->el);
		p = p->next;
	}
	return 0;
}

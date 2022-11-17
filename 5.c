//in and out from beginning
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


int Push(position p, int broj);  // prima zadnji el
int Pop(position p);  // prima prvi 
int StanjeStoga(position p);

int main() {
    stack head = { .el = 0, .next = NULL };
	char fileName[MAX] = { 0 };
	FILE* fp = NULL;
	char line[MAX] = { 0 };
	char* pline = NULL;
	int broj = 0;
	int n = 0;
	position returnPosition = NULL;
	//variables for operatons
	int n1 = 0, n2 = 0;
    //not a number, not an operator (here)
	char op[] = ".";

    printf("File name: ");
	scanf(" %s", fileName);

	fp = fopen(fileName, "r");

	if (fp == NULL) {
		printf("Unable to open file\n");
		return -1;
	}

    fgets(line, MAX, fp);
	//test
	printf("\nlength a: %d\n", (int) strlen(line));
	pline = line;
	while (strlen(pline) > 0) {
		printf("\nlength: %d\n", (int) strlen(pline));
        sscanf(pline, " %d %n", &broj, &n);
		if (n == 1) {
			//test
			printf("broj: %d\n", broj);
			Push(&head, broj);
		} else {
            sscanf(pline, "%c %n", op, &n);
            printf("\nop: %s\n", op);
            if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0 ||
            strcmp(op, "*") == 0 || strcmp(op, "/") == 0 ) {
                n2 = Pop(&head);
                n1 = Pop(&head);
                if (strcmp(op, "+") == 0 ) {
                    Push(&head, n1+n2);
                } else if (strcmp(op, "-") == 0) {
                    Push(&head, n1 - n2);
                } else if (strcmp(op, "*") == 0) {
                    Push(&head, n1 * n2);
                } else if (strcmp(op, "/") == 0) {
                    Push(&head, n1 - n2);
                } 
                
            }
		
	    }
        pline += n;
    }
    StanjeStoga(&head);
    fclose(fp);
    return 0;
}


//&head
int Push(position p, int broj) {
    position el = NULL;
	el = malloc(sizeof(stack));
	if (el == NULL) {
		printf("Unable to allocate memory\n");
		return -1;
	}
    el->next = p->next;
    p->next = el;
    el->el = broj;
    return 0;
}

//&head
int Pop(position p) {
    position temp = NULL;
    int broj = 0;
    if (p->next == NULL) {
        printf("Prazni stog\n");
        return -1;
    }
    temp = p->next;
    p->next = p->next->next;
    broj = temp->el;
    free(temp);

    return broj;
}


//isprinta elemente stoga
int StanjeStoga(position p) {
	if (p->next == NULL) {
		printf("\nPrazni stog\n");
		return -1;
	}
	printf("\n\n");
	
	while (p->next != NULL) {
		printf("%d\t", p->next->el);
		p = p->next;
	}
	puts("");
	return 0;
}

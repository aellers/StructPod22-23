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


int Push(position p, int broj);  
int Pop(position p);  

int main() {
	
	return 0;
}



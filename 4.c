#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 128

struct _polinom;
typedef struct _polinom* position;

typedef struct _polinom {
	int coef;
	int exp;
	position next;
}polinom;

int readFile(char* fileName, position p1, position p2);
position Unos(position p, int co, int ex);
position NadiVeci(position p, int ex);
int IspisPolinoma(position p);


int main() {
	char fileName[MAX] = { 0 };
	polinom head1 = {
		.coef = 0,
		.exp = 0,
		.next = NULL,
	};
  	polinom head2 = {
		.coef = 0,
		.exp = 0,
		.next = NULL,
	};
	polinom headZbroj = {
		.coef = 0,
		.exp = 0,
		.next = NULL,
	};
	polinom headUmnozak = {
		.coef = 0,
		.exp = 0,
		.next = NULL,
	};

	printf("Read from which file: ");
	scanf(" %s", fileName);
	
	readFile(fileName, &head1, &head2);
	IspisPolinoma(&head1);
	printf("\n");
	IspisPolinoma(&head2);
  	return 0;
}

/*assuming that we're reading first two (formated as we like) 
lines from a file*/
int readFile(char* fileName, position p1, position p2) {
	FILE* fp = NULL;
  	position temp = NULL;
	int co = 0, ex = 0, n = 0;
	char buffer[MAX] = { 0 };
	char line[MAX] = { 0 };
	char* p = NULL;

	fp = fopen(fileName, "r");
	if (fp == NULL) {
		printf("Unable to open file\n");
		return -1;
	}

	//polinom 1
	fgets(buffer, MAX, fp);
	p = buffer;
	while (strlen(p) > 0) {
		sscanf(p, "%d %d %n", &co, &ex, &n);
    	temp = Unos(p1, co, ex);
		p += n;
	}
	
	//polinom 2
	fgets(buffer, MAX, fp);
	p = buffer;
	while (strlen(p) > 0) {
		sscanf(p, "%d %d %n", &co, &ex, &n);
    	temp = Unos(p2, co, ex);
		p += n;
	}

	return 0;
}

//&head
position Unos(position p, int co, int ex) {
  	position new = NULL;
	if (co == 0) {
		return NULL;
	}
  	new = (position) malloc(sizeof(polinom));


	if (new == NULL) {
		printf("Unable to allocate memory\n");
    	return NULL;
  	}  

	while ((p->next != NULL) && (ex >= p->next->exp)) {
		p = p->next;
	}

	if (p->exp == ex) {
		p->coef += co;
		free(new);
		return NULL;
	}

	new->next = p->next;
  	p->next = new;

  	new->coef = co;
  	new->exp = ex;
  	return new;
}

//use with p = &head; just for testing if works 
int IspisPolinoma(position p) {
	while (p->next != NULL) {
		//change format to be better later
    	printf("%dx^%d\n", p->next->coef, p->next->exp);
		p = p->next;
	}
	return 0;
}
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
int PomnoziPolinome(position p1, position p2, position rez);
int SortiraniUnos(position novi, position p);
int ZbrojiIsteEksponente(position p);
int ZbrojiPolinome(position p1, position p2, position rez);


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
	printf("\n\n\n");

	PomnoziPolinome(&head1, &head2,&headUmnozak);
	IspisPolinoma(headUmnozak.next);
	ZbrojiIsteEksponente(&headUmnozak);
	printf("\n\n");
	printf("Nakon zbrajanja istih eksp:\n\n\n");
	IspisPolinoma(headUmnozak.next);



	ZbrojiPolinome(&head1, &head2, &headZbroj);
	printf("\n\n\n");
	printf("Zbroj:\n\n");
	IspisPolinoma(headZbroj.next);
	

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
	new = (position)malloc(sizeof(polinom));


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


int PomnoziPolinome(position p1, position p2, position headZbroj)
{
	position novi = NULL;
	position rezHead = NULL;
	position p2start = NULL;

	rezHead = headZbroj;
	p2start = p2;


	if (p1 == NULL || p2 == NULL || headZbroj== NULL) {	
		printf("GREŠKA! Jedan od pokazivaca na polinom je NULL");
		return -1;
	}

	while (p1 != NULL)
	{

		while (p2 != NULL)
		{
			novi = (position)malloc(sizeof(polinom));

			novi->exp = (p1->exp + p2->exp);	
			novi->coef = (p1->coef * p2->coef);

			SortiraniUnos(novi, rezHead);

			p2 = p2->next;
		}

		p1 = p1->next;
		p2 = p2start;
	}

	


	return 0;
}

int SortiraniUnos(position novi, position p)
{
	position head = NULL;
	head = p;

	if (p->next == NULL) {         //prazna
		novi->next = p->next;
		p->next = novi;
	}

	else {
		while (p->next != NULL && p->next->exp < novi->exp) {  //nije kraj i exp sljedeceg veci od novog
			p = p->next;
		}

		novi->next = p->next;		
		p->next = novi;
	}
	p = head;
	return 0;
}


int ZbrojiIsteEksponente(position p)   //headZbroj
{
	position prethodni = NULL;
	position trenutni= NULL;
	position sljedeci = NULL;
	prethodni = p;
	trenutni = p->next;
	sljedeci = trenutni->next;


	while (sljedeci != NULL)
	{
		if (trenutni->exp == sljedeci->exp) {	//ako su eksponenti jednaki
			sljedeci->coef += trenutni->coef;	//zbroj koef unosimo u sljedeci

			prethodni->next = sljedeci;	//trenutni se iskljucuje iz liste
			free(trenutni);	//oslobada se memorija trenutnog

			trenutni = sljedeci;	//sljedeci postaje trenutni
			sljedeci = sljedeci->next;	//sljedeci element
			prethodni=prethodni;	//prethodni ostaje isti
		}
		else {
			prethodni=trenutni;	
			trenutni=sljedeci;	
			sljedeci = sljedeci->next; 
		}
	}
	 
	return 0;
}


int ZbrojiPolinome(position p1, position p2, position rez)
{
	position novi = NULL;
	position rezhead = NULL;
	rezhead = rez;

	while (p1 != NULL && p2 != NULL) {
		if(p1->exp < p2->exp) {
			novi = (position)malloc(sizeof(polinom));	//stvara se novi clan

			novi->exp = p1->exp;	//unos podataka
			novi->coef = p1->coef;
			
			novi->next = rez->next;	//dodaje se u listu
			rez->next = novi;

			p1 = p1->next;

			rez = rez->next;
		}


		else if (p1->exp > p2->exp) {
			novi = (position)malloc(sizeof(polinom));	//stvara se novi clan

			novi->exp = p2->exp;	//unos podataka
			novi->coef = p2->coef;

			novi->next = rez->next;	//dodaje se u listu
			rez->next = novi;

			p2 = p2->next;
			rez = rez->next;
		}


		else if (p1->exp == p2->exp) {
			novi = (position)malloc(sizeof(polinom));	

			novi->exp = p2->exp;	
			novi->coef = p2->coef + p1->coef;

			novi->next = rez->next;	
			rez->next = novi;

			p1 = p1->next;
			p2 = p2->next;

			rez = rez->next;
		}
	}


	//slucajevi ako se dode do kraja jednog ili drugog polinoma



	if (p1 != NULL) {
		while (p1 != NULL) {
			novi = (position)malloc(sizeof(polinom));

			novi->coef = p1->coef;
			novi->exp = p1->exp;

			novi->next = rez->next;	//dodaje se u listu
			rez->next = novi;

			p1 = p1->next;
			rez = rez->next;
		}

	}

	if (p2 != NULL) {
		while (p2 != NULL) {
			novi = (position)malloc(sizeof(polinom));

			novi->coef = p2->coef;
			novi->exp = p2->exp;

			novi->next = rez->next;	
			rez->next = novi;

			p2 = p2->next;
			rez = rez->next;
		}

	}

	return 0;
}

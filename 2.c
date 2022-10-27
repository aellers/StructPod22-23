#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>														
#include <string.h>	
#include <ctype.h> //for tolower()																									
#define MAX 64

typedef struct Student * Pozicija;											

struct Student {															
	char ime[MAX];
	char prezime[MAX];
	int godRod;
	Pozicija next;
};

void UnosP(char *FName, char *LName, int birthYear, Pozicija P); //unos na pocetak
void Ispis(Pozicija P);	//ispis liste					
void UnosK(char *FName, char *LName, int birthYear, Pozicija P); //unos na kraj		
Pozicija Trazi(char *LName, Pozicija P); //trazi po prezimenu	
void Brisi(char *LName, Pozicija P); //brisi odredeni element

Pozicija TraziP(char *LName, Pozicija P);	//trazi prethodnog							


int main()
{
	char FName[MAX] = { 0 };
	char LName[MAX] = { 0 };
	int birthYear = 0;
	char izb  = 0;	
	struct Student Head;

	Head.next = NULL;

	//loop ends when user chooses q (quit)
	while (izb != 'q') {
		printf("Unesite p (unos na pocetak), k (unos na kraj), t (trazi po prezimenu), b (brisi odredeni element), i (ispis lite) ili q (quit): ");
		scanf(" %c", &izb);


		switch(izb) {
			case 'q':
				break;
			case 'p': 
				printf("\nUnesite ime studenta: ");
				scanf(" %s", FName);
				printf("Unesite prezime studenta: ");
				scanf(" %s", LName);
				printf("Unesite godinu rodenja studenta: ");
				scanf("%d", &birthYear);
				UnosP(FName, LName, birthYear, &Head);
				break;
			case 'k': 
				printf("\nUnesite ime studenta: ");
				scanf(" %s", FName);
				printf("Unesite prezime studenta: ");
				scanf(" %s", LName);
				printf("Unesite godinu rodenja studenta: ");
				scanf("%d", &birthYear);
				UnosK(FName, LName, birthYear, &Head);
				break;
			case 't':
				printf("\nUnesite prezime studenta: ");
				scanf(" %s", LName);
				Trazi(LName, Head.next);
			case 'b':
				printf("\nUnesite prezime studenta: ");
				scanf(" %s", LName);
				Brisi(LName, &Head);
				break;
			case 'i':
				Ispis(Head.next);
				break;
			default: 
				printf("\npogreska u unos");
				break;
		}
	}


    return 0;
}


void UnosP(char *FName, char *LName, int birthYear, Pozicija P) {
	Pozicija q = (Pozicija) malloc(sizeof(struct Student));

	strcpy(q->ime, FName);
	strcpy(q->prezime, LName);
	q->godRod = birthYear;

	q->next = P->next;
	P->next = q;

}

void UnosK(char *FName, char *LName, int birthYear, Pozicija P) {
	Pozicija q = (Pozicija) malloc(sizeof(struct Student));

	while (P->next != NULL) {
		P = P -> next;
	}

	strcpy(q->ime, FName);
	strcpy(q->prezime, LName);
	q->godRod = birthYear;

	q->next = P->next;
	P->next = q;

}

void Ispis(Pozicija P) {
	printf("\n\nIme\tPrezime\tGodina rodenja\n");
	while (P != NULL) {
		printf("%s\t%s\t%d\n", P->ime, P->prezime, P->godRod);
		P = P->next;
	}
	printf("\n\n");
}

Pozicija Trazi(char *LName, Pozicija P) {
	while (P != NULL && strcmp(LName, P->prezime)) {
		P = P->next;
	}

	if (P == NULL) {
		printf("Nije pronaden student s prezimenom %s\n", LName);
		return NULL;
	} else {
		printf("pronaden student s prezimenom %s\n", LName);
		return P;
	}
}

Pozicija TraziP(char *LName, Pozicija P) {
	Pozicija prev = P;
	P = P->next;

	while (P != NULL && strcmp(P->prezime, LName)) {
		prev = P;
		P = P->next;
	}

	if (P == NULL) {
		printf("Nema studenta s prezimenom %s\n", LName);
		return NULL;
	} else {
		return prev;
	}
}					


void Brisi(char *LName, Pozicija P) {
	Pozicija prev;

	prev = TraziP(LName, P);
	
	if (prev != NULL) {
		P = prev->next;														
		prev->next = P->next;
		free(P);													
	}
}

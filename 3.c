#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>														
#include <string.h>	
#include <ctype.h> //for tolower()																									
#define MAX 64

typedef struct Student* Pozicija;											

struct Student {															
	char ime[MAX];
	char prezime[MAX];
	int godRod;
	Pozicija next;
};

void UnosP(char* FName, char* LName, int birthYear, Pozicija P); //unos na pocetak
void Ispis(Pozicija P);	//ispis liste					
void UnosK(char* FName, char* LName, int birthYear, Pozicija P); //unos na kraj		
Pozicija Trazi(char* LName, Pozicija P); //trazi po prezimenu	
void Brisi(char* LName, Pozicija P); //brisi odredeni element

Pozicija TraziP(char* LName, Pozicija P);	//trazi prethodnog		

void UnosIza(char* FName, char* LName, int birthYear, Pozicija P); //unos nakon nekog elementa
void UnosIspred(char* FName, char* LName, int birthYear, Pozicija P); //unos prije nekog elementa
void Sort(Pozicija P); //sortiraj listu po prezimenu
void IspisDat(Pozicija P, char* DatIme); //ispis u datoteku 
void CitaDat(Pozicija P, char* DatIme); //cita iz datoteke


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
		printf("Izaberite:\n p (unos na pocetak)\n k (unos na kraj)\n t (trazi po prezimenu)\n b (brisi odredeni element)\n i (ispis lite)\n q (quit)\n\n ");
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
				printf("\n\n");
				break;
			case 'k': 
				printf("\nUnesite ime studenta: ");
				scanf(" %s", FName);
				printf("Unesite prezime studenta: ");
				scanf(" %s", LName);
				printf("Unesite godinu rodenja studenta: ");
				scanf("%d", &birthYear);
				UnosK(FName, LName, birthYear, &Head);
				printf("\n\n");
				break;
			case 't':
				printf("\nUnesite prezime studenta: ");
				scanf(" %s", LName);
				Trazi(LName, Head.next);
				printf("\n\n");
				break;
			case 'b':
				printf("\nUnesite prezime studenta: ");
				scanf(" %s", LName);
				Brisi(LName, &Head);
				printf("\n\n");
				break;
			case 'i':
				Ispis(Head.next);
				printf("\n\n");
				break;
			default: 
				printf("\npogreska u unos");
				printf("\n\n");
				break;
		}
	}


    return 0;
}


void UnosP(char* FName, char* LName, int birthYear, Pozicija P) {
	Pozicija q = (Pozicija) malloc(sizeof(struct Student));

	strcpy(q->ime, FName);
	strcpy(q->prezime, LName);
	q->godRod = birthYear;

	q->next = P->next;
	P->next = q;

}

void UnosK(char* FName, char* LName, int birthYear, Pozicija P) {
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
		printf("%s\t%s\t%d.\n", P->ime, P->prezime, P->godRod);
		P = P->next;
	}
}

Pozicija Trazi(char* LName, Pozicija P) {
	int count = 1;

	while (P != NULL && strcmp(LName, P->prezime)) {
		P = P->next;
		count++;
	}

	if (P == NULL) {
		printf("Nije pronaden student s prezimenom %s", LName);
		return NULL;
	} else {
		printf("pronaden student s prezimenom %s na %d. mjestu u listi", LName, count);
		return P;
	}
}

Pozicija TraziP(char* LName, Pozicija P) {
	Pozicija prev = P;
	P = P->next;

	while (P != NULL && strcmp(P->prezime, LName)) {
		prev = P;
		P = P->next;
	}

	if (P == NULL) {
		printf("Nema studenta s prezimenom %s", LName);
		return NULL;
	} else {
		return prev;
	}
}					


void Brisi(char* LName, Pozicija P) {
	Pozicija prev;

	prev = TraziP(LName, P);
	
	if (prev != NULL) {
		P = prev->next;														
		prev->next = P->next;
		free(P);													
	}
}


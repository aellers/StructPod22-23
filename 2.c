#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>														
#include<string.h>																										
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


int main()
{

    return 0;
}

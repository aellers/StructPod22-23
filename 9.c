#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define PRAZNO_STABLO 0
#define NAREDBA_MAX_LENGTH 20

//binarno stablo - dodaj element, ispis(4), pretrazi, izbrisi 

struct Stablo;
typedef struct Stablo* position;

typedef struct Stablo {
	int vrijednost;
	position lijevo;
	position desno;
}Stablo;


//funkcije

position dodajElement(position root,int vrijednost);
position stvoriNovi(int vrijednost);
int inorder(position root);
int preorder(position root);
int postorder(position root);
position pretrazi(position root, int vrijednost);
position delete(position root, int vrijednost);
position minCvor(position cvor);

//levelorder
int levelorder(position root);
int printCurrentLevel(position root, int level);
int height(position root);

bool isValidEl(position root, int el, int n); 

//funkcije iz 9. vjezbe
position insert(position root, int* niz, int n);

int main()
{
	//dodavanje
	char naredba[NAREDBA_MAX_LENGTH] = { 0 };
	int el = -1; 
	int n = 0; 
	position root = NULL;
	position p = NULL;
	bool validEl = false; 
    int vrijednost[] = {2, 5, 7, 8, 11, 1, 4, 2, 3, 7};
    int i = 0; 

    /*
    root = dodajElement(root, vrijednost[0]);
    for (i = 1; i < 10; i++)
    {
        dodajElement(root, vrijednost[i]);
    }*/

    root = insert(root, vrijednost, 10);

	while (strcmp(naredba, "quit") != 0) {  
		printf("\nOpcije:\n"
			"dodaj [el] - dodaj broj u stablo\n" 
			"preorder - preorder ispis\n"
			"inorder - inorder ispis\n"
			"postorder - postorder ispis\n"
			"level - level order ispis\n"
			"find [el] - pretrazi broj\n"
			"delete [el] - izbrisi broj\n"
			"quit - zavrsi program\n");

			scanf(" %s", naredba);
			
			if (strcmp(naredba, "quit") == 0)
				continue;

			if (strcmp(naredba, "dodaj") == 0) {
				n = scanf(" %d", &el);
				validEl = isValidEl(root, el, n);
				if (validEl == false)
					printf("Ne dozvoljena vrijenost\n");
					continue;
				dodajElement(root, el);
			} 
			else if (strcmp(naredba, "preorder") == 0) {
				preorder(root);
			}  
			else if (strcmp(naredba, "inorder") == 0) {
				inorder(root);
			}
			else if (strcmp(naredba, "postorder") == 0) {
				postorder(root);
			} 
			else if (strcmp(naredba, "level") == 0) {
				levelorder(root);
			}
			else if (strcmp(naredba, "delete") == 0) {
				scanf(" %d", &el);
				root = delete(root, el);
			} 
			else if (strcmp(naredba, "find") == 0) {
				scanf(" %d", &el);
				p = pretrazi(root, el);
				if (p == NULL) {
					printf("Nema vrijednosti %d u stablu\n", el);
				}
				else {
					printf("Element s vrijednost %d se nalazi na adresi %p\n", p->vrijednost, p);
				}
			}
			else {
				printf("Nepoznata naredba, pokusajte ponovo\n");
			}
			puts("");
	}
	puts("");
	

	return 0;
}


position dodajElement(position root, int vrijednost)
{
	if (!root) {
		return(stvoriNovi(vrijednost));
	}

	if (root->vrijednost > vrijednost) {
		root->lijevo = dodajElement(root->lijevo, vrijednost);
	}

	else {
		if (root->vrijednost < vrijednost) {
			root->desno = dodajElement(root->desno, vrijednost);
		}
	}
	
	return root;
}


position stvoriNovi(int vrijednost)
{

	position novi = malloc(sizeof(Stablo));
	novi->vrijednost = vrijednost;
	novi->lijevo = NULL;
	novi->desno = NULL;

	return novi;

}


int inorder(position root)
{
	if (root == NULL) {
		return PRAZNO_STABLO;
	}
		inorder(root->lijevo);
		printf("%d ", root->vrijednost);
		inorder(root->desno);

	return 0;
}

int preorder(position root)
{
	if (root == NULL) {
		return PRAZNO_STABLO;
	}
	printf("%d ", root->vrijednost);
	preorder(root->lijevo);
	preorder(root->desno);
	return 0;

}

int postorder(position root)
{
	if (root ==NULL) {
		return PRAZNO_STABLO;
	}

	postorder(root->lijevo);
	postorder(root->desno);
	printf("%d ", root->vrijednost);

	return 0;
}

int levelorder(position root)
{
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++)
		printCurrentLevel(root, i);

	return 0;
}


int printCurrentLevel(position root, int level)
{
	if (root == NULL) {
		return PRAZNO_STABLO;
	}
	if (level == 1) {
		printf("%d ", root->vrijednost);
	}
	else if (level > 1) {
		printCurrentLevel(root->lijevo, level - 1);
		printCurrentLevel(root->desno, level - 1);
	}

	return 0;
}

int height(position root)
{
	if (root == NULL) {
		return PRAZNO_STABLO;
	}
	else {
		/* compute the height of each subtree */
		int lheight = height(root->lijevo);
		int rheight = height(root->desno);

		/* use the larger one */
		if (lheight > rheight)
			return (lheight + 1);
		else
			return (rheight + 1);

		return 0;
	}

}

position pretrazi(position root, int vrijednost)
{
	if (root == NULL || root->vrijednost == vrijednost) {
		return root;
	}

	if (root->vrijednost < vrijednost) {
		return pretrazi(root->desno, vrijednost);
	}

	return pretrazi(root->lijevo, vrijednost);	


}


position delete(position root, int vrijednost)
{
	// base case
	if (root == NULL)
		return root;

	//vrijednost je u lijevom podstablu
	if (vrijednost < root->vrijednost)
		root->lijevo = delete(root->lijevo, vrijednost);

	//vrijednost je u desnom podstablu
	else if (vrijednost > root->vrijednost)
		root->desno= delete(root->desno, vrijednost);

	//vrijednost ista kao root vrijednost
	else {
		// cvor sa jednim djetetom ili bez djece
		if (root->lijevo == NULL) {
			position temp = root->desno;
			free(root);
			return temp;
		}
		else if (root->desno == NULL) {
			position temp = root->lijevo;
			free(root);
			return temp;
		}

		// cvor sa dvoje djece, nadi najmanji u desnom podstablu
	
		position temp = minCvor(root->desno);

		//kopiraj vrijednost najmanjeg
		root->vrijednost = temp->vrijednost;

		// izbrisi najmanji
		root->desno = delete(root->desno, temp->vrijednost);
	}
	return root;
}

position minCvor(position cvor)
{

	position current = cvor;

	while (current && current->lijevo != NULL)
		current = current->lijevo;

	return current;

}


bool isValidEl(position root, int el, int n) 
{
	position p = NULL;
	p = pretrazi(root, el); 
	if (p == root && root->vrijednost != el) 
		return false;
	if (n != 1)
		return false;
	if (el <= 0) 
		return false;
	
	return true;
}

position insert(position root, int* niz, int n) 
{
    int i = 1;
    root = dodajElement(root, niz[0]);
    for (i = 1; i < n; i++)
    {
        dodajElement(root, niz[i]);
    }

    return root;
}
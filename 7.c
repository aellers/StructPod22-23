#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_FILENAME_LENGTH 12

typedef struct node node;
typedef struct node* position;

typedef struct node {
    char name[MAX_FILENAME_LENGTH];
    position nextSibling;
    position firstChild;
} node;

int createSubdirectory(position p, char* dirName);
int createDirectory(position p, char* dirName);

int main() {
    node root = {.nextSibling = NULL, .firstChild = NULL };
    strcpy(root.name, "root");
    
    return 0;
}

//create child
int createSubdirectory(position p, char* dirName) {
    position q = NULL;

    q = (node*) malloc(sizeof(node));
    if (q == NULL) {
        return -1;
    }

    if (p->firstChild != NULL) {
        p = p->firstChild;
        while (p->nextSibling != NULL) {
            p = p->nextSibling;
        }
        p->nextSibling = q;
    } else {
        p->firstChild = q;
    }
        q->firstChild = NULL;
        q->nextSibling = NULL;
        strcpy(q->name, dirName);

    return 0;
}

//create sibling
int createDirectory(position p, char* dirName) {
    position q = NULL;

    q = (node*) malloc(sizeof(node));
    if (q == NULL) {
        return -1;
    }

    while (p->nextSibling != NULL) {
        p = p->nextSibling;
    }

    p->nextSibling = q;
    q->firstChild = NULL;
    q->nextSibling = NULL;
    strcpy(q->name, dirName);

    return 0;
}

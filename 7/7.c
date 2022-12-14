#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_FILENAME_LENGTH 12

typedef struct node node;
typedef struct node* treePos;

typedef struct node {
    char name[MAX_FILENAME_LENGTH];
    treePos nextSibling;
    treePos firstChild;
} node;

//stack for traversal and output; stores pointers to nodes of tree
typedef struct stack stack;
typedef struct stack* stackPos;

typedef struct stack {
    node el;
    //element put on stack before 
    stackPos pointsTo;
} stack;


int createSubdirectory(treePos p, char* dirName);
int createDirectory(treePos p, char* dirName);

treePos push(stackPos p, treePos el);
treePos pop();

int main() {
    stack head = {.el = NULL, .pointsTo = NULL};
    treePos rightmost = NULL;
    node root = {.nextSibling = NULL, .firstChild = NULL };
    strcpy(root.name, "root");
    
    return 0;
}

//create child
int createSubdirectory(treePos p, char* dirName) {
    treePos q = NULL;

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
int createDirectory(treePos p, char* dirName) {
    treePos q = NULL;

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

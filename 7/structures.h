#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "constants.h"


typedef struct node node;
typedef struct node* nodePos;

//tree structure
typedef struct node {
    char name[MAX_FILENAME_LENGTH];
    nodePos nextSibling;
    nodePos firstChild;
} node;

//stack for traversal and output; stores pointers to nodes of tree
typedef struct stack stack;
typedef struct stack* stackPos;

typedef struct stack {
    nodePos el;
    //element put on stack before 
    stackPos pointsTo;
} stack;

#endif 
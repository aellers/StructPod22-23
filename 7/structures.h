#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "constants.h"


typedef struct treeEl treeEl;
typedef struct treeEl* treeElPos;

//tree structure
typedef struct treeEl {
    char name[MAX_FILENAME_LENGTH];
    treeElPos nextSibling;
    treeElPos firstChild;
} treeEl;

//stack for traversal and output; stores pointers to nodes of tree
typedef struct stackEl stackEl;
typedef struct stackEl* stackElPos;

typedef struct stackEl {
    treeElPos el;
    stackElPos lastIn; //element put on stack before 
} stackEl;

typedef struct stack {
    stackEl head; 
    stackElPos top;
} stack;


#endif 
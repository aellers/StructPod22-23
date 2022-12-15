#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"

int createDir(treeElPos p, char* dirName) {
    treeElPos q = NULL;

    q = (treeEl*) malloc(sizeof(treeEl));
    if (q == NULL) {
        return -1;
    }

    if (p->firstChild == NULL) {
        p->firstChild = q;
    } else { //p has children
        p = p->firstChild;
        while (p->nextSibling != NULL) {
            p = p->nextSibling;
        }

        p->nextSibling = q;
    }
    q->firstChild = NULL;
    q->nextSibling = NULL;
    strcpy(q->name, dirName);

    return 0;
}

int listSubdirectories(treeElPos treeEl) {
    if (treeEl->firstChild == NULL) { 
        printf("\n");
        return 0; 
    }
    treeEl = treeEl->firstChild; //how without extra steps
    while (treeEl->nextSibling != NULL) {
        printf("%s\n", treeEl->name);
        treeEl = treeEl->nextSibling;
    }
    //had this before the while and spent some hours trying to find the thing causing unexpected output for md
    printf("%s\n", treeEl->name); 
    puts("");
    return 0; 
}

int listCurrentDirectory(treeElPos thistreeEl) {
    printf("%s\n\n", thistreeEl->name);
    return 0; 
}

treeElPos isSubdirectory(treeElPos thistreeEl, char* name) { //returns address if exists
    treeElPos q = NULL;
    q = thistreeEl->firstChild;
    while (strcmp(q->name, name) != 0) {
        q = q->nextSibling;
    }
    if (strcmp(q->name, name) != 0) {
        return NULL;
    }
    return q;
}
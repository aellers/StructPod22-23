#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"

//create child
int createSubdirectory(nodePos p, char* dirName) {
    nodePos q = NULL;

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
        p->firstChild = q;//why two lines with same thing?
    }
        q->firstChild = NULL;
        q->nextSibling = NULL;
        strcpy(q->name, dirName);


    return 0;
}

//create sibling
int createDirectory(nodePos p, char* dirName) {
    nodePos q = NULL;

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



//not sure what the bes way is for the functions in this file to be able to access this
//not sure if needed anymore
nodePos findRightmost(nodePos thisNode) { 
    while (thisNode->firstChild != NULL && thisNode->nextSibling != NULL) {
        if (thisNode->nextSibling == NULL) {
            thisNode = thisNode->firstChild;
        } else {
            thisNode = thisNode->nextSibling; 
        }
    }
    return thisNode;
}

int listSubdirectories(nodePos node) {
    if (node->firstChild == NULL) { 
        printf("\n");
        return 0; 
    }
    node = node->firstChild;
    printf("%s\n", node->name); //lists first child, unsure of how to without this extra step

    while (node->nextSibling != NULL) {
        printf("%s\n", node->name);
        node = node->nextSibling;
    }
    puts("");
    return 0; 
}

int listCurrentDirectory(nodePos thisNode) {
    printf("%s\n\n", thisNode->name);
    return 0; 
}

nodePos isSubdirectory(nodePos thisNode, char* name) { //returns address if exists
    nodePos q = NULL;
    q = thisNode->firstChild;
    while (strcmp(q->name, name) != 0) {
        q = q->nextSibling;
    }
    if (strcmp(q->name, name) != 0) {
        return NULL;
    }
    return q;
}
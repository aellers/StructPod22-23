#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "structures.h"

treeElPos push(stack* pStack, treeElPos el) {
    stackElPos q = NULL;
    q = (stackEl*) malloc(sizeof(treeEl));
    if (el == NULL || q == NULL) {
        return NULL;
    }
    if (q == NULL) {
        return NULL;
    }
    q->el = el;
    q->lastIn = pStack->top;
    pStack->top = q;
    return q->el;
}


treeElPos pop(stack* pStack) {
    treeElPos el = pStack->top->el;

    if (pStack->top->lastIn == NULL) {
        return NULL;
        printf("Empty stack\n");
    }
    pStack->top = pStack->top->lastIn;
    free(pStack->top);
    return el;
}

int ispis(stack* pStack) {
    
    stackElPos p = pStack->top;
    puts("testA"); 
    while (p->lastIn != NULL) {
        printf("%s\n", (void*) p->el);
        p = p->lastIn;
    }
    puts("");
    return 0; 
}
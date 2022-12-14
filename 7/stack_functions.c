#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

//lastIn
nodePos push(stackPos lastIn, nodePos el) {
    stackPos q = NULL;
    q = (stack*) malloc(sizeof(node));
    if (el == NULL || q == NULL) {
        return NULL;
    }
    q->el = el;
    q->pointsTo = lastIn;
    lastIn = q;

    return el;
}

//fix later? does it work now?
nodePos pop(stackPos lastIn) {
    nodePos returnValue = lastIn->el;
    stackPos temp = NULL;
    

    //free();
    *lastIn = *temp;
    return returnValue;
}
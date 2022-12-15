//work on int listThisDirectory(treeElPos thisNode, stackElPos lastIn); first; it's a mess
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "structures.h"
#include "loop.h"

int main() {
    stack stack;
    stack.head.el = NULL;
    stack.head.lastIn = NULL;
    
    treeEl root = { .nextSibling = NULL, .firstChild = NULL };
    strcpy(root.name, "root");

    mainLoop(&stack, &root); //fix
    
    //call functions to clean up stack and tree (together)
    return 0;
}

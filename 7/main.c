//work on int listThisDirectory(nodePos thisNode, stackPos lastIn); first; it's a mess
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "structures.h"
#include "loop.h"

int main() {
    stack head = { .el = NULL, .pointsTo = NULL };
    nodePos rightmost = NULL;
    node root = { .nextSibling = NULL, .firstChild = NULL };
    strcpy(root.name, "root");

    mainLoop(&head, rightmost, &root);
    
    //call functions to clean up stack and tree (together)
    return 0;
}

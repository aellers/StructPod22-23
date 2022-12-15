#ifndef TREE_FUNCTIONS_H
#define TREE_FUNCTIONS_H
#include "structures.h"

int createDir(treeElPos p, char* dirName);
int createDira(treeElPos p, char* dirName); //will probably delete later

int listSubdirectories(treeElPos treeEl);
int listCurrentDirectory(treeElPos thistreeEl);
treeElPos isSubdirectory(treeElPos thistreeEl, char* name);


#endif
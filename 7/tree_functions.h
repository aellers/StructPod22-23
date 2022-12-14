#ifndef TREE_FUNCTIONS_H
#define TREE_FUNCTIONS_H
#include "structures.h"

int createSubdirectory(nodePos p, char* dirName);
int createDirectory(nodePos p, char* dirName);
int listSubdirectories(nodePos node);
int listCurrentDirectory(nodePos thisNode);
nodePos isSubdirectory(nodePos thisNode, char* name);

nodePos findRightmost(nodePos thisNode);



#endif
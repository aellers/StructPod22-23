#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"
#include "constants.h"
#include "stack_functions.h"
#include "tree_functions.h"

int mainLoop(stack* pStack, treeEl* rootPos) {
    char command[MAX_COMMAND_LENGTH] = { 0 }; 
    char dirName[MAX_FILENAME_LENGTH] = { 0 };
    treeElPos currentNode = rootPos; //where we are right now (used when moving around to create subdirectories)
    treeElPos thisNode = rootPos;
    treeElPos p = NULL; //not a new node// p and currentNode do the same thing, clean up
    stackElPos lastIn = &(pStack->head);

    while (strcmp(command, "quit") != 0) {
        p = NULL;
        strcpy(dirName, "");

        printf("Menu options\n"
            "md [name] - make directory\n"
            "cd [name] - move to subdirectory [name]\n"
            "cd.. - move to parent directory\n"
            "dir - list subdirectory of current directory\n"
            "current - list current directory\n" //not a dos command (afaik), just for convenience
            /*"ispis - write out stack" //for testing (doesn't work though)*/
            "quit - quits program\n\n");

            scanf(" %s", command);
            if (strcmp(command, "md") == 0 || strcmp(command, "cd") == 0) {
                scanf(" %s", dirName);
                if (strcmp(command, "md") == 0) { 
                    createDir(thisNode, dirName);
                } else { //(strcmp(command, "cd") == 0)
                    push(pStack, thisNode);
                    thisNode = isSubdirectory(thisNode, dirName);
                }
            } else if (strcmp(command, "cd..") == 0) { //complicated and hard
                if (thisNode == rootPos) {
                    puts("Stack is empty\n"); //test
                } else {
                    thisNode = pop(pStack);
                }
            } else if (strcmp(command, "dir") == 0) {
                listSubdirectories(thisNode);
            /*} else if (strcmp(command, "ispis") == 0) {
                ispis(pStack);*/
            } else if (strcmp(command, "current") == 0) {
                listCurrentDirectory(thisNode);
            } else if (strcmp(command, "quit") == 0) {
                continue;
            }  else {
                printf("Unknown command, please try again.\n\n");
                continue;
            }
            
    }

    return 0; 
}

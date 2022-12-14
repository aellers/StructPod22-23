#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"
#include "constants.h"
#include "stack_functions.h"
#include "tree_functions.h"

int mainLoop(stackPos headPos, node* rightmost, node* rootPos) {
    char command[MAX_COMMAND_LENGTH] = { 0 }; 
    char dirName[MAX_FILENAME_LENGTH] = { 0 };
    nodePos currentNode = rootPos; //where we are right now (used when moving around to create subdirectories)
    nodePos thisNode = rootPos;
    nodePos newNode = NULL; 
    nodePos p = NULL; //not a new node// p and currentNode do the same thing, clean up
    stackPos lastIn = headPos;

    while (strcmp(command, "quit") != 0) {
        newNode = NULL; //is it bad to do it like this?
        p = NULL;
        printf("Menu options\n"
            "md [name] - make directory\n"
            "cd [name] - move to subdirectory [name]\n"
            "cd.. - move to parent directory\n"
            "dir - list subdirectory of current directory\n"
            "current - list current directory\n" //not a dos command (afaik), just for convenience
            "quit - quits program\n\n");

            scanf(" %s", command);
            if (strcmp(command, "md") == 0 || strcmp(command, "cd") == 0) {
                scanf(" %s", dirName);
                if (strcmp(command, "md") == 0) {
                    //if node has no children this will be the first
                    if (thisNode->firstChild == NULL) {
                        createSubdirectory(thisNode, dirName);
                    } else { //if this node has children this will be a sibling of its first child (and children generally) 
                        newNode = thisNode->firstChild;
                        createDirectory(newNode, dirName);
                    }

                } else { //(strcmp(command, "cd") == 0)// //doesn't yet work
                   p = isSubdirectory(thisNode, dirName);
                   if (p == NULL) {
                    printf("Unable to mmove to directory %s, does not exist\n\n", dirName);
                    continue;
                    }
                    /*push(lastIn, thisNode);
                    thisNode = p;
                    puts("\n");*/ //doesn't work, will probably add back later
                }
            } else if (strcmp(command, "cd..") == 0) {
                //this is going to be the most commplicated one, but way less so than whatever I was thinking of for that one thing
                thisNode = pop(lastIn);
                listCurrentDirectory(thisNode); //for testing
            } else if (strcmp(command, "dir") == 0) {
                listSubdirectories(thisNode);
            } else if (strcmp(command, "current") == 0) {
                listCurrentDirectory(thisNode);
            } else if (strcmp(command, "quit") == 0) {
                continue;
            }  else {
                printf("Unknown command, please try again.\n\n");
                //make add some things like if "q" do you want to quit, maybe
                continue;
            }
            
    }

    return 0; 
}

#include <stdio.h>

struct TreeNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* Tree;

typedef struct TreeNode{
    int El; 
    Position Left;
    Position Right;
}TreeNode; 

Tree MakeEmpty(Tree T);
int Add(int El, Tree T);
int PrintInorder(Tree T);
int PrintPreorder(Tree T);
int PrintPostorder(Tree T);
int PrintLevelOrder(Tree T); //solve using queue structure
int EraseEl(int El, Tree T);
Position FindEl(int El, Tree T);

int main() {
    Tree tree; 

    return 0; 
}
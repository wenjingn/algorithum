#ifndef __BITREE_H
#define __BITREE_H

typedef struct BiTreeNode BiTreeNode;
typedef struct BiTreeNode *BiTree;
struct BiTreeNode {
    struct BiTreeNode *p;
    struct BiTreeNode *l;
    struct BiTreeNode *r;
    int key;
};

BiTreeNode *bitreeMaximum(BiTreeNode *n);
BiTreeNode *bitreeMinimum(BiTreeNode *n);
BiTreeNode *bitreeSuccessor(BiTreeNode *n);
BiTreeNode *bitreePredecessor(BiTreeNode *n);
BiTreeNode *bitreeSearch(BiTree *bt, int key);
int bitreeInsert(BiTree *bt, int key);
void bitreeDelete(BiTree *bt, BiTreeNode *n);

void displayNode(BiTreeNode *n);

void bitreePreOrderWalkRecursive(BiTreeNode *n);
void bitreeInOrderWalkRecursive(BiTreeNode *n);
void bitreePostOrderWalkRecursive(BiTreeNode *n);

void bitreePreOrderWalkStack(BiTree *bt);
void bitreeInOrderWalkStack(BiTree *bt);
void bitreePostOrderWalkStack(BiTree *bt);

void bitreePreOrderWalk(BiTree *bt);
void bitreeInOrderWalk(BiTree *bt);
void bitreePostOrderWalk(BiTree *bt);

#endif

#ifndef __RBTREE_H
#define __RBTREE_H

#define RBTREE_RED 0
#define RBTREE_BLACK 1

typedef struct RBTreeNode RBTreeNode;
typedef struct RBTree RBTree;
typedef void rbtreeWalkHandler(RBTree *t, RBTreeNode *n);

struct RBTreeNode {
    RBTreeNode *p;
    RBTreeNode *l;
    RBTreeNode *r;
    int color;
    int key;
};

struct RBTree {
    RBTreeNode *rt;
    RBTreeNode *nil;
};

RBTree *rbtreeCreate();
void rbtreeLeftRotate(RBTree *t, RBTreeNode *n);
void rbtreeRightRotate(RBTree *t, RBTreeNode *n);
RBTreeNode *rbtreeMaximum(RBTree *t, RBTreeNode *n);
RBTreeNode *rbtreeMinimum(RBTree *t, RBTreeNode *n);
RBTreeNode *rbtreeSuccessor(RBTree *t, RBTreeNode *n);
RBTreeNode *rbtreePredecessor(RBTree *t, RBTreeNode *n);
RBTreeNode *rbtreeSearch(RBTree *t, int k);
int rbtreeInsert(RBTree *t, int k);
void rbtreeInsertFixup(RBTree *t, RBTreeNode *n);
void rbtreeDelete(RBTree *t, RBTreeNode *n);
void rbtreeDeleteFixup(RBTree *t, RBTreeNode *n);
void rbtreePreOrderWalk(RBTree *t, rbtreeWalkHandler *handler);
void rbtreeInOrderWalk(RBTree *t, rbtreeWalkHandler *handler);
void rbtreePostOrderWalk(RBTree *t, rbtreeWalkHandler *handler);

#endif

#include <stdio.h>
#include "../rbtree.c"

void displayNode(RBTree *t, RBTreeNode *n)
{
    printf("key:%d color:%d\n", n->key, n->color);
}

int main()
{
    RBTree *t = rbtreeCreate();
    rbtreeInsert(t, 8);
    rbtreeInsert(t, 7);
    rbtreeInsert(t, 6);
    rbtreeInsert(t, 5);
    rbtreeInsert(t, 4);
    rbtreeInsert(t, 3);
    rbtreeInsert(t, 2);
    rbtreeInsert(t, 1);

    rbtreePreOrderWalk(t, displayNode);
    printf("---------------------------\n");
    rbtreeInOrderWalk(t, displayNode);
    printf("---------------------------\n");
    rbtreePostOrderWalk(t, displayNode);
    printf("---------------------------\n");
    
    RBTreeNode *n = rbtreeSearch(t, 5);
    rbtreeDelete(t, n);
    
    printf("---------------------------------------------------------------\n");
    rbtreePreOrderWalk(t, displayNode);
    printf("---------------------------\n");
    rbtreeInOrderWalk(t, displayNode);
    printf("---------------------------\n");
    rbtreePostOrderWalk(t, displayNode);
    printf("---------------------------\n");
}

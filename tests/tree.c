#include <stdio.h>
#include "../bitree.c"

int main()
{
    BiTree *bt = bitreeCreate();
    bitreeInsert(bt, 5);
    bitreeInsert(bt, 3);
    bitreeInsert(bt, 7);
    bitreeInsert(bt, 2);
    bitreeInsert(bt, 8);
    bitreeInsert(bt, 4);
    bitreeInsert(bt, 1);

    bitreePreOrderWalkRecursive(*bt);
    printf("\n");
    bitreePreOrderWalk(bt);
    printf("\n");
    BiTreeNode *n = bitreeSearch(bt, 3);
    bitreeDelete(bt, n);
    n = bitreeSearch(bt, 5);
    bitreeDelete(bt, n);
    bitreePostOrderWalkRecursive(*bt);
}

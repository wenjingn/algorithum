#include <stdlib.h>
#include "bitree.h"

BiTree *bitreeCreate()
{
    return malloc(sizeof(BiTree));
}

BiTreeNode *bitreeMaximum(BiTreeNode *n)
{
    if (n == NULL) return NULL;
    while (n->r) {
        n = n->r;
    }

    return n;
}

BiTreeNode *bitreeMinimum(BiTreeNode *n)
{
    if (n == NULL) return NULL;
    while (n->l) {
        n = n->l;
    }
    return n;
}

BiTreeNode *bitreeSuccessor(BiTreeNode *n)
{
    if (n == NULL) return NULL;
    if (n->r) {
        return bitreeMinimum(n->r);
    }

    BiTreeNode *p = n->p;
    while (p && p->r == n) {
        n = p;
        p = p->p;
    }

    return p;
}

BiTreeNode *bitreePredecessor(BiTreeNode *n)
{
    if (n == NULL) return NULL;
    if (n->l) {
        return bitreeMaximum(n->l);
    }

    BiTreeNode *p = n->p;
    while (p && p->l == n) {
        n = p;
        p = p->p;
    }
    return p;
}

BiTreeNode *bitreeSearch(BiTree *bt, int key)
{
    BiTreeNode *n = *bt;
    while (n) {
        if (key == n->key) {
            return n;
        } else if (key > n->key) {
            n = n->r;
        } else {
            n = n->l;
        }
    }

    return NULL;
}

int bitreeInsert(BiTree *bt, int key)
{
    BiTreeNode *n = malloc(sizeof(*n));
    if (n == NULL) return -1;

    n->p = NULL;
    n->l = NULL;
    n->r = NULL;
    n->key = key;
    if (*bt == NULL) {
        *bt = n;
        return 0;
    }

    BiTreeNode *curr = *bt;
    BiTreeNode *p;
    while (curr) {
        p = curr;
        if (n->key > curr->key) {
            curr = curr->r;
        } else {
            curr = curr->l;
        }
    }

    if (n->key > p->key) {
        p->r = n;
    } else {
        p->l = n;
    }
    n->p = p;
    return 0;
}

void bitreeDelete(BiTree *bt, BiTreeNode *n)
{
    BiTreeNode *todel, *child;
    if (n->l == NULL || n->r == NULL) {
        todel = n;
    } else {
        todel = bitreeSuccessor(n);
    }

    if (todel->l) {
        child = todel->l;
    } else {
        child = todel->r;
    }

    if (child) {
        child->p = todel->p;
    }

    if (todel->p == NULL) {
        *bt = child;
    } else if (todel == todel->p->l) {
        todel->p->l = child;
    } else {
        todel->p->r = child;
    }

    if (n != todel) {
        n->key = todel->key;
    }
    free(todel);
}

void displayNode(BiTreeNode *n)
{
    printf("{key:%d n:%p p:%p l:%p r:%p}\n", n->key, n, n->p, n->l, n->r);
}

void bitreePreOrderWalkRecursive(BiTreeNode *n)
{
    if (n == NULL) return;
    displayNode(n);
    bitreePreOrderWalkRecursive(n->l);
    bitreePreOrderWalkRecursive(n->r);
}

void bitreeInOrderWalkRecursive(BiTreeNode *n)
{
    if (n == NULL) return;
    bitreeInOrderWalkRecursive(n->l);
    displayNode(n);
    bitreeInOrderWalkRecursive(n->r);
}

void bitreePostOrderWalkRecursive(BiTreeNode *n)
{
    if (n == NULL) return;
    bitreePostOrderWalkRecursive(n->l);
    bitreePostOrderWalkRecursive(n->r);
    displayNode(n);
}

void bitreePreOrderWalkStack(BiTree *bt)
{
    BiTreeNode *n;
    BiTreeNode *S[10] = {*bt};
    int top = 0;
    
    while (top > -1) {
        n = S[top];
        while (n) {
            displayNode(n);
            n = n->l;
            S[++top] = n;
        }
        
        top--;
        if (top > -1) {
            n = S[top--];
            n = n->r;
            S[++top] = n;
        }
    }
}

void bitreeInOrderWalkStack(BiTree *bt)
{
    BiTreeNode *n;
    BiTreeNode *S[10] = {*bt};
    int top = 0;
    while (top > -1) {
        n = S[top];
        while (n) {
            n = n->l;
            S[++top] = n;
        }

        top--;
        if (top > -1) {
            n = S[top--];
            displayNode(n);
            n = n->r;
            S[++top] = n;
        }
    }
}

void bitreePostOrderWalkStack(BiTree *bt)
{
    BiTreeNode *n = *bt;
    BiTreeNode *child;
    BiTreeNode *S[10] = {NULL};
    int top = -1;

    do {
        while (n) {
            S[++top] = n;
            n = n->l;
        }

        child = NULL;
        while (top > -1) {
            n = S[top];
            if (n->r == NULL || child == n->r) {
                displayNode(n);
                child = n;
                top--;
            } else {
                n = n->r;
                break;
            }
        }
    } while (top > -1);
}

void bitreePreOrderWalk(BiTree *bt)
{
    BiTreeNode *n = *bt;
    BiTreeNode *child;
    while (n) {
        while (n->l) {
            displayNode(n);
            n = n->l;
        }
        displayNode(n);

        child = NULL;
        while (n) {
            if (n->r == NULL || child == n->r) {
                child = n;
                n = n->p;
            } else {
                n = n->r;
                break;
            }
        }
    }
}

void bitreeInOrderWalk(BiTree *bt)
{
    BiTreeNode *n = *bt;
    BiTreeNode *child;
    while (n) {
        while (n->l) {
            n = n->l;
        }

        child = NULL;
        while (n) {
            if (n->r == NULL || child == n->r) {
                if (n->r == NULL) {
                    displayNode(n);
                }
                child = n;
                n = n->p;
            } else {
                displayNode(n);
                n = n->r;
                break;
            }
        }
    }
}

void bitreePostOrderWalk(BiTree *bt)
{
    BiTreeNode *n = *bt;
    BiTreeNode *child;
    while (n) {
        while (n->l) {
            n = n->l;
        }

        child = NULL;
        while (n) {
            if (n->r == NULL || child == n->r) {
                displayNode(n);
                child = n;
                n = n->p;
            } else {
                n = n->r;
                break;
            }
        }
    }
}

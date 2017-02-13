#include <stdlib.h>
#include "rbtree.h"

RBTree *rbtreeCreate()
{
    RBTree *t = malloc(sizeof(RBTree));
    if (t == NULL) return NULL; 
    
    t->nil = malloc(sizeof(RBTreeNode));
    if (t->nil == NULL) {
        free(t);
        return NULL;
    }

    t->nil->color = RBTREE_BLACK;
    t->rt = t->nil;
    return t;
}

void rbtreeLeftRotate(RBTree *t, RBTreeNode *n)
{
    if (n->r == t->nil) return;
    RBTreeNode *r = n->r;
    r->p = n->p;
    if (n->p == t->nil) {
        t->rt = r;
    } else if (n == n->p->l) {
        n->p->l = r;
    } else {
        n->p->r = r;
    }
    
    n->r = r->l;
    r->l->p = n;

    r->l = n;
    n->p = r;
}

void rbtreeRightRotate(RBTree *t, RBTreeNode *n)
{
    if (n->l == t->nil) return;
    RBTreeNode *l = n->l;
    l->p = n->p;
    if (n->p == t->nil) {
        t->rt = l;
    } else if (n == n->p->l) {
        n->p->l = l;
    } else {
        n->p->r = l;
    }

    n->l = l->r;
    l->r->p = n;

    n->p = l;
    l->r = n;
}

RBTreeNode *rbtreeMaximum(RBTree *t, RBTreeNode *n)
{

    while (n->r != t->nil) {
        n = n->r;
    }
    return n;
}

RBTreeNode *rbtreeMinimum(RBTree *t, RBTreeNode *n)
{
    while (n->l != t->nil) {
        n = n->l;
    }
    return n;
}

RBTreeNode *rbtreeSuccessor(RBTree *t, RBTreeNode *n)
{
    if (n->r != t->nil) {
        return rbtreeMinimum(t, n->r);
    }

    while (n->p != t->nil && n == n->p->r) {
        n = n->p;
    }

    if (n->p != t->nil) {
        return n->p;
    }

    return NULL;
}

RBTreeNode *rbtreeDecessor(RBTree *t, RBTreeNode *n)
{
    if (n->l != t->nil) {
        return rbtreeMaximum(t, n->l);
    }

    while (n->p != t->nil && n == n->p->l) {
        n = n->p;
    }

    if (n->p != t->nil) {
        return n->p;
    }

    return NULL;
}

RBTreeNode *rbtreeSearch(RBTree *t, int key)
{
    RBTreeNode *n = t->rt;
    while (n != t->nil) {
        if (key == n->key) {
            return n;
        } else if (key < n->key) {
            n = n->l;
        } else {
            n = n->r;
        }
    }

    return NULL;
}

int rbtreeInsert(RBTree *t, int k)
{
    RBTreeNode *n = malloc(sizeof(*n));
    if (n == NULL) {
        return -1;
    }
    
    n->l = t->nil;
    n->r = t->nil;
    n->color = RBTREE_RED;
    n->key = k;

    RBTreeNode *p = t->nil;
    RBTreeNode *c = t->rt;
    while (c != t->nil) {
        p = c;
        if (k < c->key) {
            c = c->l;
        } else {
            c = c->r;
        }
    }

    n->p = p;
    if (p == t->nil) {
        t->rt = n;
    } else if (k < p->key) {
        p->l = n;
    } else {
        p->r = n;
    }

    rbtreeInsertFixup(t, n);
    return 0;
}

void rbtreeInsertFixup(RBTree *t, RBTreeNode *n)
{
    RBTreeNode *uncle;
    while (n->p->color == RBTREE_RED) {
        if (n->p == n->p->p->l) {
            uncle = n->p->p->r;
            if (uncle->color == RBTREE_RED) {
                uncle->color = RBTREE_BLACK;
                n->p->color = RBTREE_BLACK;
                n->p->p->color = RBTREE_RED;
                n = n->p->p;
            } else {
                if (n == n->p->r) {
                    n = n->p;
                    rbtreeLeftRotate(t, n);
                }
                n->p->color = RBTREE_BLACK;
                n->p->p->color = RBTREE_RED;
                rbtreeRightRotate(t, n->p->p);
            }
        } else {
            uncle = n->p->p->l;
            if (uncle->color == RBTREE_RED) {
                uncle->color = RBTREE_BLACK;
                n->p->color = RBTREE_BLACK;
                n->p->p->color = RBTREE_RED;
                n = n->p->p;
            } else {
                if (n == n->p->l) {
                    n = n->p;
                    rbtreeRightRotate(t, n);
                }
                n->p->color = RBTREE_BLACK;
                n->p->p->color = RBTREE_RED;
                rbtreeLeftRotate(t, n->p->p);
            }
        }
    }
    t->rt->color = RBTREE_BLACK;
}

void rbtreeDelete(RBTree *t, RBTreeNode *n)
{
    RBTreeNode *todel, *child;
    if (n->l == t->nil || n->r == t->nil) {
        todel = n;
    } else {
        todel = rbtreeSuccessor(t, n);
    }

    if (todel->l != t->nil) {
        child = todel->l;
    } else {
        child = todel->r;
    }
    
    child->p = todel->p;
    
    if (todel == t->rt) {
        t->rt = child;
    } else if (todel == todel->p->l) {
        todel->p->l = child;
    } else {
        todel->p->r = child;
    }

    if (n != todel) {
        n->key = todel->key;
    }

    if (todel->color == RBTREE_BLACK)
        rbtreeDeleteFixup(t, child);
}

void rbtreeDeleteFixup(RBTree *t, RBTreeNode *n)
{
    while (n != t->rt && n->color == RBTREE_BLACK) {
        RBTreeNode *s;
        if (n == n->p->l) {
            s = n->p->r;
            if (s->color == RBTREE_RED) {
                n->p->color = RBTREE_RED;
                s->color = RBTREE_BLACK;
                rbtreeLeftRotate(t, n->p);
                s = n->p->r;
            }

            if (s->l->color == RBTREE_BLACK && s->r->color == RBTREE_BLACK) {
                s->color = RBTREE_RED;
                n = n->p;
            } else {
                if (s->r->color == RBTREE_BLACK) {
                    s->color = RBTREE_RED;
                    s->l->color = RBTREE_BLACK;
                    rbtreeRightRotate(t, s);
                    s = n->p->r;
                }
                
                s->color = n->p->color;
                n->p->color = RBTREE_BLACK;
                s->r->color = RBTREE_BLACK;
                rbtreeLeftRotate(t, n->p);
                n = t->rt;
            }
        } else {
            s = n->p->l;
            if (s->color == RBTREE_RED) {
                s->color = RBTREE_BLACK;
                n->p->color = RBTREE_RED;
                rbtreeRightRotate(t, n->p);
                s = n->p->l;
            }

            if (s->l->color == RBTREE_BLACK && s->r->color == RBTREE_BLACK) {
                s->color = RBTREE_RED;
                n = n->p;
            } else {
                if (s->l->color == RBTREE_BLACK) {
                    s->color = RBTREE_RED;
                    s->r->color = RBTREE_BLACK;
                    rbtreeLeftRotate(t, s);
                    s = n->p->l;
                }

                s->color = n->p->color;
                n->p->color = RBTREE_BLACK;
                s->l->color = RBTREE_BLACK;
                rbtreeRightRotate(t, n->p);
                n = t->rt;
            }
        }
    }

    n->color = RBTREE_BLACK;
}

void rbtreePreOrderWalk(RBTree *t, rbtreeWalkHandler *handler)
{
    RBTreeNode *n = t->rt;
    RBTreeNode *child;
    while (n != t->nil) {
        handler(t, n);
        while (n->l != t->nil) {
            n = n->l;
            handler(t, n);
        }

        child = NULL;
        while (n != t->nil) {
            if (n->r == t->nil || child == n->r) {
                child = n;
                n = n->p;
            } else {
                n = n->r;
                break;
            }
        }
    }
}

void rbtreeInOrderWalk(RBTree *t, rbtreeWalkHandler *handler)
{
    RBTreeNode *n = t->rt;
    RBTreeNode *child;
    while (n != t->nil) {
        while (n->l != t->nil) {
            n = n->l;
        }

        child = NULL;
        while (n != t->nil) {
            if (n->r == t->nil || child == n->r) {
                if (n->r == t->nil) {
                    handler(t, n);
                }
                child = n;
                n = n->p;
            } else {
                handler(t, n);
                n = n->r;
                break;
            }
        }
    }
}

void rbtreePostOrderWalk(RBTree *t, rbtreeWalkHandler *handler)
{
    RBTreeNode *n = t->rt;
    RBTreeNode *child;
    while (n != t->nil) {
        while (n->l != t->nil) {
            n = n->l;
        }

        child = NULL;
        while (n != t->nil) {
            if (n->r == t->nil || child == n->r) {
                handler(t, n);
                child = n;
                n = n->p;
            } else {
                n = n->r;
                break;
            }
        }
    }
}

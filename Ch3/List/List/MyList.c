//
//  MyList.c
//  List
//
//  Created by scorpiozj on 10/14/13.
//  Copyright (c) 2013 scorpiozj. All rights reserved.
//

#include <stdio.h>
#include "MyList.h"
#include <stdlib.h>

struct Node {
    ElementType Element;
    Position Next;
};

List MakeEmpty(List L);

int IsEmpty(List L)
{
    return (L->Next == NULL);
}

int IsLast(Position P, List L)
{
    return (P->Next == NULL);
}
Position Find(ElementType X, List L)
{
    Position pos = L->Next;
    while (pos != NULL)
    {
        if (pos->Element == X)
        {
            break;
        }
        pos = pos->Next;
    }
    
    return pos;
}
void Insert(ElementType X, List L, Position P)
{
    Position TempCell = malloc(sizeof(Position));
    if (TempCell != NULL)
    {
        TempCell->Element = X;
        TempCell->Next = P->Next;
        P->Next = TempCell;
    }
}
void DeleteList(List L);
Position FindPrevious(ElementType X, List L)
{
    Position p = L->Next;
    while (p != NULL && p->Element != X)
    {
        p = p->Next;
    }
    return p;
}
void Delete(ElementType X, List L)
{
    Position previous = FindPrevious(X, L);
    
    if (previous != NULL)
    {
        Position current = previous->Next;
        previous->Next = current->Next;
    }
}

Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrive(Position P);
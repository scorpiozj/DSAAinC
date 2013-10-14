//
//  MyList.h
//  List
//
//  Created by scorpiozj on 10/14/13.
//  Copyright (c) 2013 scorpiozj. All rights reserved.
//

#ifndef List_MyList_h
#define List_MyList_h
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

typedef int ElementType;


List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
void Delete(ElementType X, List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrive(Position P);

#endif

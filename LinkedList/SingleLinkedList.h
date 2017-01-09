#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode{
	ElementType Data;
	struct tagNode* NextNode;
} Node;

Node* SLL_CreateNode( ElementType NewData );
void SLL_DestroyNode( Node* _Node );

void SLL_AppendNode( Node** Head, Node* NewNode );
void SLL_InsertBefore( Node** Head, Node* Current, Node* NewNode );
void SLL_InsertAfter( Node* Current, Node* NewNode );
void SLL_InsertNewHead( Node** Head, Node* NewHead );

void SLL_RemoveNode( Node** Head, Node* Remove );
void SLL_DestroyAllNodes( Node* Head );

Node* SLL_GetNodeAt( Node* Head, int Location );
int SLL_GetNodeCount( Node* Head );

void SLL_PrintList( Node* Head );

int Test_SingleLinkedList();

#endif /* SINGLELINKEDLIST_H */
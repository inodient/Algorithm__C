#ifndef CIRCULARDOUBLYLINKEDLIST_H
#define CIRCULARDOUBLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode{
	ElementType Data;
	struct tagNode* PrevNode;
	struct tagNode* NextNode;
} Node;

Node* CDLL_CreateNode( ElementType NewNode );
void CDLL_DestroyNode( Node* _Node );

void CDLL_AppendNode( Node** Head, Node* NewNode );
void CDLL_InsertAfter( Node* Current, Node* NewNode );

void CDLL_RemoveNode( Node** Head, Node* Remove );

Node* CDLL_GetNodeAt( Node* Head, int Location );
int CDLL_GetNodeCount( Node* Head );

void CDLL_PrintNode( Node* _Node );
void CDLL_PrintList( Node* Head );

int Test_CircularDoublyLinkedList();

#endif /* CIRCULARDOUBLYLINKEDLIST_H */

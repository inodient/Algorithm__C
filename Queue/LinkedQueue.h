#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Graph/AdjacencyListGraph.h"

typedef Vertex* QueueElementType;

typedef struct tagNode{
	QueueElementType Data;
	struct tagNode* NextNode;
} Node;

typedef struct tagLinkedQueue{
	Node* Front;
	Node* Rear;
	int Count;
} LinkedQueue;

void LQ_CreateQueue( LinkedQueue** Queue );
void LQ_DestroyQueue( LinkedQueue* _Queue );

Node* LQ_CreateNode( QueueElementType NewData );
void LQ_DestroyNode( Node* _Node );

void LQ_Enqueue( LinkedQueue* Queue, Node* NewNode );
Node* LQ_Dequeue( LinkedQueue* Queue );

int LQ_IsEmpty( LinkedQueue* Queue );

int Test_LinkedQueue();

#endif /* LINKEDQUEUE_H */

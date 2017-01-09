#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode{
	ElementType Data;
} Node;

typedef struct tagCircularQueue{
	int Capacity;
	int Front;
	int Rear;
	Node* Nodes;
} CircularQueue;

void CQ_CreateQueue( CircularQueue** Queue, int Capacity );
void CQ_DestroyQueue( CircularQueue* _Queue );

void CQ_Enqueue( CircularQueue* Queue, ElementType NewData );
ElementType CQ_Dequeue( CircularQueue* Queue );

int CQ_GetSize( CircularQueue* Queue );
int CQ_IsEmpty( CircularQueue* Queue );
int CQ_IsFull( CircularQueue* Queue );

int Test_CircularQueue();

#endif /* CIRCULARQUEUE_H */

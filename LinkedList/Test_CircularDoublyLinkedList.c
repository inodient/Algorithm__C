/*
 * Test_CircularDoublyLinkedList.c
 *
 *  Created on: Oct 1, 2016
 *      Author: changhokang
 */

#include "CircularDoublyLinkedList.h"

int Test_CircularDoublyLinkedList(){
	int i = 0;
	int Count = 0;
	Node* List = NULL;
	Node* Current = NULL;
	Node* NewNode = NULL;

	printf( "Insert 0 to 5 ....\n" );
	for( i=0; i<5; i++ ){
		NewNode = CDLL_CreateNode( i );
		CDLL_AppendNode( &List, NewNode );
	}
	CDLL_PrintList( List );

	printf( "\nInserting 3000 After [2] ....\n" );
	NewNode = CDLL_CreateNode( 3000 );
	Current = CDLL_GetNodeAt( List, 2 );
	CDLL_InsertAfter( Current, NewNode );

	CDLL_PrintList( List );

	printf( "\nCheck whether Circular or not ....\n" );
	Count = CDLL_GetNodeCount( List );
	for( i=0; i<Count*2; i++ ){
		if( i == 0 ){
			Current = List;
		} else {
			Current = Current->NextNode;
		}

		printf( "List[%d] : %d\n", i, Current->Data );
	}

	printf( "\nDeleting List ....\n" );
	Count = CDLL_GetNodeCount( List );
	for( i=0; i<Count; i++ ){
		Current = CDLL_GetNodeAt( List, 0 );

		printf( "\n	Deleting Node which has %d\n", Current->Data );
		CDLL_RemoveNode( &List, Current );
		CDLL_DestroyNode( Current );
		CDLL_PrintList( List );
		printf( "\n" );
	}
	return 0;
}

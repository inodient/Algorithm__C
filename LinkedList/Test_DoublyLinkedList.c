#include "DoublyLinkedList.h"

int Test_DoublyLinkedList(){
	int i = 0;
	int Count = 0;
	Node* List = NULL;
	Node* NewNode = NULL;
	Node* Current = NULL;

	printf( "Inserting 0 to 4 at List....\n" );
	for( i=0; i<5; i++ ){
		NewNode = DLL_CreateNode( i );
		DLL_AppendNode( &List, NewNode );
	}
	DLL_PrintList( List );

	printf( "\nInserting 3000 at [3]....\n" );
	NewNode = DLL_CreateNode( 3000 );
	Current = DLL_GetNodeAt( List, 3 );

	DLL_InsertAfter( Current, NewNode );

	DLL_PrintList( List );

	printf( "\nDestroying List....\n" );
	Count = DLL_GetNodeCount( List );
	for( i=0; i<Count; i++ ){
		Current = DLL_GetNodeAt( List, Count-1-i );

		printf( "\n >>>> Destroying Node which has %d\n", Current->Data );
		DLL_RemoveNode( &List, Current );
		DLL_DestroyNode( Current );
		DLL_PrintList( List );
	}

	return 0;
}


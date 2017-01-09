#include "SingleLinkedList.h"

int Test_SingleLinkedList(){
	int i = 0;
	int Count = 0;
	Node* List = NULL;
	Node* NewNode = NULL;
	Node* Current = NULL;

	printf( "Inserting 0 to 4....\n" );
	for( i=0; i<5; i++ ){
		NewNode = SLL_CreateNode( i );
		SLL_AppendNode( &List, NewNode );
	}
	SLL_PrintList( List );

	printf( "\nInserting -1, -2 to Head....\n" );
	NewNode = SLL_CreateNode( -1 );
	SLL_InsertNewHead( &List, NewNode );

	NewNode = SLL_CreateNode( -2 );
	SLL_InsertNewHead( &List, NewNode );

	SLL_PrintList( List );

	printf( "\nInserting 3000 after [4]....\n" );
	Current = SLL_GetNodeAt( List, 4 );
	NewNode = SLL_CreateNode( 3000 );

	SLL_InsertAfter( Current, NewNode );

	SLL_PrintList( List );

	printf( "\nDestroying List....\n" );
	Count = SLL_GetNodeCount( List );

	for( i=0; i<Count; i++ ){
		Current = SLL_GetNodeAt( List, 0 );

		printf( "\n >>>>> Destroying Node which has %d\n", Current->Data );
		SLL_RemoveNode( &List, Current );
		SLL_DestroyNode( Current );

		SLL_PrintList( List );
	}

	return 0;
}

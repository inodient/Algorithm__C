#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagLCRSNode{
	struct tagLCRSNode* LeftChild;
	struct tagLCRSNode* RightSibling;
	ElementType Data;
} LCRSNode;




LCRSNode* LCRS_CreateNode( ElementType NewData );
void LCRS_DestroyNode( LCRSNode* _Node );
void LCRS_DestroyTree( LCRSNode* _Root );

void LCRS_AddChildNode( LCRSNode* Root, LCRSNode* Child );

void LCRS_PrintTree( LCRSNode* Root, int Depth );




LCRSNode* LCRS_CreateNode( ElementType NewData ){
	LCRSNode* NewNode = (LCRSNode*)malloc( sizeof(LCRSNode) );

	NewNode->LeftChild = NULL;
	NewNode->RightSibling = NULL;
	NewNode->Data = NewData;

	return NewNode;
}

void LCRS_DestroyNode( LCRSNode* _Node ){
	free( _Node );
}

void LCRS_DestroyTree( LCRSNode* _Root ){
	if( _Root->LeftChild != NULL ){
		LCRS_DestroyTree( _Root->LeftChild );
	}
	if( _Root->RightSibling != NULL ){
		LCRS_DestroyTree( _Root->RightSibling );
	}

	LCRS_DestroyNode( _Root );
}

void LCRS_AddChildNode( LCRSNode* Root, LCRSNode* Child ){
	if( Root->LeftChild == NULL ){
		Root->LeftChild = Child;
	} else{
		LCRSNode* CursorNode = Root->LeftChild;

		while( CursorNode->RightSibling != NULL ){
			CursorNode = CursorNode->RightSibling;
		}

		CursorNode->RightSibling = Child;
	}
}

void LCRS_PrintTree( LCRSNode* Root, int Depth ){
	int i = 0;
	for( i=0; i<Depth; i++ ){
		printf( "\t" );
	}

	printf( "%c\n", Root->Data );

	if( Root->LeftChild != NULL ){
		LCRS_PrintTree( Root->LeftChild, Depth+1 );
	}
	if( Root->RightSibling != NULL ){
		LCRS_PrintTree( Root->RightSibling, Depth );
	}
}




int Test_LCRSTree( void ){
	LCRSNode* Root = LCRS_CreateNode( 'A' );

	LCRSNode* B = LCRS_CreateNode( 'B' );
	LCRSNode* C = LCRS_CreateNode( 'C' );
	LCRSNode* D = LCRS_CreateNode( 'D' );
	LCRSNode* E = LCRS_CreateNode( 'E' );
	LCRSNode* F = LCRS_CreateNode( 'F' );
	LCRSNode* G = LCRS_CreateNode( 'G' );
	LCRSNode* H = LCRS_CreateNode( 'H' );
	LCRSNode* I = LCRS_CreateNode( 'I' );
	LCRSNode* J = LCRS_CreateNode( 'J' );
	LCRSNode* K = LCRS_CreateNode( 'K' );


	LCRS_AddChildNode( Root, B );
	LCRS_AddChildNode( B, C );
	LCRS_AddChildNode( B, D );
	LCRS_AddChildNode( D, E );
	LCRS_AddChildNode( D, F );

	LCRS_AddChildNode( Root, G );
	LCRS_AddChildNode( G, H );

	LCRS_AddChildNode( Root, I );
	LCRS_AddChildNode( I, J );
	LCRS_AddChildNode( J, K );

	LCRS_PrintTree( Root, 0 );

	LCRS_DestroyTree( Root );

	return 0;
}

//int main( void ){
//	Test_LCRSTree();
//	return 0;
//}

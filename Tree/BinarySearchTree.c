#include "BinarySearchTree.h"

BSTNode* BST_CreateNode( ElementType NewData ){
	BSTNode* NewNode = (BSTNode*)malloc( sizeof( BSTNode ) );
	
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = NewData;
	
	return NewNode;
}

void BST_DestroyNode( BSTNode* _Node ){
	free( _Node );
}

void BST_DestroyTree( BSTNode* _Root ){
	if( _Root == NULL ) return;
	
	BST_DestroyTree( _Root->Left );
	BST_DestroyTree( _Root->Right );
	
	BST_DestroyNode( _Root );
}

BSTNode* BST_SearchNode( BSTNode* Tree, ElementType Target ){
	if( Tree == NULL ) return NULL;
	
	if( Tree->Data == Target ){
		return Tree;
	} else if( Tree->Data > Target ){
		return BST_SearchNode( Tree->Left, Target );
	} else if( Tree->Data < Target ){
		return BST_SearchNode( Tree->Right, Target );
	}
	
	return NULL;
}

BSTNode* BST_SearchMinNode( BSTNode* Tree ){
	if( Tree == NULL ) return NULL;
	
	if( Tree->Left == NULL ){
		return Tree;
	} else {
		BST_SearchMinNode( Tree->Left );
	}
	
	return NULL;
}
	
void BST_InsertNode( BSTNode* Tree, BSTNode* Child ){
	if( Tree->Data < Child->Data ){
		if( Tree->Right == NULL ){
			Tree->Right = Child;
		} else{
			BST_InsertNode( Tree->Right, Child );
		}
	} else if( Tree->Data > Child->Data ){
		if( Tree->Left == NULL ){
			Tree->Left = Child;
		} else{
			BST_InsertNode( Tree->Left, Child );
		}
	}
}

BSTNode* BST_RemoveNode( BSTNode* Tree, BSTNode* Parent, ElementType Target ){
	BSTNode* Removed = NULL;
	
	if( Tree == NULL ){
		return NULL;
	}
	
	if( Tree->Data > Target ){
		Removed = BST_RemoveNode( Tree->Left, Tree, Target );
	} else if( Tree->Data < Target ){
		Removed = BST_RemoveNode( Tree->Right, Tree, Target );
	} else {
		Removed = Tree;
		
		if( Tree->Left == NULL && Tree->Right == NULL ){
			if( Parent->Left == Tree ){
				Parent->Left = NULL;
			} else{
				Parent->Right = NULL;
			}
		} else{
			if( Tree->Left != NULL && Tree->Right != NULL ){
				BSTNode* MinNode = BST_SearchMinNode( Tree->Right );
				MinNode = BST_RemoveNode( Tree, NULL, MinNode->Data );
				Tree->Data = MinNode->Data;
			} else{
				BSTNode* Temp = NULL;
				if( Tree->Left != NULL ){
					Temp = Tree->Left;
				} else{
					Temp = Tree->Right;
				}
				
				if( Parent->Left == Tree ){
					Parent->Left = Temp;
				} else{
					Parent->Right = Temp;
				}
			}
		}
	}
	
	return Removed;
}

void BST_InorderPrintTree( BSTNode* Root ){
	if( Root == NULL ) return;
	
	BST_InorderPrintTree( Root->Left );
	printf( "%d ", Root->Data );
	BST_InorderPrintTree( Root->Right );
}

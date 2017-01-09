//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//void Swap( int* A, int* B ){
//	int Temp = *A;
//	*A = *B;
//	*B = Temp;
//}
//
//void BubbleSort( int DataSet[], int Length ){
//	int i = 0;
//	int j = 0;
//
//	for( i=0; i<Length-1; i++ ){
//		for( j=0; j<Length-(i+1); j++ ){
//			if( DataSet[j] > DataSet[j+1] ){
//				Swap( &DataSet[j], &DataSet[j+1] );
//			}
//		}
//
////		<< Algorithm Performance Analyze >>
////		printf( "%d th : ", i );
////		for( int k=0; k<6; k++ ){
////			printf( "%d	", DataSet[k] );
////		}
////		printf( "\n" );
//	}
//}
//
//void InsertionSort( int DataSet[], int Length ){
//	int i = 0;
//	int j = 0;
//	int Value = 0;
//
//	for( i=1; i<Length; i++ ){
//		if( DataSet[i-1] <= DataSet[i] )
//			continue;
//
//		Value = DataSet[i];
//
//		for( j=0; j<i; j++ ){
//			if( DataSet[j] > Value ){
//				memmove( &DataSet[j+1], &DataSet[j], sizeof( DataSet[0] ) * ( i - j ) );
//				DataSet[j] = Value;
//				break;
//			}
//		}
//
////		<< Algorithm Performance Anaylze >>
////		printf( "%d th : ", i );
////		for( int k=0; k<6; k++ ){
////			printf( "%d	", DataSet[k] );
////		}
////		printf( "\n" );
//	}
//}
//
//int Partition( int DataSet[], int Left, int Right ){
//	int First = Left;
//	int Pivot = DataSet[First];
//
//	++Left;
//
//	while( Left <= Right ){
//		while( DataSet[Left] <= Pivot && Left < Right ){
//			++Left;
//		}
//		while( DataSet[Right] > Pivot && Left <= Right ){
//			--Right;
//		}
//
//		if( Left < Right ){
//			Swap( &DataSet[Left], &DataSet[Right] );
//
//			for( int k=0; k<13; k++ ){
//				printf( "%d	", DataSet[k] );
//			}
//			printf( "\n" );
//
//		} else{
//			break;
//		}
//	}
//
//	Swap( &DataSet[First], &DataSet[Right] );
//	for( int k=0; k<13; k++ ){
//		printf( "%d	", DataSet[k] );
//	}
//	printf( "\n" );
//
//	return Right;
//}
//
//void QuickSort( int DataSet[], int Left, int Right ){
//	if( Left < Right ){
//		int Index = Partition( DataSet, Left, Right );
//
//		QuickSort( DataSet, Left, Index - 1 );
//		QuickSort( DataSet, Index + 1, Right );
//	}
//}
//
//int main( void ){
//	int i = 0;
//	//int DataSet[] = { 5, 1, 6, 4, 2, 3 };
//	int DataSet[] = { 8, 3, 1, 2, 2, 2, 1, 0, 9, 3, 3, 1, 4 };
//	int Length = sizeof DataSet / sizeof DataSet[0];
//
//	//BubbleSort( DataSet, Length );
//	//InsertionSort( DataSet, Length );
//	QuickSort( DataSet, 0, Length-1 );
//
//	for( i=0; i<Length; i++ ){
//		printf( "%d	", DataSet[i] );
//	}
//
//	printf( "\n" );
//
//	return 0;
//}

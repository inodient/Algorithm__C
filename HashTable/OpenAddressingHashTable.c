#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* KeyType;
typedef char* ValueType;

enum ElementStatus {
	EMPTY = 0,
	OCCUPIED = 1
};

typedef struct tagElementType{
	KeyType Key;
	ValueType Value;
	enum ElementStatus Status;
} ElementType;

typedef struct tagHashTable{
	int OccupiedCount;
	int TableSize;
	ElementType* Table;
} HashTable;




HashTable* OAHT_CreateHashTable( int TableSize );
void OAHT_DestroyHashTable( HashTable* _HT );
void OAHT_ClearElement( ElementType* Element );

void OAHT_Set( HashTable** HT, KeyType Key, ValueType Value );
ValueType OAHT_Get( HashTable* HT, KeyType Key );

int OAHT_Hash( KeyType Key, int TableSize );
int OAHT_Hash2( KeyType Key, int TableSize );

void OAHT_Rehash( HashTable** HT );




HashTable* OAHT_CreateHashTable( int TableSize ){
	HashTable* NewHashTable = (HashTable*)malloc( sizeof( HashTable ) );

	NewHashTable->OccupiedCount = 0;
	NewHashTable->TableSize = TableSize;
	NewHashTable->Table = (ElementType*)malloc( sizeof( ElementType ) * ( NewHashTable->TableSize ) );
	memset( NewHashTable->Table, 0, sizeof( ElementType ) * ( NewHashTable->TableSize ) );

	return NewHashTable;
}

void OAHT_DestroyHashTable( HashTable* _HT ){
	int i = 0;
	for( i=0; i<_HT->TableSize; i++ ){
		if( _HT->Table[i].Status != EMPTY ){
			OAHT_ClearElement( &(_HT->Table[i]) );
		}
	}

	free( _HT->Table );
	free( _HT );
}

void OAHT_ClearElement( ElementType* Element ){
	if( Element == NULL ) return;

	free( Element->Key );
	free( Element->Value );
}

void OAHT_Set( HashTable** HT, KeyType Key, ValueType Value ){
	double Usage;


	Usage = (double)(*HT)->OccupiedCount / (*HT)->TableSize;

	printf( "Usage : %f\n", Usage );
	if( Usage > 0.5 ){
		printf( "Necessary To Rehash....\n" );
		OAHT_Rehash( HT );
	}

	int Address = 0;
	int StepSize = 0;

	Address = OAHT_Hash( Key, (*HT)->TableSize );
	StepSize = OAHT_Hash2( Key, (*HT)->TableSize );

	while( (*HT)->Table[Address].Status != EMPTY && strcmp( (*HT)->Table[Address].Key, Key ) != 0 ){
		printf( "\nCollision occured : Key (%s), Address (%d)\n\n", Key, Address );

		Address = ( Address + StepSize ) % (*HT)->TableSize;
	}

	(*HT)->Table[Address].Key = (char*)malloc( sizeof( char ) * ( strlen( Key ) + 1 ) );
	strcpy( (*HT)->Table[Address].Key, Key );

	(*HT)->Table[Address].Value = (char*)malloc( sizeof( char ) * ( strlen( Value ) + 1 ) );
	strcpy( (*HT)->Table[Address].Value, Value );

	(*HT)->Table[Address].Status = OCCUPIED;

	(*HT)->OccupiedCount++;

	printf( "Key (%s) is entered at Address (%d)\n", Key, Address );
}

ValueType OAHT_Get( HashTable* HT, KeyType Key ){
	int Address, StepSize;

	Address = OAHT_Hash( Key, HT->TableSize );
	StepSize = OAHT_Hash2( Key, HT->TableSize );

	while( HT->Table[Address].Status == OCCUPIED ){
		if( strcmp( HT->Table[Address].Key, Key ) == 0 ){
			return HT->Table[Address].Value;
		}

		Address = ( Address + StepSize ) % HT->TableSize;
	}

	return NULL;
}

int OAHT_Hash( KeyType Key, int TableSize ){
	int i = 0;
	int HashValue = 0;

	for( i=0; i<strlen(Key); i++ ){
		HashValue = (HashValue<<2) + Key[i];
	}

	HashValue = HashValue % TableSize;

	return HashValue;

	// int i = 0;
	// int HashValue = 0;

	// for( i=0; i<strlen(Key); i++ ){
	// 	HashValue = (HashValue<<2) + Key[i];
	// }

	// HashValue = HashValue % TableSize;

	// return HashValue;

}

// int OAHT_Hash2( KeyType Key, int TableSize ){
// 	int i = 0;
// 	int HashValue;

// 	for( i=0; i<strlen(Key); i++ ){
// 		HashValue = (HashValue<<2) + Key[i];
// 	}

// 	HashValue = ( HashValue % ( TableSize - 3 ) ) + 1;

// 	return HashValue;
// }

int OAHT_Hash2( KeyType Key, int TableSize ){
	int i = 0;
	int HashValue = 0;

	for( i=0; i<strlen(Key); i++ ){
		HashValue = (HashValue<<2) + Key[i];
	}

	HashValue = HashValue % (TableSize - 3);

	return HashValue + 1;
}


void OAHT_Rehash( HashTable** HT ){
	int i = 0;
	ElementType* OldTable = (*HT)->Table;

	HashTable* NewHashTable = OAHT_CreateHashTable( (*HT)->TableSize * 2 );

	printf( "\nRehashed. New Table Size is : %d\n\n", NewHashTable->TableSize );

	for( i=0; i<(*HT)->TableSize; i++ ){
		if( OldTable[i].Status == OCCUPIED ){
			OAHT_Set( &NewHashTable, OldTable[i].Key, OldTable[i].Value );
		}
	}

	OAHT_DestroyHashTable( *HT );

	(*HT) = NewHashTable;
}




int Test_OAHT( void ){
	HashTable* HT = OAHT_CreateHashTable( 11 );

	OAHT_Set( &HT, "MSFT", "Microsoft Corporation" );
	OAHT_Set( &HT, "JAVA", "Sun Microsystems" );
	OAHT_Set( &HT, "REDH", "Red Hat Linux" );
	OAHT_Set( &HT, "APAC", "Apache Org" );
	OAHT_Set( &HT, "ZYMZZ", "Unisys Ops Check" );
	OAHT_Set( &HT, "IBM", "IBM Ltd." );
	OAHT_Set( &HT, "ORCL", "Oracle Corporation" );
	OAHT_Set( &HT, "CSCO", "Cisco Systems, Inc." );
	OAHT_Set( &HT, "GOOG", "Google Inc." );
	OAHT_Set( &HT, "YHOO", "Yahoo! Inc." );
	OAHT_Set( &HT, "NOVL", "Novell, Inc." );

	printf( "\n" );
	printf( "Key:%s, Value:%s\n", "MSFT", OAHT_Get( HT, "MSFT" ) );
	printf( "Key:%s, Value:%s\n", "JAVA", OAHT_Get( HT, "JAVA" ) );
	printf( "Key:%s, Value:%s\n", "REDH", OAHT_Get( HT, "REDH" ) );
	printf( "Key:%s, Value:%s\n", "APAC", OAHT_Get( HT, "APAC" ) );
	printf( "Key:%s, Value:%s\n", "ZYMZZ", OAHT_Get( HT, "ZYMZZ" ) );
	printf( "Key:%s, Value:%s\n", "IBM", OAHT_Get( HT, "IBM" ) );
	printf( "Key:%s, Value:%s\n", "ORCL", OAHT_Get( HT, "ORCL" ) );
	printf( "Key:%s, Value:%s\n", "CSCO", OAHT_Get( HT, "CSCO" ) );
	printf( "Key:%s, Value:%s\n", "GOOG", OAHT_Get( HT, "GOOG" ) );
	printf( "Key:%s, Value:%s\n", "YHOO", OAHT_Get( HT, "YHOO" ) );
	printf( "Key:%s, Value:%s\n", "NOVL", OAHT_Get( HT, "NOVL" ) );

	OAHT_DestroyHashTable( HT );

	return 0;
}

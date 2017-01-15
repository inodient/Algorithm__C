#include <stdio.h>
#include <stdlib.h>

typedef char* KeyType;
typedef int ValueType;

typedef struct tagNode{
	KeyType Key;
	ValueType Value;
} Node;

typedef struct tagHashTable{
	int TableSize;
	Node* Table;
} HashTable;




HashTable* SHT_CreateHashTable( int TableSize );
void SHT_DestroyHashTable( HashTable* _HT );

void SHT_Set( HashTable* HT, KeyType Key, ValueType Value );
ValueType SHT_Get( HashTable* HT, KeyType Key );

int SHT_Hash( KeyType Key, int HashTable );




HashTable* SHT_CreateHashTable( int TableSize ){
	HashTable* NewHashTable = (HashTable*)malloc( sizeof( HashTable ) );

	NewHashTable->TableSize = TableSize;
	NewHashTable->Table = (Node*)malloc( sizeof( Node ) * ( NewHashTable->TableSize ) );

	return NewHashTable;
}

void SHT_DestroyHashTable( HashTable* _HT ){
	free( _HT->Table );
	free( _HT );
}

void SHT_Set( HashTable* HT, KeyType Key, ValueType Value ){
	int Address = SHT_Hash( Key, HT->TableSize );

	HT->Table[Address].Key = Key;
	HT->Table[Address].Value = Value;
}

ValueType SHT_Get( HashTable* HT, KeyType Key ){
	int Address = SHT_Hash( Key, HT->TableSize );

	return HT->Table[Address].Value;
}

int SHT_Hash( KeyType Key, int TableSize ){
	int i = 0;
	int HashValue = 0;

	unsigned long Len = strlen( Key );

	for( i=0; i<Len; i++ ){
		HashValue = (HashValue << 3) + Key[i];
	}

	HashValue %= TableSize;

	return HashValue;

	//return Key % TableSize;
}




int Test_SHT( void ){

	HashTable* HT = SHT_CreateHashTable( 193 );

	SHT_Set( HT, "table", 32114 );
	SHT_Set( HT, "book", 514 );
	SHT_Set( HT, "bag", 8917 );
	SHT_Set( HT, "office", 286 );

	printf( "Key : %s, Value %d\n", "table", SHT_Get( HT, "table" ) );
	printf( "Key : %s, Value %d\n", "book", SHT_Get( HT, "book" ) );
	printf( "Key : %s, Value %d\n", "bag", SHT_Get( HT, "bag" ) );
	printf( "Key : %s, Value %d\n", "office", SHT_Get( HT, "office" ) );

	SHT_DestroyHashTable( HT );

	return 0;
}

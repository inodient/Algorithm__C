#ifndef BOYERMOORE_H
#define BOYERMOORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 512

int BoyerMoore( char* Text, int TextSize, int Start, char* Pattern, int PatternSize );

void BuildGST( char* Pattern, int PatternSize, int* Suffix, int* GST );
void BuildBCT( char* Pattern, int PatternSize, int* BST );
int Max( int A, int B );

#endif

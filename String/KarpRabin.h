#ifndef KARPRABIN_H
#define KARPRABIN_H

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MSX_BUFFER 512

int KarpRabin( char* Text, int TextSize, int Start, char* Pattern, int PatternSize );

int Hash( char* String, int Size );
int ReHash( char* String, int Start, int Size, int HashPrev, int Coefficient );

#endif

/* This assignment originated at UC Riverside.*/
 

/************************************************
Hash Function.

How does it make it better:

> Division method is used in this hash function.

> Use of the bitwise XOR causes scrambling of the bits and 
  better distribution of the keys fewer splits.

> Due to use of bitwise XOR which causes less wastage of bits.

> It is quick and preserves uniform distribution.

> Shift operator causes hash value not exceed the size.

> Causes less collision.

> Mod of value is taken which returns the index into which the string is to be placed into the hashtable.

************************************************/
#include <string>
#include "hash.h"

using namespace std;

int 
Hash::hf ( string ins ) {

	unsigned long hash=1315423911;
	for(unsigned int i =0;i< ins.length();i++)
	{
		hash ^=(hash<<5)+(hash>>2)+ins[i];

	}

	return hash % HASH_TABLE_SIZE;
}


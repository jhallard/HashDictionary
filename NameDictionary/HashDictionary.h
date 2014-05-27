#ifndef HASH_DICTIONARY_H
#define HASH_DICTIONARY_H
/*  
*	@Author John H Allard. Written for CSIS 212 Advanced Data Structures at GCC, May 27th, 2014.
*	HashDictionary.h - Declaration of the HashDictionary class. This class represents a dictionary that uses hashing with chaining to store the items.
*	The dictionary size is defined as a constant below, which is because of a bug that I could not resolve involving the compiler rejecting a one arg constructor
*	which would have been the size of the dictionary that the user wants. 
*/
#include "DictionaryNode.h"
#include <vector>
#include <iostream>

template <class keyType, class itemType> 
class HashDictionary
{
private:
	static const int dictionarySize = 100;
	DictionaryNode<keyType, itemType> * dictionary[dictionarySize];
	int numberOfEntries;
	int hashEntry(keyType);

public:

	explicit HashDictionary();

	bool isEmpty();

	int getNumberOfItems();

	int getDictionarySize();

	bool add(keyType, itemType);

	bool remove(keyType);

	bool contains(keyType);

	itemType getItem(keyType);

	void traverse(void visit(itemType&));


};

#include "HashDictionary.cpp"

#endif
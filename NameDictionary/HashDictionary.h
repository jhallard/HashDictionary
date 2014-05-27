#ifndef HASH_DICTIONARY_H
#define HASH_DICTIONARY_H

#include "DictionaryNode.h"

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
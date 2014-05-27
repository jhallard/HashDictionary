#ifndef HASH_DICTIONARY_H
#define HASH_DICTIOINARY_H

#include "DictionaryNode.h"

template <class keyType, class itemType> 
class HashDictionary
{
private:
	DictionaryNode * dictionary;
	int dictionarySize, numberOfEntries;

	bool hashEntry(DictionaryNode);

public:

	bool isEmpty();

	int getNumberOfItems();

	bool add(keyType, itemType);

	bool remove(keyType);

	bool contains(keyType);

	itemType getItem(keyType);

	void traverse(void visit(itemType&));


};


#endif
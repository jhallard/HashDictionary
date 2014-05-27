#ifndef HASH_DICTIONARY_CPP
#define HASH_DICTIONARY_CPP

#include "HashDictionary.h"

template <class keyType, class itemType>
HashDictionary<keyType, itemType>::HashDictionary()
{
	//this->dictionarySize = size;
	this->numberOfEntries = 0;
	for(int i = 0; i < dictionarySize; i++)
	{
		this->dictionary[i] = nullptr;
	}
}

template <class keyType, class itemType>
bool HashDictionary<keyType, itemType>::isEmpty()
{
	return(!this->numberOfEntries);
}

template <class keyType, class itemType>
int HashDictionary<keyType, itemType>::getDictionarySize()
{
	return this->dictionarySize;
}

template <class keyType, class itemType>
int HashDictionary<keyType, itemType>::getNumberOfItems()
{
	return this->numberOfEntries;
}


template <class keyType, class itemType>
bool HashDictionary<keyType, itemType>::add(keyType key, itemType item)
{
	DictionaryNode<keyType, itemType> * newNode = new DictionaryNode<keyType, itemType>(key, item);
	DictionaryNode<keyType, itemType> * ptr;
	int index = hashEntry(newNode->getKey());

	ptr = this->dictionary[index];

	if(ptr == nullptr)
	{
		dictionary[index] = newNode;
		this->numberOfEntries++;
		return true;
	}
	else
	{
		while(ptr->getNext() != nullptr)
		{
			ptr = ptr->getNext();
		}
		ptr = newNode;
		this->numberOfEntries++;
	}

	return true;
}

template <class keyType, class itemType>
int HashDictionary<keyType, itemType>::hashEntry(keyType key)
{
	return (key%15)*(key%1213)%this->dictionarySize;
}


template <class keyType, class itemType>
bool  HashDictionary<keyType, itemType>::remove(keyType)
{

	return true;
}

template <class keyType, class itemType>
bool HashDictionary<keyType, itemType>::contains(keyType key)
{
	int index = hashEntry(key);

	DictionaryNode<keyType, itemType> * nodeptr = nullptr;
	nodeptr = this->dictionary[index];

	if(nodeptr == nullptr)
		return false;

	if(key == nodeptr->getKey())
		return true;

	while(nodeptr->getNext() != nullptr)
	{
		if(nodeptr->getKey() == key)
			return true;

		nodeptr = nodeptr->getNext();
	}

	return false;
	
}

template <class keyType, class itemType>
itemType HashDictionary<keyType, itemType>::getItem(keyType)
{
	return itemType();
}

template <class keyType, class itemType>
void HashDictionary<keyType, itemType>::traverse(void visit(itemType&))
{

}

#endif
#ifndef DICTIONARY_NODE_CPP
#define DICTIONARY_NODE_CPP

#include "DictionaryNode.h"

template <class keyType, class itemType>
DictionaryNode<keyType, itemType>::DictionaryNode(keyType key, itemType item)
{
	this->key = key;
	this->item = item;
	this->next = nullptr;
}

template <class keyType, class itemType>
DictionaryNode<keyType, itemType>::DictionaryNode()
{
	this->key = 0;
	this->item = 0;
	this->next = nullptr;
}

template <class keyType, class itemType>
void DictionaryNode<keyType, itemType>::setKey(keyType key)
{
	this->key = key;
}

template <class keyType, class itemType>
keyType DictionaryNode<keyType, itemType>::getKey()
{
	return this->key;
}

template <class keyType, class itemType>
void DictionaryNode<keyType, itemType>::setItem(itemType)
{
	this->item = item;
}

template <class keyType, class itemType>
itemType DictionaryNode<keyType, itemType>::getItem()
{
	return this->item;
}

template <class keyType, class itemType>
DictionaryNode<keyType, itemType> * DictionaryNode<keyType, itemType>::getNext()
{
	return this->next;
}

template <class keyType, class itemType>
void DictionaryNode<keyType, itemType>::setNext(DictionaryNode<keyType, itemType> * nextEntry)
{
	this->next = nextEntry;
}

#endif
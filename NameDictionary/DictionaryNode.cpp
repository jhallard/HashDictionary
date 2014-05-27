#include "DictionaryNode.h"

template <class keyType, class itemType>
DictionaryNode::DictionaryNode(keyType key, itemType item)
{
	this->key = key;
	this->item = item;
}

template <class keyType, class itemType>
void DictionaryNode::setKey(keyType key)
{
	this->key = key;
}

template <class keyType, class itemType>
keyType DictionaryNode::getKey()
{
	return this->key;
}

template <class keyType, class itemType>
void DictionaryNode::setItem(itemType)
{
	this->item = item;
}

template <class keyType, class itemType>
itemType DictionaryNode::getItem()
{
	return this->item;
}

template <class keyType, class itemType>
DictionaryNode * DictionaryNode::getNext()
{
	return this->next;
}

template <class keyType, class itemType>
void DictionaryNode::setNext(DictionaryNode * nextEntry)
{
	this->next = nextEntry;
}
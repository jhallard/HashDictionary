#ifndef DICTIONARY_NODE_H
#define DICTIONARY_NODE_H

template <class keyType, class itemType>
class DictionaryNode
{
private:
	keyType key;
	itemType item;
	DictionaryNode * next;

public:
	DictionaryNode(keyType, itemType);

	void setKey(keyType);
	keyType getKey();

	void setItem(itemType);
	itemType getItem();

	DictionaryNode * getNext();
	void setNext(DictionaryNode *);

};

#endif

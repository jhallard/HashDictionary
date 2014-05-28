#ifndef DICTIONARY_NODE_H
#define DICTIONARY_NODE_H

template <class keyType, class itemType>
class DictionaryNode
{
private:
    keyType key;
    itemType item;
    DictionaryNode<keyType, itemType> * next;

public:
    DictionaryNode(keyType, itemType);
    DictionaryNode();

    void setKey(keyType);
    keyType getKey();

    void setItem(itemType);
    itemType getItem();

    DictionaryNode<keyType, itemType> * getNext();
    void setNext(DictionaryNode<keyType, itemType> *);

};

#include "DictionaryNode.cpp"

#endif

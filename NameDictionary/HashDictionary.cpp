/*  
*	@Author John H Allard. Written for CSIS 212 Advanced Data Structures at GCC, May 27th, 2014.
*	HashDictionary.cpp - Implementation of class HashDictionary. This class is a dictionary that uses hashing with chaining to store data.
*	It is a relatively trivial implementation but it is fully template compatible, just tell it what type the keys are and what type the items are and you're good to go
*	One thing that is kind of bad and needs to eb fixed is that I couldn't get the program to let me make a constructor that takes in just one int to be the size of the 
*	dictionary, so I had to declare a constant to do this.
*/
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
		ptr = ptr->getNext();
		while(ptr != nullptr)
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
bool  HashDictionary<keyType, itemType>::remove(keyType key)
{
	int index = hashEntry(key);
	DictionaryNode<keyType, itemType> * nodeptr = nullptr;
	nodeptr = dictionary[index];

	if(nodeptr == nullptr)
		return false;
	else if(key == nodeptr->getKey())
	{
		dictionary[index] = dictionary[index]->getNext();
		this->numberOfEntries--;
		return true;
	}
	else
	{
		while(nodeptr->getNext() != nullptr)
		{
			if(nodeptr->getNext()->getKey() == key)
			{
				nodeptr = nodeptr->getNext()->getNext();
				this->numberOfEntries--;
				return true;
			}
			nodeptr = nodeptr->getNext();
		}
		return false;
	}
	return false;
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
void HashDictionary<keyType, itemType>::traverse(void visit(DictionaryNode<keyType, itemType> &))
{
	DictionaryNode<keyType, itemType> * nodeptr = nullptr;
	nodeptr = dictionary[0];

	int total = 0;
	double average = 0;
	for(int i = 0; i < this->dictionarySize; i++)
	{
		if(dictionary[i] != nullptr)
		{
			nodeptr = dictionary[i];
			std::cout << "Slot #" << i; visit(*nodeptr);
			total += (int)nodeptr->getKey();

			while(nodeptr->getNext() != nullptr)
			{
				nodeptr = nodeptr->getNext();
				std::cout << "Slot #" << i; visit(*nodeptr);
				total += (int)nodeptr->getKey();
			}
		}
	}

	average = (double)total/this->getNumberOfItems();
	double x = (double)dictionarySize;
	double alpha = (double)(this->getNumberOfItems()/x);


	std::cout << "\n\n Average Age = " << average << "\n\n" << "alpha = " << alpha << "\n\n";

}

#endif
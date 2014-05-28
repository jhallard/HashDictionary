/*  
*    @Author John H Allard. Written for CSIS 212 Advanced Data Structures at GCC, May 27th, 2014.
*    HashDictionary.cpp - Implementation of class HashDictionary. This class is a dictionary that uses hashing with chaining to store data.
*    It is a relatively trivial implementation but it is fully template compatible, just tell it what type the keys are and what type the items are and you're good to go
*    One thing that is kind of bad and needs to eb fixed is that I couldn't get the program to let me make a constructor that takes in just one int to be the size of the 
*    dictionary, so I had to declare a constant to do this.
*    ONLINE REPOSITORY -     http://github.com/jhallard/HashDictionary
*/
#ifndef HASH_DICTIONARY_CPP
#define HASH_DICTIONARY_CPP

#include "HashDictionary.h"

// @Constructor
// @param - Size of the hash table in slots, more than this number of items can be added but it means that there
//			will definitely be collisions occuring. This constructor dynamically allocated the map using the @param size.
template <class keyType, class itemType>
HashDictionary<keyType, itemType>::HashDictionary(int size)
{
    this->dictionarySize = size;
    this->numberOfEntries = 0;
	this->dictionary = new DictionaryNode<keyType, itemType>*[dictionarySize];
    for(int i = 0; i < dictionarySize; i++)
    {
        this->dictionary[i] = nullptr;
    }
}

// @Destructor
// Clean up the dynamically allocated memory in @field dictionary;
template <class keyType, class itemType>
HashDictionary<keyType, itemType>::~HashDictionary()
{
	delete [] dictionary;
}

// Returns true if the dictionary is empty of entries
template <class keyType, class itemType>
bool HashDictionary<keyType, itemType>::isEmpty()
{
    return(!this->numberOfEntries);
}

// returns the size of the dictionary, as in the number of slots available, NOT the number of items the dictionary has
template <class keyType, class itemType>
int HashDictionary<keyType, itemType>::getDictionarySize()
{
    return this->dictionarySize;
}

// This gets the number of entries inside the dictionary at the time the function is called
template <class keyType, class itemType>
int HashDictionary<keyType, itemType>::getNumberOfItems()
{
    return this->numberOfEntries;
}

// Add an entry into the hashmap. 
// @Param key - the key of the entry, to be hashed to determine the index.
// @Param item - the item (value) to be inserted into the hashmap at the hashed index
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
        ptr->setNext(newNode);
        this->numberOfEntries++;
    }

    return true;
}

// Hash the key to form an index based on the size of the dictionary (determine by @field dictionarySize)
// We use the std::Hash<int> function to hash it to an interger and then modulo by the size of the dictionary.
// @Param key - the key to be hashed, can be of any type that the std::Hash function accepts.
template <class keyType, class itemType>
int HashDictionary<keyType, itemType>::hashEntry(keyType key)
{
    std::hash<keyType> hash_fn;
    std::size_t str_hash = hash_fn(key);
	str_hash = str_hash%this->dictionarySize;

	return str_hash;
}

// Remove an item from the dictionary at index @Param key. 
// Pass in the key to try and identify where the item would be, if we reach a nullptr then we know
// we have not found the item in question. Returns true if it found and removed the item and false otherwise
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

// Query the hashmap to see if it contains the item. Call this function before you call getItem() so
// you can make sure that the item you are looking for is in the hashmap before trying to pull it out.
// Returns true if it can find the item and false otherwise.
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

// This function throws std::logic_error if an item with key @Param key does not exist.
// Otherwise it returns the value of the item associated with @Param key.
template <class keyType, class itemType>
itemType HashDictionary<keyType, itemType>::getItem(keyType key)
{
    int index = hashEntry(key);

    DictionaryNode<keyType, itemType> * nodeptr = nullptr;
    nodeptr = this->dictionary[index];

    if(nodeptr == nullptr)
        throw std::logic_error("Item Does not Exist");

    if(key == nodeptr->getKey())
        return nodeptr->getItem();

    while(nodeptr->getNext() != nullptr)
    {
        if(nodeptr->getKey() == key)
			return nodeptr->getItem();

        nodeptr = nodeptr->getNext();
    }

    throw std::logic_error("Item Does not Exist");
}

// traverse the map in order (ascending the slots of the hashmap and if a slot has chaining, then traverse the chain in order before
// moving on to the next slot. On each slot it calls the @Param visit() function, which is a function that the user defines to either print out the map
// or store the argument in different container.
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
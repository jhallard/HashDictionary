#include <iostream>
#include <string>
#include <fstream>

#include "HashDictionary.h"
#include "DictionaryNode.h"

using namespace std;

template <class keyType, class itemType>
void visit(DictionaryNode<keyType, itemType> & name)
{
    cout << "  Age : " << name.getKey() << "    --   Name : " << name.getItem() << "\n\n";
}

template <class keyType, class itemType>
void fileToDictionary(HashDictionary<keyType, itemType> &, string filename);

int main()
{
    //HashDictionary<int, char> * dic = new HashDictionary<int, char>();
    HashDictionary<int, string> dict;

    int menuop = -1;

    while(menuop != 0)
    {
        cout << "Please Choose One of the Following Options\n\n";
        cout << "1.) print hash table\n";
        cout << "2.) retrieve hash item\n";
        cout << "3.) delete item\n";
        cout << "4.) read names from file\n";
        cout << "0.) quit\n\n";

        cin >> menuop;
        int key = 0;
        switch(menuop)
        {
            case(1):
                system("cls");
                void (*fptr)(DictionaryNode<int, string> &);
                fptr = visit;
                dict.traverse(fptr);    
                system("pause");
                system("cls");
            break;

            case(2):
                cout << "Please enter the key to the item you want to retrieve\n";
                cin >> key;

                if(dict.contains(key))
                {
                    string item = dict.getItem(key);
                    cout << "Item Located in Map, Key #" << key << " :: Item " << item << "\n\n";
                }
                else
                    cout << "\n\nItem not found in dictionary\n\n";
            break;


            case(3):
                cout << "Please enter the key to the item you want to delete\n";
                cin >> key;
                if(dict.remove(key))
                {
                    cout << "\n\nItem with key #" << key << " has been removed\n\n";
                }
                else
                    cout << "\n\nItem not found in dictionary\n\n";
            break;


            case(4):
                string name;
                cout << "Please enter the name of the file to read from\n";
                cin >> name;
                fileToDictionary(dict, name);
            break;
        }// end switch

    }// end main menu while loop
    

    system("pause");
}


template <class keyType, class itemType>
void fileToDictionary(HashDictionary<keyType, itemType>  &dic, string filename)
{
    ifstream infile;
    infile.open(filename);
    std::vector<std::string> names;
    while(!infile.eof()) // To get you all the lines.
    {
        string str;
        char age[3];
        int numage = 0;
        int index = 0;
        getline(infile,str); // Saves the line in STRING.

        while(index < 3 && str[index] != ' ')
        {
            age[index] = str[index];
            index++;
        }

        while(str[index] == ' ')
        {
            index++;
        }

        str = str.substr(index, str.size());
        numage = atoi(age);

        dic.add(numage, str);
    }
    infile.close();

}




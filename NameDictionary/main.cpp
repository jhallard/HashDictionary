#include <iostream>

#include "HashDictionary.h"
#include "DictionaryNode.h"

using namespace std;

int main()
{
	//HashDictionary<int, char> * dic = new HashDictionary<int, char>();
	HashDictionary<int, char> dict;
	dict.add(21,'a');
	dict.add(23, 'b');
	dict.add(24,'g');

	if(dict.contains(21))
		cout << "wohoo!";
	if(dict.contains(22))
		cout << "noooo!";
	if(dict.contains(23))
		cout << "wohccc!";
	if(dict.contains(24))
		cout << "wohoo!";
	system("pause");
}
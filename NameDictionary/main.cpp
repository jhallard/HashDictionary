#include <iostream>
#include <string>

#include "HashDictionary.h"
#include "DictionaryNode.h"

using namespace std;

void visit(string & name)
{
	static int count = 1;
	cout << count << " : " << name << endl;
	count++;
}

int main()
{
	//HashDictionary<int, char> * dic = new HashDictionary<int, char>();
	HashDictionary<int, string> dict;
	dict.add(21,"abc");
	dict.add(23, "def");
	dict.add(24,"gett");


	void (*fptr)(string&);
	fptr = visit;
	dict.traverse(fptr);	

	system("pause");
}
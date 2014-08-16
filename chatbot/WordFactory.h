#pragma once
//#include "Dictionary.h"
#include <string>
#include <hash_map>
#include "Word.h"

class WordFactory
{
public:
	WordFactory();
	~WordFactory();

	pair<string,Word*> MakeWord(const string& _type,hash_map<string,string>& _wordState);
	pair<string,Word*> MakeWord(string& _str);

private:

};
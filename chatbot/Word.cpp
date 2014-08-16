#include "Word.h"
#include <iostream>
#include <iterator>

using namespace WordState;

//!«‘‚É“o˜^‚³‚ê‚Ä‚¢‚È‚¢ê‡
Word::Word(string& _str){
	exist = 0;
	wordState["•\‘wŒ^"] = _str;
	wordState["•iŒ"] = "*";
	wordState["‘OÚ‘±0"] = "*";
	setPriority();
}

//!«‘‚©‚ç“o˜^‚µ‚½ê‡
Word::Word(hash_map<string,string>& _state){
	wordState = _state;
	exist = 0;
	setPriority();
}

Word::~Word(){
	//cout << wordState["•\‘wŒ^"];
}

void Word::setPriority(){
	if (wordState["•iŒ"] == "–¼Œ")
	{
		priority = 2;
	}
	else
	{
		priority = 1;
	}
}

string Word::getState(const string& _key){
	return wordState[_key];
}
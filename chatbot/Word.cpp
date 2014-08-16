#include "Word.h"
#include <iostream>
#include <iterator>

using namespace WordState;

//!辞書に登録されていない場合
Word::Word(string& _str){
	exist = 0;
	wordState["表層型"] = _str;
	wordState["品詞"] = "*";
	wordState["前接続0"] = "*";
	setPriority();
}

//!辞書から登録した場合
Word::Word(hash_map<string,string>& _state){
	wordState = _state;
	exist = 0;
	setPriority();
}

Word::~Word(){
	//cout << wordState["表層型"];
}

void Word::setPriority(){
	if (wordState["品詞"] == "名詞")
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
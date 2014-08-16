#include "Word.h"
#include <iostream>
#include <iterator>

using namespace WordState;

//!�����ɓo�^����Ă��Ȃ��ꍇ
Word::Word(string& _str){
	exist = 0;
	wordState["�\�w�^"] = _str;
	wordState["�i��"] = "*";
	wordState["�O�ڑ�0"] = "*";
	setPriority();
}

//!��������o�^�����ꍇ
Word::Word(hash_map<string,string>& _state){
	wordState = _state;
	exist = 0;
	setPriority();
}

Word::~Word(){
	//cout << wordState["�\�w�^"];
}

void Word::setPriority(){
	if (wordState["�i��"] == "����")
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
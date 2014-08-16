#include "WordFactory.h"

WordFactory::WordFactory()
{
	
}

WordFactory::~WordFactory()
{

}

pair<string,Word*> WordFactory::MakeWord(const string& _type,hash_map<string,string>& _wordState){
	//���[�h����map��1��Word�����
		Word* word = new Word(_wordState);
		pair<string,Word*> p(_type,word);
		return p;
}

pair<string,Word*> WordFactory::MakeWord(string& _str){
	Word* word = new Word(_str);
	pair<string,Word*> p(_str,word);
	
	return p;
}
#pragma once
#include <string>
#include <hash_map>

using namespace std;

namespace WordType{
	enum{
		NOUN,		//名詞
		VERB,		//動詞
		I_ADJECTIVE,	//形容詞
		NA_ADJECTIVE,	//形容動詞
		ADVERB,			//副詞
		ADNOMINAL,		//連体詞
		CONJUNCTION,	//接続詞
		AUXILIARY_VERB,	//助動詞
		PARTICLE,		//助詞
	};
};

namespace WordState{
	enum{
		WORD,	//表層型
		PART,	//品詞
		CONJUGATE,	//活用形
		DECLENSION,	//活用型
		MODEL,		//原型
		TYPE,		//品詞分類
		PRE_PART0,	//前接続0
		PRE_PART1,	//前接続1
		NEXT_PART0,	//後接続0
		NEXT_PART1,	//後接続1
	};
};

//!語を表すクラス
class Word{
private:
	//!語及びその分類
	hash_map<string,string> wordState;

	//!次に続くワードとその確率
	//hash_map<string,int> nextWord;

	//!語が現れた数
	int exist;

	//!優先度
	int priority;
public:
	Word(string& _str);
	Word(hash_map<string,string>& _state);
	virtual ~Word();

	//!登録語のパラメータを返す
	string getState(const string& _index);

	void IncExist(){ exist++;}

	void setPriority();

	int getExist(){return exist;}
	int getPriority(){return priority;}
};
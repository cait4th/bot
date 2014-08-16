#pragma once
#include "Word.h"

class Markov{
private:
	const int N;	//マルコフ連鎖数
	const int RE;	//単語選択係数(大きいほど文章が長くなる)

	hash_map<string,hash_map<string,int>> markovData;	

public:
	Markov();
	virtual ~Markov();

	//!マルコフ連鎖生成
	void MakeMarkov(vector<string>& _str);
	//!suffix選択
	string ChooseNext(const string& _key);

	hash_map<string,int>& getMarkovData(const string& _key);
};
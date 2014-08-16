#pragma once

#include "Generater.h"
#include "Dictionary.h"
#include "Markov.h"

class Bot{
private:
	Generater generater;
	Dictionary* dic;
	Markov markov;

	string input;
	vector<string> output;
public:
	Bot(Dictionary* _dictionary);
	virtual ~Bot();

	//!外部の文章から学習
	void Load(const string& _filename);

	//!入力された文を受け取る
	void setString(const string& _str);

	//!入力文を解析する
	void Analysis();

	//!出力
	void Say();

	//!入力文からキーワードを選択
	vector<string> SeletKey();
};
#pragma once
#include <map>
#include "Word.h"
#include "WordFactory.h"

class Dictionary{
private:
	std::multimap<const string,Word*> dictionary;
	string output;

	WordFactory* wordFactory;

public:
	Dictionary(WordFactory* _factory);
	//!入力された文章をtxtに出力
	virtual ~Dictionary();

	//!ファイルから辞書データベースに登録
	void Load(const string& _filename);

	//!ファイルから文章を形態素解析して登録
	void Save(vector<string>& _input);

	//!キー・品詞・前接続からWordを取り出す
	Word* getWord(const string& _key,const string& _part = string("*"),const string& _prePart = string("*"));

	//!キーが辞書に登録されているか
	bool IsExistWord(const string& _key);

	//!入力された文章を蓄積
	void SaveString(const string& _str);

	multimap<const string,Word*> getDic(){return dictionary;}
};
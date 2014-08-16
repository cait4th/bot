#pragma once
#include <string>
#include <vector>
#include "Dictionary.h"

using namespace std;

class Generater{
private:
	enum{
		KANJI,
		KATAKANA,
		OTHER
	};

public:
	Generater();
	virtual ~Generater();

	//字句解析
	//!漢字かそれ以外かの判別
	bool IsKanji(const char ch);

	//!カタカナかそれ以外かの判別
	bool IsKatakana(const char ch1,const char ch2);

	//!句読点,記号の検出
	bool IsPunct(const char ch1,const char ch2);

	//!字種の設定
	int TypeSet(const char ch1,const char ch2);

	//!全角文字のみ取り出す
	string GetWideChar(const string& _s);

	//!文章のカット
	vector<string> Cut(const string& _str,Dictionary& _dictionary);

	//!一度だけ後ろから形態素の切り出し
	vector<string> CreateMorphOnce(const char* _target);

	//!辞書による切り出し
	vector<string> CreateByDictionary(const string& _str,Dictionary& _dictionary);
};
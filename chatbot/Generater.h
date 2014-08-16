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

	//������
	//!����������ȊO���̔���
	bool IsKanji(const char ch);

	//!�J�^�J�i������ȊO���̔���
	bool IsKatakana(const char ch1,const char ch2);

	//!��Ǔ_,�L���̌��o
	bool IsPunct(const char ch1,const char ch2);

	//!����̐ݒ�
	int TypeSet(const char ch1,const char ch2);

	//!�S�p�����̂ݎ��o��
	string GetWideChar(const string& _s);

	//!���͂̃J�b�g
	vector<string> Cut(const string& _str,Dictionary& _dictionary);

	//!��x������납��`�ԑf�̐؂�o��
	vector<string> CreateMorphOnce(const char* _target);

	//!�����ɂ��؂�o��
	vector<string> CreateByDictionary(const string& _str,Dictionary& _dictionary);
};
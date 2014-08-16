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

	//!�O���̕��͂���w�K
	void Load(const string& _filename);

	//!���͂��ꂽ�����󂯎��
	void setString(const string& _str);

	//!���͕�����͂���
	void Analysis();

	//!�o��
	void Say();

	//!���͕�����L�[���[�h��I��
	vector<string> SeletKey();
};
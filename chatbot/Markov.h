#pragma once
#include "Word.h"

class Markov{
private:
	const int N;	//�}���R�t�A����
	const int RE;	//�P��I���W��(�傫���قǕ��͂������Ȃ�)

	hash_map<string,hash_map<string,int>> markovData;	

public:
	Markov();
	virtual ~Markov();

	//!�}���R�t�A������
	void MakeMarkov(vector<string>& _str);
	//!suffix�I��
	string ChooseNext(const string& _key);

	hash_map<string,int>& getMarkovData(const string& _key);
};
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
	//!���͂��ꂽ���͂�txt�ɏo��
	virtual ~Dictionary();

	//!�t�@�C�����玫���f�[�^�x�[�X�ɓo�^
	void Load(const string& _filename);

	//!�t�@�C�����當�͂��`�ԑf��͂��ēo�^
	void Save(vector<string>& _input);

	//!�L�[�E�i���E�O�ڑ�����Word�����o��
	Word* getWord(const string& _key,const string& _part = string("*"),const string& _prePart = string("*"));

	//!�L�[�������ɓo�^����Ă��邩
	bool IsExistWord(const string& _key);

	//!���͂��ꂽ���͂�~��
	void SaveString(const string& _str);

	multimap<const string,Word*> getDic(){return dictionary;}
};
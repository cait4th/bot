#include "Dictionary.h"
#include <fstream>
#include <iostream>
#include <string>

Dictionary::Dictionary(WordFactory* _factory){
	wordFactory = _factory;
	Load(string("./dictionary/noun.csv"));
	Load(string("./dictionary/auxiliary.csv"));
	Load(string("./dictionary/particle.csv"));
	dictionary.insert(wordFactory->MakeWord(string("_START_")));
	cout << dictionary.count("�l");
}

Dictionary::~Dictionary(){
	ofstream ofs;
	ofs.open("test.txt",ios::app);
	if (!ofs)
	{
		cout << "Save�t�@�C�����J���܂���\n";
		exit(1);
	}
	ofs << output;
	ofs.close();
}

//!�t�@�C�����玫���f�[�^�x�[�X�ɓo�^
void Dictionary::Load(const string& _filename){
	std::ifstream ifs(_filename);

	if (!ifs)
	{
		char error[512];
		sprintf_s(error,"�w�肵���t�@�C��(%s)���J���܂���ł���",_filename.c_str());
		throw error;
	}

	string str;
	unsigned cnt=0;
	std::vector<string> keyCode;
	while (!ifs.eof())
	{
		ifs >> str;
		cnt = 0;

		std::hash_map<string,string> states;

		unsigned comment = str.find('/');
		unsigned index = str.find_first_of(',');
		unsigned key = str.find_first_of('!');	
		//�R�����g���P�ꂪ�Ȃ���Ύ��̍s��
		if (index == string::npos || comment != string::npos)
		{
			continue;
		}

		
		//�P�ꂸ��map�ɂ����
		while (index != string::npos)
		{
			index = str.find_first_of(',');
			//������̐����Ȃ�
			if (key != string::npos)
			{
				keyCode.push_back(str.substr(1,index-1));
			}
			else
			{
				states[keyCode.at(cnt)] = str.substr(0,index);
			}
			str = str.substr(index+1);
			cnt++;
		}
		
		//���[�h����map��1��Word�����
		dictionary.insert(wordFactory->MakeWord(states[keyCode.at(0)],states));

	}
	ifs.close();
}

void Dictionary::Save(vector<string>& _input){
	for (vector<string>::iterator i = _input.begin();
		i != _input.end(); i++)
	{
		//�����ɖ����L�[���[�h��o�^
		if (IsExistWord(*i)==false)
		{
			dictionary.insert(wordFactory->MakeWord(*i));
		}
	}
}

Word* Dictionary::getWord(const string& _key,const string& _part,const string& _prePart){	
	try{
		int count = (int)dictionary.count(_key);
		if (count != 0)
		{
			multimap<const string,Word*>::iterator it = dictionary.find(_key);
			Word* w;
			for (int i=0; i<count; i++)
			{
				w = it->second;
				//�ۗ�
				/*if (w->getState("�i��") == _part && w->getState("�O�ڑ�0") == _prePart)
				{
					return w;
				}*/
				return w;
				it++;
			}
		}
		throw "Dictionary::getWord�ɂ����Ďw�肳�ꂽ�L�[��dictioary�ɑ��݂��܂���ł���";

	} catch(char* e){
		cout << e << endl << "�L�[:" << _key;
	}
	return NULL;
}

bool Dictionary::IsExistWord(const string& _key){
	if ((int)dictionary.count(_key) == 0)
	{
		return false;
	}
	return true;
}

void Dictionary::SaveString(const string& _str){
	output += _str;
	output += "\n";
}
#include "Bot.h"
#include <iostream>
#include <sstream>
#include <fstream>

Bot::Bot(Dictionary* _dictionary){
	dic = _dictionary;
	cout <<"Now Loading..." << endl;
	Load(string("test.txt"));
	cout <<"bot:用件をどうぞ" << endl;
}

Bot::~Bot(){

}

void Bot::Load(const string& _filename){
	ifstream ifs(_filename);

	if (!ifs)
	{
		char error[512];
		sprintf_s(error,"指定したファイル(%s)が開けませんでした",_filename.c_str());
		throw error;
	}

	string str;
	vector<string> out;

	while (!ifs.eof())
	{
		ifs >> str;

		out = generater.Cut(str,*dic);
		dic->Save(out);

		for (vector<string>::iterator i = out.begin();
			i != out.end(); i++)
		{
			cout << *i;
		}
		cout << endl;

		markov.MakeMarkov(out);
	}
	ifs.close();
}

void Bot::setString(const string& _str){
	input = _str;
	dic->SaveString(_str);
}

void Bot::Analysis(){
	output = generater.Cut(input,*dic);
	dic->Save(output);

	markov.MakeMarkov(output);
}

vector<string> Bot::SeletKey(){
	vector<string> keys;
	double r = (rand()/(double)RAND_MAX);
	for (vector<string>::iterator i = output.begin();
		i != output.end()-1; i++)
	{
		try{
			if (r<0.4*dic->getWord(*i)->getPriority())
			{
				keys.push_back(*i);
				keys.push_back(*(i+1));
				return keys;
			}
			r = (rand()/(double)RAND_MAX);
		}
		catch(char*){
			i = output.begin();
			continue;
		}
	}

	keys.clear();
	keys.push_back("_START_");
	keys.push_back("私");
	return keys;

}

void Bot::Say(){
	cout << "bot:";

	unsigned i = 0;
	string s;
	vector<string> say = SeletKey();
	do
	{
		s = say[i] + say[i+1];
		s = markov.ChooseNext(s);
		say.push_back(s);
		i++;
	}
	while (s != "_END_");

	for (vector<string>::iterator it = say.begin();
		it != say.end(); it++)
	{
		if ((*it) != "_START_")
		{
			cout << *it;
		}
	}
	printf("\n");
}
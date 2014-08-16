#include "Markov.h"

Markov::Markov(): N(2), RE(3){

}

Markov::~Markov(){

}

void Markov::MakeMarkov(vector<string>& _str){
	hash_map<string,int> tmp;

	string pre;
	for (vector<string>::iterator i = _str.begin()+N; i != _str.end(); i++)
	{
		for (int j=N; j>0; j--)
		{
			pre += *(i-j);
		}

		tmp = markovData[pre];

		if (tmp.find(*i) == tmp.end())
		{
			tmp[*i] = 0;
		}
		tmp[*i]++;
		markovData[pre] = tmp;
		pre.clear();
	}
}

string Markov::ChooseNext(const string& _key){
	int sum = 0;
	hash_map<string,int>::iterator i;
	for (i = markovData[_key].begin(); i != markovData[_key].end(); i++)
	{
		sum += i->second;
	}

	//Å‘åsum‚Ì—”
	int r = (int)((rand()/(double)RAND_MAX)*sum);

	//•¶Í‚ª‚·‚®‚ÉØ‚ê‚é‚½‚ß”‰ñŒJ‚è•Ô‚·
	for (int j=0; j<RE; j++)
	{
		for (i = markovData[_key].begin(); i != markovData[_key].end(); i++)
		{
			if (r<i->second+1)
			{
				return i->first;
			}
			r = (int)((rand()/(double)RAND_MAX)*sum);
		}
	}
	return "_END_";
}

hash_map<string,int>& Markov::getMarkovData(const string& _key){
	return markovData[_key];
}
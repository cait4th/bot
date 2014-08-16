#include "Generater.h"
#include <iostream>

Generater::Generater(){

}

Generater::~Generater(){

}

bool Generater::IsKanji(const char ch){
	int d = (unsigned char)ch;

	if (d >= 0x88)
	{
		return true;
	}
	return false;
}

bool Generater::IsKatakana(const char ch1,const  char ch2){
	int d1 = (unsigned char)ch1;
	int d2 = (unsigned char)ch2;

	if ((d1==0x83) && (d2 >= 40) && (d2 <= 0x96))
	{
		return true;
	}
	return false;
}

//!一応一文字分を引数としている
bool Generater::IsPunct(const char ch1,const char ch2){
	if ((ch1==0xffffff81))
	{
		return true;
	}
	return false;
}

int Generater::TypeSet(const char ch1,const char ch2){
	if (IsKanji(ch1))
	{
		return KANJI;
	}
	else if (IsKatakana(ch1,ch2))
	{
		return KATAKANA;
	}
	else
	{
		return OTHER;
	}
}

//!_sから全角文字のみ取り出したものを返す
string Generater::GetWideChar(const string& _s){
	string _t;
	int d;
	unsigned int i=0;
	while(i<_s.size())
	{
		d = (unsigned char)_s[i];
		if (((d>0x7f) && (d<0xa0)) || (d>0xdf) && (d<0xf0))	//2バイト文字
		{
			_t += _s[i++];
			_t += _s[i++];
		}
		else
		{	
			++i;
		}
	}
	_t += '\0';

	return _t;
}

vector<string> Generater::Cut(const string& _str,Dictionary& _dictionary){
	vector<string> result,out,lastStr;
	string str = GetWideChar(_str);

	result.push_back("_START_");

	while (true)
	{
		out = CreateByDictionary(str,_dictionary);
		//不明文章の分解
		lastStr = CreateMorphOnce(out.at(out.size()-1).c_str());

		//不明文章を消す(形態素解析できれば)
		if (out.size()>0 || lastStr.size()>1)
		{
			out.pop_back();
		}

		//形態素解析した文章を仮出力に入れる
		for (vector<string>::iterator i = lastStr.begin();
			i != lastStr.end(); i++)
		{
			out.push_back(*i);
		}
		
		/*次の分解する文章があれば更新
		なければダミーを仮出力に入れる(後で末尾がpopされるため)*/
		if (lastStr.size()>1)
		{
			str = lastStr.at(lastStr.size()-1);
		}
		else
		{
			out.push_back("");
			str = "";
		}

		//末尾は分解されてないので消す
		out.pop_back();
		//既知の単語をresultに追加
		for (vector<string>::iterator i = out.begin();i != out.end(); i++)
		{
			result.push_back(*i);
		}

		//分解する文章がなければ終了
		if (str == "")
		{
			break;
		}
	}
	result.push_back("_END_");
	return result;
}

vector<string> Generater::CreateMorphOnce(const char* _target){
	//分解した文章を入れる
	vector<string> result;
	string str;

	int i=0;
	int lastType = TypeSet(_target[i],_target[i+1]);
	
	while (_target[i] != '\0')
	{
		if (!IsPunct(_target[i],_target[i+1]))
		{
			int nowType = TypeSet(_target[i],_target[i+1]);

			if (nowType!=lastType) //字種が変わっている
			{
				result.push_back(str);
				break;
			}
			str += _target[i++];
			str += _target[i++];
		}
		else	//句読点
		{
			//文頭が句読点でなければそこまでが形態素
			if (str != "")
			{
				result.push_back(str);
				break;
			}
			str += _target[i++];
			str += _target[i++];
			result.push_back(str);
			break;
		}
	}

	//形態素解析できなければ余り無し(句読点除く)
	string target = string(_target);
	if ((target == str) && target.size()>0)
	{
		if (IsPunct(str[0],str[1])==false)
		{
			result.push_back(str);
			return result;
		}
	}

	//削った余りを入れる
	string s = string(_target).substr(str.size());
	if (s.size()>0)
	{
		result.push_back(s);
	}

	return result;
}

//!最長一致法による
vector<string> Generater::CreateByDictionary(const string& _str,Dictionary& _dictionary){
	vector<string> result;

	string saveStr = _str;
	string nextStr = _str;

	while (nextStr.size()>0)
	{
		//後ろから順に辞書に登録されているか調べ、なければ末尾をカット
		if (_dictionary.IsExistWord(nextStr) == true)
		{
			result.push_back(nextStr);
			nextStr = saveStr.substr(nextStr.size());
			saveStr = nextStr;
		}
		else
		{
			nextStr = nextStr.substr(0,nextStr.size()-1);
		}
	}
	result.push_back(saveStr);

	return result;
}
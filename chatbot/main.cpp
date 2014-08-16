#include <iostream>
#include "Bot.h"
#include "Dictionary.h"
#include "WordFactory.h"

using namespace std;
int main(){

	cout << "�I������ɂ�ctl+Z�������ĉ�����" << endl;
	cout << "���S�p�����̂ݎg�p�o���܂��B" << endl;

	WordFactory* wordFactory = new WordFactory();
	Dictionary dic(wordFactory);
	Bot bot(&dic);
	string str;

	cout << "you:";
	while (cin >> str)
	{
		bot.setString(str);
		bot.Analysis();
		bot.Say();

		cout << "you:";
	}

	delete wordFactory;
}
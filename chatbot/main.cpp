#include <iostream>
#include "Bot.h"
#include "Dictionary.h"
#include "WordFactory.h"

using namespace std;
int main(){

	cout << "終了するにはctl+Zを押して下さい" << endl;
	cout << "※全角文字のみ使用出来ます。" << endl;

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
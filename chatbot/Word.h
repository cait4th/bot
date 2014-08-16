#pragma once
#include <string>
#include <hash_map>

using namespace std;

namespace WordType{
	enum{
		NOUN,		//����
		VERB,		//����
		I_ADJECTIVE,	//�`�e��
		NA_ADJECTIVE,	//�`�e����
		ADVERB,			//����
		ADNOMINAL,		//�A�̎�
		CONJUNCTION,	//�ڑ���
		AUXILIARY_VERB,	//������
		PARTICLE,		//����
	};
};

namespace WordState{
	enum{
		WORD,	//�\�w�^
		PART,	//�i��
		CONJUGATE,	//���p�`
		DECLENSION,	//���p�^
		MODEL,		//���^
		TYPE,		//�i������
		PRE_PART0,	//�O�ڑ�0
		PRE_PART1,	//�O�ڑ�1
		NEXT_PART0,	//��ڑ�0
		NEXT_PART1,	//��ڑ�1
	};
};

//!���\���N���X
class Word{
private:
	//!��y�т��̕���
	hash_map<string,string> wordState;

	//!���ɑ������[�h�Ƃ��̊m��
	//hash_map<string,int> nextWord;

	//!�ꂪ���ꂽ��
	int exist;

	//!�D��x
	int priority;
public:
	Word(string& _str);
	Word(hash_map<string,string>& _state);
	virtual ~Word();

	//!�o�^��̃p�����[�^��Ԃ�
	string getState(const string& _index);

	void IncExist(){ exist++;}

	void setPriority();

	int getExist(){return exist;}
	int getPriority(){return priority;}
};
#pragma once
#include<vector>
#include<ctime>
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
#include"win_tools.h"

class Record;
class RecordItem //һ����¼
{
	string name;//��¼����ʱ�����
	int score;//����
	int speed;//С���ƶ��ٶ�
	int ghost_num;//С������3~5����
	int steps_num;//�ܹ�������ʱ������
	vector<int> steps;//��¼��ÿ��ʱ������ʱ�Զ���/С�ֵ��ƶ�����
public:
	friend class Record;
	friend class Game;
	RecordItem() { steps_num = 0;};
	RecordItem(const string& iname, int iscore) { name = iname; score = iscore; steps_num = 0;};
	bool operator <(const RecordItem &B) { return score > B.score; }//���ڽ��� sort
};

class Record //��¼������
{
	const char *filepath; //�����ʷ��¼���ļ���
	vector<RecordItem> items; //��ʷ��¼��Ŀ
public:
	friend class Game;
	Record():filepath("game.record"){};
	//���ļ��ж�ȡ��ʷ��¼��Ϣ
	void read();
	//����ʷ��Ϣ�����ļ�
	void save();
	//����һ����ʷ��¼��Ϣ
	void add(int the_score,const vector<int> &steps,int ghost_num,int speed);
	//ɾ��ָ���±����ʷ��¼��Ŀ
	void del(int x);
	//չʾ��ʷ��¼
	void show();
};


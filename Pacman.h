#pragma once
#include"Map.h"

class Pacman:public Position
{
	DIRECTION go;
public:
	friend class Game;
	Pacman() {};
	//��(x,y)λ�÷��óԶ���
	void init(int x, int y);
	//pacman��ĳ�������ƶ�������Map��Ҫ����ƶ��Ƿ�Ϸ������磬ǽ�޷�ǰ����
	void move(int dir, Map &map);
	//���سԶ��˵�ǰ���ڵ�λ������
	void getXY(int &a, int &b);
};


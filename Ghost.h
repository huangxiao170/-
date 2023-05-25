#pragma once
#include"Position.h"
#include"Map.h"
#include"Pacman.h"

class Ghost:public Position
{
	//��ʾ�ƶ�����
	DIRECTION go;
	//��ʼλ������
	int init_x, init_y;
public:
	Ghost() {};
	//��(x,y)λ�÷���С��
	Ghost(int x, int y);
	//С�ֳ�ĳ�������ƶ�������Map��Ҫ����ƶ��Ƿ�Ϸ������磬ǽ�޷�ǰ����
	int move(Map &map,Pacman &pacman);
	int move(int dir,Map &map, Pacman &pacman);//���أ�ָ��������ƶ�
	//��ײ��⣺�������䶳�ڣ���GameOver�����򣬸�С�ֻص���ʼλ��
	bool hit(Pacman &pacman, Map &map);
};


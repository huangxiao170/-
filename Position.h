#pragma once

#include<string>
#include<cstring>
#include<iostream>
#include<fstream>
using namespace std;
#include"win_tools.h"

//��������
enum DIRECTION { UP, DOWN, LEFT, RIGHT };

class Position
{
protected:
	string key;//�õ���ַ�
	int x, y;  //����
	int color; //��ɫ
public:
	friend class Map;
	Position() {
		color = BLUE_GREEN_COLOR;
	}
	Position(int a, int b, const string str,int icolor = BLUE_GREEN_COLOR) {
		setXY(a, b);
		color = icolor;
		setKey(str);
	}
	//�趨�ַ�
	void setKey(const string str);
	//�趨��ʾ����
	void setXY(int a, int b);
	//��ָ�����괦��ʾ
	void print();
	//��ո����괦���ַ�
	void clear();
};


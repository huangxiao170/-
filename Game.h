#pragma once
#include"Map.h"
#include"Pacman.h"
#include"Ghost.h"
#include"Record.h"
#include<conio.h>

//��ϢUI�ĳߴ�
const int INFO_UI_SIZE = 5;
//�����
const int SIDE_INFO_UI_SIEZ = 22;

extern const int WINDOWS_SIZE_X;
extern const int WINDOWS_SIZE_Y;

class Game
{
	//�ĸ�ģ�飺�Զ��ˡ�С�֡���ͼ����ʷ��¼
	Pacman pacmanX;
	vector<Ghost> ghosts;
	Map mapX;
	Record record;
	
	//С���ƶ��ٶȵ���
	int GHOST_SPEED,speed_value;
	//�ѹ���ʱ�����ڵĸ���
	int time_counter;
	//��¼ÿ��ʱ������ʱ�Զ���/С�ֵ��ƶ�����
	vector<int> steps;
	//��ʶ�Ƿ��ڻط�״̬
	bool play_flag;

public:
	
	
	Game();
	void calculateFrameRate(double elapsedTime);
	//��Ϸ��ʼ��
	void init();
	//��Ϸ��ʼ����
	int start();
	//��Ϸ����ѡ��
	bool settings();
	//��ʷ��¼չʾ
	int show_record();
	//��Ϸѭ��
	bool loop();
	//��Ϸ�ط�
	void play(int x);
	
private:
	double  getLastTime;
	double getCurrentTime;
    double frameRate; // ��ǰ��Ϸ֡��
	//��Ϸ��ͣ
	void pause();
	//��Ϸ����
	bool game_over();
	//��Ϸʤ��
	bool game_win();
	//�����������Ϸ��Ϣ��UI
	void infoUI();
	//������ϢUI����
	void helpUI();
	//��ͣ�����»������н���
	void refresh();
};


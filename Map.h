#pragma once
#include"Position.h"
#include<vector>
#include<queue>
using namespace std;

const int MAP_SIZE = 29;
const int PACMAN_X = MAP_SIZE / 2;
const int PACMAN_Y = MAP_SIZE / 2;

//ʱ������
extern const int TIME_SPEED;
const int MAX_FREEZE_TIME = 5 * 1000 / TIME_SPEED;

//��ͼ�е�ĳ������ͣ��հס�ǽ�����ӡ���������
enum MAP_POS_TYPE { SPACE,WALL,PEAN,SUPER_PEAN };
class MapPos: public Position
{
	int type; //��ͼ�е�ĳ�������
public:
	//�趨��ͼ��ĳ�������
	void setType(int t);
	int getType() { return type; }
};

//����Ѱ·������ṹ��
struct PosXY
{
	int x, y;
};

class Pacman;
class Ghost;
class Map
{
	//��ͼ�е�ÿ���㣬����һ������ͬ���͵�Ԫ��
	MapPos points[MAP_SIZE][MAP_SIZE];
	//��ҵ÷�
	int scores;
	//ʤ��Ŀ��÷�
	int target_scores;
	//�������Ӵ�������ȴЧ��ʱ��
	int freezeTime;
	//Ѱ·�㷨���ڲ����庯��
	void findPath(Position &A, Position&B);

public:
	friend class Game;
	friend class Ghost;
	Map() {};
	//��ʼ�����ɵ�ͼ(ʹ��ָ�����ļ�)
	void init(const char* filepath, Pacman &pacman, vector<Ghost> &ghosts);
	//ĳ��ͼ���������
	void renew(int x, int y) { points[x][y].print(); }
	//����ĳ��(x,y)������,���ж��Ƿ�ɴ�/�Ʒ�
	int goXY(int x, int y) { return points[x][y].getType(); }
	//�Ե�(x,y)���Ķ���
	void delPean(int x, int y);
	//���(x,y)λ���Ƿ񳬳���ͼ��Χ,�Է�ֹ����Խ��
	bool oK(int x, int y);
	//�Ե�(x,y)���ĳ�������
	void delSuperPean(int x, int y);
	//�ҵ�A����Ե���B���·���е���һ���ķ���
	int findDir(Position &A, Position&B);
};


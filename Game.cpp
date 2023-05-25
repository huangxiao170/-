#include "Game.h"

//ʱ������
const int TIME_SPEED = 50;

//��߽�Ŀ��ඨλ(��������룩
const int INFO_MARGIN_LEFT = 8;
//�ϱ߽�Ŀ��ඨλ
const int INFO_MARGIN_UP = 6;

Game::Game()
{
	
		
	frameRate = 0.0;
	
	/*��ʼ��*/
	//���ô��ڴ�С
	SetWindowSize(WINDOWS_SIZE_X, WINDOWS_SIZE_Y);
	//�������������
	srand((unsigned int)(time(NULL)));
	//���ع��
	HideCursor();

}
void Game::calculateFrameRate(double elapsedTime) {
	frameRate = 1.0 / elapsedTime;
}
void Game::init()
{
	mapX.init("map.txt", pacmanX, ghosts);
	time_counter = 0;
	steps.clear();
	play_flag = false;
}

char GameName[] = { "\
                                                                                                     \n\
     *********                                                                                       \n\
     **      **                                                                                      \n\
     **       **                                                                                     \n\
     **      **                                                                                      \n\
     *********       *****          ******        ***      ***         *****         **  *****       \n\
     **            **     **      **      **     **  **   ** **      **     **     ** **      **     \n\
     **           **       **    **              *   **  **   **    **       **      **        **    \n\
     **          ***       **    **             **    ** *    **   ***       **      **        **    \n\
     **           **      ***     **      **    *     ****     **   **      ***      **        **    \n\
     **             *****   ***     ******     **      **       *     *****   ***    **        **    \n\
                                                                                                     \n\
                                                                                                     \n\
"
};



int Game::start()
{
	//�̶���UI��Ϣ
	SetColor(WHITE_COLOR);
	system("cls");
	Goto_XY(0, 2);
	SetColor(GAMENAME_COLOR);
	cout << GameName;
	Goto_XY(0, MAP_SIZE + INFO_UI_SIZE - 1);
	SetColor(TITLE_COLOR); cout << "\"��\"��\"��\"��ѡ�񣬻س���ȷ�ϣ�Esc���˳�"; SetColor(THEME_COLOR);

	//�ο����λ���趨
	int left_margin = (MAP_SIZE + SIDE_INFO_UI_SIEZ)-7;
	int vertical_margin = (MAP_SIZE + INFO_UI_SIZE)/2+5;
	SetColor(THEME_COLOR);
	Goto_XY(left_margin, vertical_margin - 1);
	cout << "��"; SetColor(SELECTED_COLOR); cout << "��ʼ��Ϸ"; SetColor(THEME_COLOR);
	Goto_XY(left_margin, vertical_margin + 1);
	cout << "  ��ʷ��¼";

	int selected = 0;
	int MAX_IDX = 1;
	//���̰���ʶ��
	while (true) {
		while (true) {
			double elapsedTime = getCurrentTime(arg1) - getLastTime(arg2); // ���磺elapsedTime = getCurrentTime() - getLastTime();
			calculateFrameRate(elapsedTime);

			// ������Ϸ֡��
			Goto_XY(MAP_SIZE * 2 + 18, INFO_MARGIN_UP + 1);
			SetColor(WHITE_COLOR);
			cout << "FPS: " << frameRate;

			Sleep(50); // ʱ������
		}
		char ch;
		if (_kbhit())
		{
			ch = _getch();
			switch (ch)
			{
			case -32:
				ch = _getch();
				switch (ch)
				{
				case 72:					
					if (selected != 0){
						selected = 0;
						Goto_XY(left_margin, vertical_margin - 1);
						cout << "��"; SetColor(SELECTED_COLOR); cout << "��ʼ��Ϸ"; SetColor(THEME_COLOR);
						Goto_XY(left_margin, vertical_margin + 1);
						cout << "  ��ʷ��¼";
					}
					break;
				case 80:
					if (selected != MAX_IDX) {
						selected = MAX_IDX;
						Goto_XY(left_margin, vertical_margin - 1);
						cout << "  ��ʼ��Ϸ";
						Goto_XY(left_margin, vertical_margin + 1);
						cout << "��"; SetColor(SELECTED_COLOR); cout << "��ʷ��¼"; SetColor(THEME_COLOR);
					}
					break;
				
				default:
					break;
				}
				break;
			case '\r':
				system("cls");
				return selected;
			case 27://Esc
				system("cls");
				exit(0);
			default:;
			}
		}
		Sleep(10);
	}
	system("cls");
	return selected;
}

int speed_min = 1;
int speed_max = 5;
int right_way_rate = 1;
void showSettings(int selected, int &speed) {
	//�ο����λ���趨
	int left_margin = (MAP_SIZE + SIDE_INFO_UI_SIEZ) - 7;
	int vertical_margin = (MAP_SIZE + INFO_UI_SIZE) / 2;
	SetColor(THEME_COLOR);
	switch (selected)
	{
	case 0:
		speed = speed_min;
		Goto_XY(left_margin, vertical_margin);
		cout << "��"; SetColor(SELECTED_COLOR); cout << "��ģʽ  "; SetColor(THEME_COLOR);
		Goto_XY(left_margin, vertical_margin + 2);
		cout << "  ��ͨģʽ  ";
		Goto_XY(left_margin, vertical_margin + 4);
		cout << "  ����ģʽ  ";
		Goto_XY(left_margin, vertical_margin + 6);
		cout << "  �Զ���ģʽ";
		break;
	case 1:
		speed = (speed_min + speed_max) / 2;
		Goto_XY(left_margin, vertical_margin);
		cout << "  ��ģʽ  ";
		Goto_XY(left_margin, vertical_margin + 2);
		cout << "��"; SetColor(SELECTED_COLOR); cout << "��ͨģʽ  "; SetColor(THEME_COLOR);
		Goto_XY(left_margin, vertical_margin + 4);
		cout << "  ����ģʽ  ";
		Goto_XY(left_margin, vertical_margin + 6);
		cout << "  �Զ���ģʽ";
		break;
	case 2:
		speed = speed_max;
		Goto_XY(left_margin, vertical_margin);
		cout << "  ��ģʽ  ";
		Goto_XY(left_margin, vertical_margin + 2);
		cout << "  ��ͨģʽ  ";
		Goto_XY(left_margin, vertical_margin + 4);
		cout << "��"; SetColor(SELECTED_COLOR); cout << "����ģʽ  "; SetColor(THEME_COLOR);
		Goto_XY(left_margin, vertical_margin + 6);
		cout << "  �Զ���ģʽ";
		break;
	case 3:
		Goto_XY(left_margin, vertical_margin);
		cout << "  ��ģʽ  ";
		Goto_XY(left_margin, vertical_margin + 2);
		cout << "  ��ͨģʽ  ";
		Goto_XY(left_margin, vertical_margin + 4);
		cout << "  ����ģʽ  ";
		Goto_XY(left_margin, vertical_margin + 6);
		cout << "��"; SetColor(SELECTED_COLOR); cout << "�Զ���ģʽ"; SetColor(THEME_COLOR);
		break;
	default:
		break;
	}

	Goto_XY(left_margin, vertical_margin + 8);
	cout << "С���ƶ��ٶȣ�";
	Goto_XY(left_margin, vertical_margin + 9);
	for (int i = speed_min; i <= speed_max; i++) {
		cout << i;
		cout << "  ";
	}
	Goto_XY(left_margin, vertical_margin + 9);
	for (int i = speed_min; i <= speed_max; i++) {
		if (i == speed) {
			SetColor(SELECTED_COLOR);cout << i; SetColor(THEME_COLOR);
		}
		else {
			cout << i;
		}
		cout << "  ";
	}
}
bool Game::settings()
{
	SetColor(WHITE_COLOR);
	system("cls");
	Goto_XY(0, 2);
	SetColor(GAMENAME_COLOR);
	cout << GameName;
	Goto_XY(0, MAP_SIZE + INFO_UI_SIZE - 1);
	SetColor(TITLE_COLOR); cout << "\"��\"��\"��\"��\"��\"��\"��\"��ѡ�񣬻س���ȷ�ϣ�Esc�������ϲ� | �ƶ��ٶȣ�ÿ���ƶ��ĸ���"; SetColor(THEME_COLOR);

	int selected = 0;
	int MAX_IDX = 3;
	int speed = speed_min;
	showSettings(selected, speed);
	//���̰���ʶ��
	while (true) {
		char ch;
		if (_kbhit())
		{
			ch = _getch();
			switch (ch)
			{
			case -32:
				ch = _getch();
				switch (ch)
				{
				case 72:
					if (selected != 0) {
						selected--;
						showSettings(selected, speed);
					}
					break;
				case 80:
					if (selected != MAX_IDX) {
						selected++;
						showSettings(selected, speed);
					}
					break;
				case 75:
					if (selected == MAX_IDX && speed != speed_min) {
						speed--;
						showSettings(selected, speed);
					}
					break;
				case 77:
					if (selected == MAX_IDX && speed != speed_max) {
						speed++;
						showSettings(selected, speed);
					}
					break;
				default:
					break;
				}
				break;
			case '\r':
				system("cls");
				GHOST_SPEED = 1000 / (50 * speed);
				speed_value = speed;
				right_way_rate = speed + 1;
				return true;
				break;
			case 27://Esc
				return false;
				break;
			default:;
			}
		}
	}
}


int RECORD_MAX_IDX = 0;
void showRecordChoice(int selected) {
	//����
	int left_margin_No = WINDOWS_SIZE_X / 2 - 30;
	int up_margin = 4;

	//�̶�UI
	Goto_XY(0, MAP_SIZE + INFO_UI_SIZE - 1);
	SetColor(TITLE_COLOR); cout << "\"��\"��\"��\"��ѡ�񣬻س�����ʼ�طţ��˸��ɾ����Esc�������ϲ�";
	Goto_XY(left_margin_No-6, up_margin);
	cout << "ѡ��"; SetColor(WHITE_COLOR);

	for (int i = 0; i <= RECORD_MAX_IDX; i++) {
		Goto_XY(left_margin_No-5, up_margin + 2 + i * 2);
		if (i == selected) {
			SetColor(THEME_COLOR); cout << "��"; SetColor(WHITE_COLOR);
		}
		else
			cout << "  ";
	}
}
int Game::show_record()
{
	record.show();
	RECORD_MAX_IDX = record.items.size() - 1;

	int selected = 0;
	showRecordChoice(selected);
	Goto_XY(WINDOWS_SIZE_X - 36, WINDOWS_SIZE_Y - 1);
	cout << "ע������ͼ�ı䣬��ɼ�¼���ܻط�ʧ��";
	
	//���̰���ʶ��
	while (true) {
		char ch;
		if (_kbhit())
		{
			ch = _getch();
			switch (ch)
			{
			case -32:
				ch = _getch();
				switch (ch)
				{
				case 72:
					if (selected != 0) {
						selected--;
						showRecordChoice(selected);
					}
					break;
				case 80:
					if (selected != RECORD_MAX_IDX) {
						selected++;
						showRecordChoice(selected);
					}
					break;
				default:
					break;
				}
				break;
			case '\b':
				record.del(selected);
				return show_record();
			case '\r':
				return selected;
			case 27://Esc
				return -1;
			default:;
			}
		}
	}

}

//���ڳԶ�����˸
int Pacman_Colors[] = { WHITE_COLOR, RED_COLOR, GREEN_COLOR, YELLOW_COLOR, BLUE_GREEN_COLOR };
int PacmanColors_i = 0;
bool Game::loop()
{
	refresh();
	
	//���ڷ����¼
	int dir_pacman = -1;
	int ghost_num = ghosts.size();
	int *dir_ghosts = new int[ghost_num];
	
	int speed_adapter = 0;
	while (true) {
		//��ʼ�� -1 ��ʾδ�ƶ�
		dir_pacman = -1;
		for (int i = 0; i < ghost_num; i++)
			dir_ghosts[i] = -1;

		//С���ƶ�ģ��
		if (mapX.freezeTime == 0) {
			++speed_adapter;
			if (speed_adapter == GHOST_SPEED) {
				speed_adapter = 0;
				//����С�ֶ��ƶ�
				for (int i = 0; i < ghost_num; i++) {
					dir_ghosts[i]=ghosts[i].move(mapX, pacmanX);
				}
			}
			pacmanX.color = BLUE_GREEN_COLOR;
		}
		else { //���ڳ�����ģʽ
			mapX.freezeTime--;
			PacmanColors_i = (PacmanColors_i + 1) % (sizeof(Pacman_Colors) / 4);
			pacmanX.color = Pacman_Colors[PacmanColors_i];
			pacmanX.print();
		}
		
		//���̰���ʶ��
		char ch;
		if (_kbhit())
		{
			ch = _getch();
			switch (ch)
			{
			case -32:
				ch = _getch();
				switch (ch)
				{
				case 72:
					pacmanX.move(UP, mapX);
					dir_pacman = UP;
					break;
				case 80:
					pacmanX.move(DOWN, mapX);
					dir_pacman = DOWN;
					break;
				case 75:
					pacmanX.move(LEFT, mapX);
					dir_pacman = LEFT;
					break;
				case 77:
					pacmanX.move(RIGHT, mapX);
					dir_pacman = RIGHT;
					break;
				default:
					break;
				}
				break;
			case 27://ESC
				return true;
			case ' ':
				pause();
				break;
			default:;
			}
		}

		//��¼�ߵķ���
		steps.push_back(dir_pacman);
		for (int i = 0; i < ghost_num; i++)
			steps.push_back(dir_ghosts[i]);
	
		//�ж��Ƿ���Ϸʤ�����������ж���
		if (mapX.scores == mapX.target_scores) {
			return game_win();
		}

		//�ж��Ƿ���Ϸʧ�ܣ����ײ��С��
		for (auto&ghost_i : ghosts) {
			if (ghost_i.hit(pacmanX,mapX))
				return game_over();
		}
		
		//����UI����
		infoUI();

		++time_counter;
		//ʱ������
		Sleep(50);
	}
}

void Game::play(int x)
{	
	//��¼Ϊ��
	if (record.items.size() == 0) return;

	//����ʷ��¼��Ŀ�У���ȡ���Ĳ�����Ϣ
	speed_value = record.items[x].speed;
	GHOST_SPEED = 1000 / (50 * speed_value);
	int ghost_num = record.items[x].ghost_num;
	
	//һ���ʼ��
	init();
	//��init()�����ط�״̬
	play_flag = true;
	refresh();

	if (ghost_num != ghosts.size()) { //У���ͼ��С�������Ƿ�����ʷ��¼�е�ƥ��
		system("cls");
		cout << "��⵽��ʷ��¼��Ŀ��Ӧ�ĵ�ͼ���ͼ�ļ��������޷�����...��ɾ����ʷ��¼�ļ���game.record ���� ��ԭ��ͼ" << endl;
		system("pause");
		exit(-1);
	}
	int numPerUnit = ghost_num + 1;//ÿnumPerUnit����steps��Ϊһ��ʱ�����ڵĲ���

	//���ڷ����¼
	int dir_pacman = -1;
	int *dir_ghosts = new int[ghost_num];

	helpUI();
	int speed_adapter = 0;
	while (true) {
		//��ʼ�� -1 ��ʾδ�ƶ�
		dir_pacman = record.items[x].steps[time_counter * numPerUnit];
		for (int i = 0; i < ghost_num; i++)
			dir_ghosts[i] = record.items[x].steps[time_counter * numPerUnit + i + 1];

		//С���ƶ�ģ��
		for (int i = 0; i < ghost_num; i++) {
			ghosts[i].move(dir_ghosts[i], mapX, pacmanX);
		}

		if(mapX.freezeTime != 0){ //���ڳ�����ģʽ
			mapX.freezeTime--;
			PacmanColors_i = (PacmanColors_i + 1) % (sizeof(Pacman_Colors) / 4);
			pacmanX.color = Pacman_Colors[PacmanColors_i];
			pacmanX.print();
		}
		pacmanX.move(dir_pacman, mapX);

		//��ײ��⣺�޵�״̬����ײ����
		for (auto&ghost_i : ghosts) {
			ghost_i.hit(pacmanX, mapX);
		}

		char ch;
		if (_kbhit())
		{
			ch = _getch();
			switch (ch)
			{
			case -32:
				ch = _getch();
				switch (ch)
				{
				case 72:
					pacmanX.move(UP, mapX);
					dir_pacman = UP;
					break;
				case 80:
					pacmanX.move(DOWN, mapX);
					dir_pacman = DOWN;
					break;
				case 75:
					pacmanX.move(LEFT, mapX);
					dir_pacman = LEFT;
					break;
				case 77:
					pacmanX.move(RIGHT, mapX);
					dir_pacman = RIGHT;
					break;
				default:
					break;
				}
				//�طŹ����а����˷�������˳��طŹ���
				play_flag = false;
				break;
			case 27://Esc
				return;
			case ' ':
				pause();
				break;
			default:;
			}
		}
		
		//��¼�ߵķ���
		steps.push_back(dir_pacman);
		for (int i = 0; i < ghost_num; i++)
			steps.push_back(dir_ghosts[i]);

		if (!play_flag) {
			//�ڻطŵĹ����а����˷�������˳��ط�ģʽ������������Ϸģʽ
			loop();
			return;
		}

		//����UI����
		infoUI();

		++time_counter;
		if (time_counter * numPerUnit >= record.items[x].steps_num) {
			//�طŽ���-��ǳԶ��˵�����λ��
			pacmanX.setKey("�w");
			pacmanX.print();
			Goto_XY(0, WINDOWS_SIZE_Y - 2);
			cout << "����������ص������棩" << endl;
			system("pause");
			break;
		}
		//ʱ������
		Sleep(50);
	}
	delete[] dir_ghosts;
}

void Game::pause()
{
	int bias_temp=23;
	Goto_XY(MAP_SIZE * 2 + 18, INFO_MARGIN_UP + bias_temp);
	if (play_flag) {
		SetColor(SELECTED_COLOR); cout << "�ط���ͣ"; SetColor(WHITE_COLOR);
	}
	else {
		SetColor(PAUSE_COLOR); cout << "��Ϸ��ͣ"; SetColor(WHITE_COLOR);
	}
	while (true) {
		char ch;
		if (_kbhit())
		{
			ch = _getch();
			switch (ch)
			{
			case 27://ESC
			case ' ':
				//refresh();
				Goto_XY(MAP_SIZE * 2 + 18, INFO_MARGIN_UP + bias_temp);
				cout << "        ";
				return;
				break;
			default:;
			}
		}
		Sleep(10);
	}
	
}

bool Game::game_over()
{
	record.add(mapX.scores, steps, ghosts.size(), speed_value);
	record.show();
	Goto_XY(WINDOWS_SIZE_X / 2 - 8, WINDOWS_SIZE_Y - 3);
	SetColor(LOST_COLOR);
	cout << "... Game Over ..." << endl;
	SetColor(WHITE_COLOR);
	cout << "����������ص������棩" << endl;
	system("pause");
	return true;
}

bool Game::game_win()
{
	record.add(mapX.scores, steps, ghosts.size(), speed_value);
	record.show();
	Goto_XY(WINDOWS_SIZE_X / 2 - 14, WINDOWS_SIZE_Y - 3);
	SetColor(WIN_COLOR);
	cout << "Congratulations~You Win!!!..." << endl;
	SetColor(WHITE_COLOR);
	cout << "����������ص������棩" << endl;
	system("pause");
	return true;
}

extern int Ghost_Colors[];
void Game::infoUI()
{
	//�����Ϸʱ��
	Goto_XY(MAP_SIZE * 2 + 2, WINDOWS_SIZE_Y - 1);
	printf("��Ϸʱ����%.1fs", time_counter*50.0 / 1000);

	//����ָ���
	Goto_XY(0, MAP_SIZE);
	string str_spliter(MAP_SIZE * 2, '-');
	cout << str_spliter;
	//�������
	Goto_XY(0, MAP_SIZE + INFO_UI_SIZE / 2);
	string str_Space(MAP_SIZE * 2, ' ');
	cout << str_Space;
	Goto_XY(0, MAP_SIZE + INFO_UI_SIZE / 2);
	cout << "��ǰ������" << mapX.scores;
	//�����ȴʱ��
	Goto_XY(0, MAP_SIZE + INFO_UI_SIZE - 2);
	cout << str_Space;
	Goto_XY(0, MAP_SIZE + INFO_UI_SIZE - 1);
	cout << str_Space;
	if (mapX.freezeTime > 0) {
		Goto_XY(0, MAP_SIZE + INFO_UI_SIZE - 2);
		printf("��ֹ - ����ʱ��%.1fs", mapX.freezeTime*50.0 / 1000);
		//cout << "ֹͣ�ƶ�����ʱ��"<< mapX.freezeTime*50.0/1000<<"s";
		Goto_XY(0, MAP_SIZE + INFO_UI_SIZE - 1);
		string str_time_counter((mapX.freezeTime)*MAP_SIZE * 2 / MAX_FREEZE_TIME, '#');
		cout << str_time_counter;
	}
}

void Game::helpUI()
{
	/* ��������� */
	//�ֽ���
	for (int i = 0; i < MAP_SIZE + INFO_UI_SIZE; i++) {
		Goto_XY(MAP_SIZE * 2, i);
		cout << "|";
	}
	int width = 28;
	//ģʽ
	if (play_flag) {
		Goto_XY(MAP_SIZE * 2 + INFO_MARGIN_LEFT + width / 2 - 4, INFO_MARGIN_UP - 5);
		SetColor(MODE_COLOR); cout << "�ط�ģʽ"; SetColor(WHITE_COLOR);
	}
	else {
		Goto_XY(MAP_SIZE * 2 + INFO_MARGIN_LEFT + width / 2 - 4, INFO_MARGIN_UP - 5);
		SetColor(MODE_COLOR); cout << "��Ϸģʽ"; SetColor(WHITE_COLOR);
	}
	

	//��������˵����
	Goto_XY(MAP_SIZE * 2 + INFO_MARGIN_LEFT + width / 2 - 4, INFO_MARGIN_UP - 2);
	SetColor(TITLE_COLOR); cout << "����˵��"; SetColor(WHITE_COLOR);
	Goto_XY(MAP_SIZE * 2 + INFO_MARGIN_LEFT - 1, INFO_MARGIN_UP - 3);
	string line1(width, '-');
	cout << "+" << line1 << "+";
	for (int i = 0; i < 8; i++) {
		Goto_XY(MAP_SIZE * 2 + INFO_MARGIN_LEFT - 1, INFO_MARGIN_UP - 2 + i);
		cout << "|";
	}
	Goto_XY(MAP_SIZE * 2 + INFO_MARGIN_LEFT - 1, INFO_MARGIN_UP - 2 + 8);
	cout << "+" << line1 << "+";
	for (int i = 0; i < 8; i++) {
		Goto_XY(MAP_SIZE * 2 + INFO_MARGIN_LEFT - 1 + width + 1, INFO_MARGIN_UP - 2 + i);
		cout << "|";
	}
	if (play_flag) {
		Goto_XY(MAP_SIZE * 2 + INFO_MARGIN_LEFT + 2, INFO_MARGIN_UP);
		cout << "��ֹ�طţ����²��ݳԶ��ˣ�";
		Goto_XY(MAP_SIZE * 2 + INFO_MARGIN_LEFT + 2, INFO_MARGIN_UP + 1);
		cout << "\"��\"��\"��\"��\"��\"��\"��\"��";
	}
	else {
		Goto_XY(MAP_SIZE * 2 + INFO_MARGIN_LEFT + 2, INFO_MARGIN_UP);
		cout << "�����ƶ���";
		Goto_XY(MAP_SIZE * 2 + INFO_MARGIN_LEFT + 2, INFO_MARGIN_UP + 1);
		cout << "\"��\"��\"��\"��\"��\"��\"��\"��";
	}
	

	Goto_XY(MAP_SIZE * 2 + INFO_MARGIN_LEFT + 2, INFO_MARGIN_UP + 3);
	cout << "��ͣ - �ո��";
	Goto_XY(MAP_SIZE * 2 + INFO_MARGIN_LEFT + 2, INFO_MARGIN_UP + 4);
	cout << "���� - Esc��";

	//ͼ��˵����
	width = 36;
	int bias_vertical = 10;
	int TEMP_MARGIN_LEFT = INFO_MARGIN_LEFT - 4;
	Goto_XY(MAP_SIZE * 2 + TEMP_MARGIN_LEFT + width / 2 - 2, INFO_MARGIN_UP + bias_vertical);
	SetColor(TITLE_COLOR); cout << "ͼ��"; SetColor(WHITE_COLOR);
	Goto_XY(MAP_SIZE * 2 + TEMP_MARGIN_LEFT - 1, INFO_MARGIN_UP + bias_vertical - 1);
	string line2(width, '-');
	cout << "+" << line2 << "+";
	for (int i = 0; i < 8; i++) {
		Goto_XY(MAP_SIZE * 2 + TEMP_MARGIN_LEFT - 1, INFO_MARGIN_UP + bias_vertical + i);
		cout << "|";
	}
	Goto_XY(MAP_SIZE * 2 + TEMP_MARGIN_LEFT - 1, INFO_MARGIN_UP + bias_vertical + 8);
	cout << "+" << line2 << "+";
	for (int i = 0; i < 8; i++) {
		Goto_XY(MAP_SIZE * 2 + TEMP_MARGIN_LEFT - 1 + width + 1, INFO_MARGIN_UP + bias_vertical + i);
		cout << "|";
	}

	Goto_XY(MAP_SIZE * 2 + INFO_MARGIN_LEFT, INFO_MARGIN_UP + 2 + bias_vertical);
	cout << "�Զ��ˣ�";
	Position Player((MAP_SIZE * 2 + INFO_MARGIN_LEFT + 9) / 2, INFO_MARGIN_UP + 2 + bias_vertical, "��", BLUE_GREEN_COLOR);
	Player.print();
	Goto_XY(MAP_SIZE * 2 + INFO_MARGIN_LEFT, INFO_MARGIN_UP + 4 + bias_vertical);
	cout << "С�֣�";
	for (int i = 0; i < ghosts.size(); i++) {
		Position ghost((MAP_SIZE * 2 + INFO_MARGIN_LEFT + 7 + i * 2) / 2, INFO_MARGIN_UP + 4 + bias_vertical, "��", Ghost_Colors[i]);
		ghost.print();
	}
	Goto_XY(MAP_SIZE * 2 + INFO_MARGIN_LEFT, INFO_MARGIN_UP + 6 + bias_vertical);
	cout << "��������   ��5s�ڴ����޵�״̬��";
	Position SuperPean((MAP_SIZE * 2 + INFO_MARGIN_LEFT + 9) / 2, INFO_MARGIN_UP + 6 + bias_vertical, "��", GREEN_COLOR);
	SuperPean.print();
	
	Goto_XY(MAP_SIZE * 2 + INFO_MARGIN_LEFT + 2, INFO_MARGIN_UP + 10 + bias_vertical);
	SetColor(HIGHLIGHT_COLOR);
	cout << "��ǰС���ƶ��ٶȣ�"<< speed_value <<"��/��";
	SetColor(WHITE_COLOR);
}

void Game::refresh()
{
	system("cls");
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {		
			mapX.points[i][j].print();
		}
	}
	pacmanX.print();
	for (auto &ghost_i : ghosts) {
		ghost_i.print();
	}
	infoUI();
	helpUI();
}

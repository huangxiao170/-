#include"win_tools.h"

//���ù��λ��
void Goto_XY(const int x, const int y)
{
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

//���ع��
void HideCursor()
{
	HANDLE fd = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cinfo;
	cinfo.bVisible = 0;
	cinfo.dwSize = 1;
	SetConsoleCursorInfo(fd, &cinfo);
}

//���ô��ڴ�С
void SetWindowSize(int cols, int lines)
{
	system("title PacManX");//���ô��ڱ���
	char cmd[30];
	sprintf(cmd, "mode con cols=%d lines=%d", cols, lines);
	system(cmd); //���ô��ڿ�Ⱥ͸߶�
}

//�����ı���ɫ
void SetColor(int colorID)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}
//wall 1|snakeb 2|snakeh 3|food 4

#include "stdafx.h"
#include<iostream>
#include<Windows.h>
#include"Snake.h"
#include<string>
using namespace std;

//======================================================================================

void gotoxy(short x, short y);
int *settings_synchronization();
int *statistics_synchronization();
void hide_mouse();
int _rand(int x);
void windowssize(short x, short y);

//======================================================================================

int *PrintSettingsData;

string Graph[200] = { "",
"��","��","��","��","��","��","��","��","��","��",
"��","��","��","��","��","�E","��","��","��","��",
"��","�d","��","��","��","��","��","��","��","��",
"�J","��","�K","��","�L","��","�I","��","��","��",
"��","��","��","��","��","�P","��","��","�S","�R",
"��","��","��","��","��","��","��","��","��","��",
"��","��","��","��","��","��","��","��","��","�S",
"��","��","�N","��","�O","��","��","��","�G","��",
"��","��","�H","��","��","��","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��",
"��","��","��","��","��","��","��","��",
};
//======================================================================================

void print_settings_synchronization()//����ͬ��
{
	PrintSettingsData = settings_synchronization();
}

void color_out(string st, short id)
{
	if (id == 15)//���idΪ15��ȡ���ֵ
	{
		id = _rand(15) + 1;
	}
	switch (id)
	{
	case 0://WHITE�ף�Ĭ�ϣ�
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		break;
	case 1://L_WHITE����
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		break;
	case 2://GREY��
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
		break;
	case 3://RED��
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		break;
	case 4://PINK��
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		break;
	case 5://BULE��
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
		break;
	case 6://L_BLUE����
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		break;
	case 7://GREEN��
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
		break;
	case 8://L_GREEN����
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		break;
	case 9://GOLDEN��
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
		break;
	case 10://YELLOW��
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		break;
	case 11://PURLPE��
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
		break;
	case 12://INDIGO��
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
		break;
	case 13://CYAN��
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
		break;
	case 14://CYANINEݼ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
		break;
	}
	cout << st;//�������
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//ɫ�ʸĻذ�ɫ
}

void c_out(string st, short x)
{
	if (PrintSettingsData[1] == 1)//�����ɫ����ʹ�ò�ɫ���,���������ɫ
	{
		color_out(st, x);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout << st;
	}
}

void graph_out(short id, short color, bool x)//�ַ����-���xΪ��:��ɫ����ַ�����:ʹ����ͨɫ�����(�Ƿ����ɫ�ʸ���ɫ�ʿ���)
{
	if (true == x)
	{
		color_out(Graph[id], color);
	}
	else
	{
		c_out(Graph[id], color);
	}
}

void g_out(short id, bool x)//��ͨ�ַ����(����idƥ�����õ��ַ�)
{
	switch (id)
	{
	case 1:
		graph_out(PrintSettingsData[12], PrintSettingsData[8], x);
		break;
	case 2:
		graph_out(PrintSettingsData[10], PrintSettingsData[6], x);
		break;
	case 3:
		graph_out(PrintSettingsData[9], PrintSettingsData[5], x);
		break;
	case 4:
		graph_out(PrintSettingsData[11], PrintSettingsData[7], x);
		break;
	case 5:
		graph_out(PrintSettingsData[19], PrintSettingsData[16], x);
		break;
	case 6:
		graph_out(PrintSettingsData[20], PrintSettingsData[17], x);
		break;
	case 7:
		graph_out(PrintSettingsData[21], PrintSettingsData[18], x);
		break;
	}
}

void shade_out(string st, short x, short y, int s, bool z)//�������
{
	if (z == false && (PrintSettingsData[1] == 0 || PrintSettingsData[2] == 0))//ʹ��������ɫ��+��������
	{
		gotoxy(x, y);
		color_out(st, 0);
		Sleep(s);
	}
	else
	{
		gotoxy(x, y);
		color_out(st, 2);
		Sleep(s);
		gotoxy(x, y);
		color_out(st, 0);
		Sleep(s);
		gotoxy(x, y);
		color_out(st, 1);
		Sleep(s);
	}
}

void shade_out_r(string st, short x, short y, int s, bool a, bool z)//������ʧ
{
	if (z == false && (PrintSettingsData[1] == 0 || PrintSettingsData[2] == 0))//ʹ��������ɫ��+��������
	{
		int b = st.size();
		gotoxy(x, y);
		while (b--)
		{
			cout << " ";
		}
		Sleep(s);
	}
	else
	{
		if (a == true)
		{
			gotoxy(x, y);
			color_out(st, 1);
			Sleep(s);
		}
		gotoxy(x, y);
		color_out(st, 0);
		Sleep(s);
		gotoxy(x, y);
		color_out(st, 2);
		Sleep(s);
		int b = st.size();
		gotoxy(x, y);
		while (b--)
		{
			cout << " ";
		}
		Sleep(s);
	}
}
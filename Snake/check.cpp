#include"stdafx.h"
#include"Snake.h"
#include<iostream>
#include<Windows.h>
#include<fstream>
#include<io.h>
#include<stdlib.h>
#include<string>

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

using namespace std;

//======================================================================================

void gotoxy(short x, short y);
void color_out(string st, short x);
void pogress_bar();
void warning_cover();
void warning(string title, string st1, string st2, string st3, string answer);
void wrong_cover();
void wrong(string title, string st1, string st2, string st3, string answer);
int _rand(int x);
void wrong_end();
void statistics_initialization();
void statistics_read();
void settings_initialization();
void settings_read();
void audio_initialization();
void audio_read();
void shade_out(string st, short x, short y, int s, bool z);
void shade_out_r(string st, short x, short y, int s, bool a, bool z);
void hide_mouse();
int *settings_synchronization();
int *statistics_synchronization();
void windowssize(short x, short y);

//======================================================================================

void check()
{
	hide_mouse();
	system("mode con cols=80 lines=31");
//	windowssize(80, 30);
	system("cls");

	Sleep(500);
	shade_out("����������Ϸ��飬���Ժ�", 28, 12, 100, true);
	Sleep(1000);
	shade_out_r("����������Ϸ��飬���Ժ�", 28, 12, 100, false, true);
	system("cls");

	Sleep(500);
	SetConsoleTitle(TEXT("̰����  ���ڽ��м��"));
	gotoxy(26, 20);
	color_out("���ڼ�� ��settings.ini��                  ", 1);
	for (int i = 0; i <= _rand(2) + 1; i++)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
	}
	if ((_access("settings.ini", 0)) == -1)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
		warning("                �ļ���ʧ                ", "     �޷���.\\���ҵ���settings.ini��     ", "              �������´���              ", "", "");
		gotoxy(26, 20);
		color_out("���ڴ�����settings.ini��                              ", 1);
		Sleep(_rand(50) + 50);
		pogress_bar();
		ofstream settings;
		settings.open("settings.ini");
		settings.close();
		gotoxy(26, 20);
		color_out("���ڳ�ʼ����settings.ini��                              ", 1);
		Sleep(_rand(50) + 50);
		pogress_bar();
		settings_initialization();
		Sleep(_rand(50) + 50);
	}
	pogress_bar();
	Sleep(_rand(50) + 50);
	if ((_access("settings.ini", 2)) == -1)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
		warning("             �ļ��޷���д               ", "   ��.\\settings.ini�������˶�дд����   ", "              ���ڳ��Խ��              ", "", "");
		gotoxy(26, 20);
		system("attrib -r settings.ini");
		color_out("���ڼ�� ��settings.ini��                  ", 1);
		pogress_bar();
		gotoxy(1, 1);
		gotoxy(1, 1);
		cout << "                                   ";
		Sleep(_rand(50) + 50);
		pogress_bar();
		if ((_access("settings.ini", 2)) == -1)
		{
			pogress_bar();
			Sleep(200);
			wrong("              ���Խ����Ч              ", "    �޷����衰.\\settings.ini��дȨ��    ", "           ���ѯ�����������           ", "", "           Y:�鿴      N:ȡ��           ");
			while (true)
			{
				if (KEY_DOWN('Y'))
				{
					ShellExecute(NULL, TEXT("open"), TEXT("http://f-studio.top/help/snake.html"), NULL, NULL, SW_SHOWNORMAL);
					break;
				}
				if (KEY_DOWN('N'))
				{
					break;
				}
			}
			Sleep(200);
			wrong_end();
		}
	}

	gotoxy(26, 20);
	color_out("���ڼ�� ��statistics.ini��                              ", 1);
	for (int i = 0; i <= _rand(2); i++)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
	}

	gotoxy(26, 20);
	color_out("���ڼ�� ��statistics.ini��                              ", 1);
	for (int i = 0; i <= _rand(2) + 1; i++)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
	}
	if ((_access("statistics.ini", 0)) == -1)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
		warning("                �ļ���ʧ                ", "    �޷���.\\���ҵ���statistics.ini��    ", "              �������´���              ", "", "");
		gotoxy(26, 20);
		color_out("���ڴ�����statistics.ini��                              ", 1);
		Sleep(_rand(50) + 50);
		pogress_bar();
		ofstream statistics;
		statistics.open("statistics.ini");
		statistics.close();
		gotoxy(26, 20);
		color_out("���ڳ�ʼ����statistics.ini��                              ", 1);
		Sleep(_rand(50) + 50);
		pogress_bar();
		statistics_initialization();
		Sleep(_rand(50) + 50);
		pogress_bar();
		Sleep(_rand(50) + 50);
		pogress_bar();
		Sleep(_rand(50) + 50);
	}
	if ((_access("statistics.ini", 2)) == -1)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
		warning("             �ļ��޷���д               ", "  ��.\\statistics.ini�������˶�дд����  ", "              ���ڳ��Խ��              ", "", "");
		gotoxy(26, 20);
		system("attrib -r statistics.ini");
		color_out("���ڼ�顰statistics.ini��                              ", 1);
		pogress_bar();
		gotoxy(1, 1);
		gotoxy(1, 1);
		cout << "                                   ";
		Sleep(_rand(50) + 50);
		pogress_bar();
		if ((_access("statistics.ini", 2)) == -1)
		{
			pogress_bar();
			Sleep(200);
			wrong("              ���Խ����Ч              ", "   �޷����衰.\\statistics.ini��дȨ��   ", "           ���ѯ�����������           ", "", "           Y:�鿴      N:ȡ��           ");
			while (true)
			{
				if (KEY_DOWN('Y'))
				{
					ShellExecute(NULL, TEXT("open"), TEXT("http://f-studio.top/help/snake.html"), NULL, NULL, SW_SHOWNORMAL);
					break;
				}
				if (KEY_DOWN('N'))
				{
					break;
				}
			}
			Sleep(200);
			wrong_end();
		}
	}

	gotoxy(26, 20);
	color_out("���ڼ�� ��audio.ini��                              ", 1);
	for (int i = 0; i <= _rand(2); i++)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
	}
	gotoxy(26, 20);
	color_out("���ڼ�� ��audio.ini��                              ", 1);
	for (int i = 0; i <= _rand(2) + 1; i++)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
	}
	if ((_access("audio.ini", 0)) == -1)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
		warning("                �ļ���ʧ                ", "    �޷���.\\���ҵ���audio.ini��       ", "              �������´���              ", "", "");
		gotoxy(26, 20);
		color_out("���ڴ�����audio.ini��                              ", 1);
		Sleep(_rand(50) + 50);
		pogress_bar();
		ofstream audio;
		audio.open("audio.ini");
		audio.close();
		gotoxy(26, 20);
		color_out("���ڳ�ʼ����audio.ini��                              ", 1);
		Sleep(_rand(50) + 50);
		pogress_bar();
		audio_initialization();
		Sleep(_rand(50) + 50);
		pogress_bar();
		Sleep(_rand(50) + 50);
		pogress_bar();
		Sleep(_rand(50) + 50);
	}
	if ((_access("audio.ini", 2)) == -1)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
		warning("             �ļ��޷���д               ", "  ��.\\audio.ini�������˶�дд����  ", "              ���ڳ��Խ��              ", "", "");
		gotoxy(26, 20);
		system("attrib -r audio.ini");
		color_out("���ڼ�顰audio.ini��                              ", 1);
		pogress_bar();
		gotoxy(1, 1);
		gotoxy(1, 1);
		cout << "                                   ";
		Sleep(_rand(50) + 50);
		pogress_bar();
		if ((_access("audio.ini", 2)) == -1)
		{
			pogress_bar();
			Sleep(200);
			wrong("              ���Խ����Ч              ", "   �޷����衰.\\audio.ini��дȨ��   ", "           ���ѯ�����������           ", "", "           Y:�鿴      N:ȡ��           ");
			while (true)
			{
				if (KEY_DOWN('Y'))
				{
					ShellExecute(NULL, TEXT("open"), TEXT("http://f-studio.top/help/snake.html"), NULL, NULL, SW_SHOWNORMAL);
					break;
				}
				if (KEY_DOWN('N'))
				{
					break;
				}
			}
			Sleep(200);
			wrong_end();
		}
	}

	gotoxy(20, 20);
	cout << "                                                      ";
	for (int i = 0; i <= _rand(15) + 5; i++)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
	}

}

void files_read()
{
	hide_mouse();
	system("mode con cols=80 lines=31");
//	windowssize(80, 30);
	Sleep(500);
	system("cls");
	for (int i = 0; i <= _rand(5) + 3; i++)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
	}
	gotoxy(26, 20);
	color_out("����׼����ȡ�ļ������Ժ�...                              ", 1);
	for (int i = 0; i <= _rand(5) + 2; i++)
	{
		pogress_bar();
		Sleep(_rand(100) + 50);
	}

	for (int i = 0; i <= _rand(10) + 5; i++)
	{
		pogress_bar();
		Sleep(_rand(100) + 50);
	}
	gotoxy(26, 20);
	color_out("        ���ڶ�ȡ����                      ", 1);
	pogress_bar();
	Sleep(_rand(70) + 50);
	pogress_bar();
	Sleep(_rand(70) + 50);
	settings_read();
	for (int i = 0; i <= _rand(10) + 5; i++)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
	}

	gotoxy(26, 20);
	color_out("        ���ڶ�ȡͳ��                      ", 1);
	pogress_bar();
	Sleep(_rand(60) + 50);
	pogress_bar();
	Sleep(_rand(60) + 50);
	statistics_read();
	for (int i = 0; i <= _rand(10) + 5; i++)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
	}

	gotoxy(24, 20);
	color_out("        ���ڶ�ȡ��Ƶ��                    ", 1);
	pogress_bar();
	Sleep(_rand(60) + 50);
	pogress_bar();
	Sleep(_rand(60) + 50);
	audio_read();
	for (int i = 0; i <= _rand(10) + 5; i++)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
	}

	gotoxy(24, 20);
	color_out("            ���ڼ���                ", 1);
	statistics_read();
	for (int i = 0; i <= _rand(10) + 2; i++)
	{
		pogress_bar();
		Sleep(_rand(90) + 50);
	}
	pogress_bar();
	Sleep(_rand(50) + 50);
	gotoxy(24, 20);
	color_out("            ���ڼ���                ", 0);
	pogress_bar();
	Sleep(_rand(50) + 50);
	gotoxy(24, 20);
	color_out("            ���ڼ���                ", 2);
	pogress_bar();
	Sleep(_rand(50) + 50);
	gotoxy(24, 20);
	cout << "                                    ";
	for (int i = 0; i <= _rand(5) + 2; i++)
	{
		pogress_bar();
		Sleep(_rand(60) + 50);
	}
	system("cls");
}
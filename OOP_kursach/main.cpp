#pragma warning(disable : 4996)
#include "Header.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

using namespace std;

int main()
{
	system("color F0");
	system("chcp 1251");
	system("cls");
	setlocale(0, "");
	DB_employee a;
	string str,str1,str2;
	while (1)
	{
		cout << "Введите слово или команду\n";
		getline(cin, str);
		if (str == "/end")
			break;
		else if (str == "/help")
			cout << "\n/end - завершение работы\n/add - добавляет слово в словарь\n/clear - затирает словарь (у самурая нет цели, есть только путь)\n/open - открыть словарь (выход из словаря - срелочка вниз, страницы листать на стрелочки вправо/влево)\n\n";
		else if (str == "/add")
		{
			cout << "En: ";
			getline(cin, str1);
			cout << "Rus: ";
			getline(cin, str2);
			word newword(str1, str2);
			a.addWord(newword);
			system("cls");
		}
		else if (str == "/clear")
			a.clear();
		else if (str == "/open")
		{
			int sign, L=0;
			a.print(L, L + 20);
			cout << "страница" << (L + 20) / 20 << "\n";
			while (1)
			{
				sign = getch();

				if (sign == 80)
					break;
				if (sign == 75 &&  L!= 0)
				{
					system("cls");
					L -= 20;
					a.print(L, L+20);
					cout << "страница" << (L + 10) / 10 << "\n";
				}
				else if (sign == 77)
				{
					system("cls");
					L += 20;
					a.print(L, L+20);
					cout << "страница" << (L+10) / 10<<"\n";
				}
			}
			system("cls");
		}
		else if (str=="/delete")
		{
			cout << "Удаляем слово: \nEn: ";
			getline(cin, str1);
			cout << "Rus: ";
			getline(cin, str2);
			word oldword(str1, str2);
			a.del(oldword);
		}
		else
		{
			system("cls");
			cout << str << "\n";
			a.translate(str);
			cout << "\n";
		}
	}
	a.write();
}
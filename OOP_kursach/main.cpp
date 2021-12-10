#pragma warning(disable : 4996)

#include "Header.h"
#include "Classes.h"

using namespace std;

void menu(dictionary& a)
{
	int sign;
	string str1, str2;
	while (1)
	{
		system("cls");
		cout << "1 - открыть словарь\n2 - добавить слово в словарь\n3 - удалить слово из словаря\n3 - очистить соварь\n4 - перевести слово\n";
		sign = getch();
		if (sign == 27)
		{
			a.write();
			return;
		}
			
		if (sign == 1 + '0')
		{
			system("cls");
			int L = 0;
			a.print(L, L + 10);
			cout << "страница" << (L + 10) / 10 << "\n";
			while (1)
			{
				sign = getch();
				if (sign == 27)
					break;
				if (sign == 75 && L != 0)
				{
					system("cls");
					L -= 10;
					a.print(L, L + 10);
					cout << "страница" << (L + 10) / 10 << "\n";
				}
				else if (sign == 77)
				{
					system("cls");
					L += 10;
					a.print(L, L + 10);
					cout << "страница" << (L + 10) / 10 << "\n";
				}
			}
		}
		if (sign == 2 + '0')
		{
			system("cls");
			cout << "En: ";
			getline(cin, str1);
			cout << "Rus: ";
			getline(cin, str2);
			cout << "для отмены - esc\n";
			sign = getch();
			if (sign != 27)
			{
				word newword(str1, str2);
				a.addWord(newword);
			}
			system("cls");
		}
		if (sign == 3 + '0')
		{
			system("cls");
			cout << "У самурая нет цели, есть только путь";
			a.clear();
			sign = getch();
		}
		if (sign == 4 + '0')
		{
			while (1)
			{
				system("cls");
				cout << "Слово: \nEn: ";
				getline(cin, str1);
				cout << str1 << "\n";
				a.translate(str1);
				cout << "\nВернутся в меню - esc\n";
				sign = getch();
				if (sign == 27)
					break;
			}
			
		}
	}
}

int main()
{
	system("color F0");
	system("chcp 1251");
	system("cls");
	setlocale(0, "");
	DB_employee a;
	menu(a);
	int sign = getch();
	if (sign == 9 + '0')
		cout<<"\n" << a.H();
	if (sign == '0')
		a.print_tree();
}

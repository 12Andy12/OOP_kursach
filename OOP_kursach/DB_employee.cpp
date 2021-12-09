#include "Header.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <cassert>

using namespace std;

ostream& operator<< (ostream& out, word point)
{
	return out << point.En() << "-" << point.Rus();
}

void DB_employee::read()
{
	delete Root;
	Root = new tree;
	string str, s1 = "", s2 = "";
	ifstream file("DataBase.dat");
	if (!file.is_open())
		cout << "...file isn't open/n";
	else
	{
		while (!file.eof())
		{
			getline(file, str);
			if (str == "")
				continue;
			int i = 0;
			for (i = 0; i < str.size(); ++i)
			{
				if (str[i] == '-')
					break;
				s1 += str[i];
			}
			for (++i; i < str.size(); ++i)
				s2 += str[i];
			word thisWord(s1, s2);
			AVL_add(thisWord, Root);
			s1 = s2 = "";
		}
	}
	file.close();
}

void DB_employee::write(tree*& r)
{
	ofstream file2("DataBase.dat", ios_base::app);
	if (!file2.is_open())
		cout << "...file is not open/n";
	else
	{
		if(r)
		{
			write(r->left);
			file2 << r->data << "\n";
			//cout << r->data << "\n";
			write(r->right);
		}
	}
	file2.close();
}

void DB_employee::addWord(word newWord)
{
	ofstream file2("DataBase.dat", ios_base::app);
	if (!file2.is_open())
		cout << "...file is not open/n";
	else
	{
		file2 << "\n" << newWord;
		AVL_add(newWord, Root);
	}
	file2.close();
}

void DB_employee::print(tree*& r, int L, int R, int& i)
{
	if (r)
	{
		print(r->left, L, R, ++i);
		if (L <= i && i < R)
			cout << r->data << "\n";
		print(r->right, L, R, ++i);
	}
}
void DB_employee::translate(tree*& root, string s)
{
	if (root == nullptr)
		cout << "Такого слова нет\n";
	else if (root->data.En() > s)
		translate(root->left, s);
	else if (root->data.En() < s)
		translate(root->right, s);
	else if (root->data.En() == s)
		cout<<"перевод: "<<root->data.Rus();
}

bool operator>(word w1, word w2)
{
	if (w1.En() > w2.En())
		return true;
	else if (w1.En() == w2.En() && w1.Rus() > w2.Rus())
		return true;
	else
		return false;
}

bool operator<(word w1, word w2)
{
	if (w1.En() < w2.En())
		return true;
	else if (w1.En() == w2.En() && w1.Rus() < w2.Rus())
		return true;
	else
		return false;
}

bool operator == (word w1, word w2)
{
	if (w1.En() == w2.En() && w1.Rus() == w2.Rus())
		return true;
	else
		return false;
}
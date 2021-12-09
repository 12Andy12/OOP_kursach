#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <cassert>

using namespace std;



class dictionary {
protected:
};

class word{
private:
	string rus;
	string en;
public:
	word(string s1, string s2)
		:en(s1), rus(s2)
	{
	}
	word()
		:en("0"), rus("0")
	{
	}
	string Rus()
	{
		return rus;
	}
	string En()
	{
		return en;
	}
	friend bool operator>(word w1, word w2);
	friend bool operator<(word w1, word w2);
	friend bool operator==(word w1, word w2);
};


class tree {
public:
	tree* left;
	tree* right;
	word data;
	int bal;
	int size = 0;
	tree()
		:left(nullptr), right(nullptr), bal(0), data("0","0"), size(0)
	{
	}
};

ostream& operator<< (ostream& out, word point);
void printbal(tree*& root);
void AVL_del(word x, tree*& root);
void AVL_add(word D, tree*& root);
void printtree(tree*& root);

//DB_emploee===================================================================================

class DB_employee : public dictionary
{
private:
	tree* Root;
public:
	
	void read();
	DB_employee()
	{
		Root = new tree;
		read();
	}
	void write(tree*& r);

	void write()
	{
		ofstream file2("DataBase.dat");
		file2.close();
		write(Root);
	}
	void addWord(word newWord);

	void clear()
	{
		delete Root;
		Root = new tree;
	}

	void print_tree()
	{
		printtree(Root);
	}

	size_t size()
	{
		return Root->size;
	}
	void print(tree*& r, int L, int R, int& i);

	void print(int L, int R)
	{
		int i = 0;
		print(Root, L, R, i);
	}
	void translate(tree*& root, string s);

	void translate(string s)
	{
		translate(Root, s);
	}
	void del(word w)
	{
		AVL_del(w, Root);
	}
};



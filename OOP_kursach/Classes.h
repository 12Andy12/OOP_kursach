#pragma once
#ifndef CLASSES_H
#define CLASSES_H

#include "tree.h"
#include "Header.h"

using namespace std;

class dictionary { 
public:
	virtual void read()
	{
		cout << "error\n";
	}
	virtual void write(tree*& r)
	{
		cout << "error\n";
	}
	virtual void write()
	{
		cout << "error\n";
	}
	virtual void addWord(word newWord)
	{
		cout << "error\n";
	}
	virtual void clear()
	{
		cout << "error\n";
	}
	virtual void print_tree()
	{
		cout << "error\n";
	}
	virtual size_t size() = 0;
	virtual void print(tree*& r, int L, int R, int& i)
	{
		cout << "error\n";
	}
	virtual void print(int L, int R)
	{
		cout << "error\n";
	}
	virtual void translate(tree*& root, string s)
	{
		cout << "error\n";
	}
	virtual void translate(string s)
	{
		cout << "error\n";
	}
	virtual void del(word w)
	{
		cout << "error\n";
	}
};

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
	int H(tree*& root)
	{
		if (root == nullptr)
			return 0;
		else
			return 1 + max(H(root->left), H(root->right));
	}
	int H()
	{
		return H(Root);
	}
};
#endif
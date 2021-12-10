#pragma once
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cassert>
#include <conio.h>
#include <windows.h>

using namespace std;

class word {
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
		:left(nullptr), right(nullptr), bal(0), data("0", "0"), size(0)
	{
	}
};
#endif
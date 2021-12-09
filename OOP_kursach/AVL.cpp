#include "Header.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <cassert>

using namespace std;

void LL(tree*& root)
{
	tree* q = root->left;
	root->bal = 0;
	q->bal = 0;
	root->left = q->right;
	q->right = root;
	root = q;
}

void RR(tree*& root)
{
	tree* q = root->right;
	root->bal = 0;
	q->bal = 0;
	root->right = q->left;
	q->left = root;
	root = q;
}

void LR(tree*& root)
{
	tree* q = root->left;
	tree* r = q->right;
	if (r->bal < 0)
		root->bal = 1;
	else
		root->bal = 0;
	if (r->bal > 0)
		q->bal = -1;
	else
		q->bal = 0;
	r->bal = 0;
	q->right = r->left;
	root->left = r->right;
	r->left = q;
	r->right = root;
	root = r;
}

void RL(tree*& root)
{
	tree* q = root->right;
	tree* r = q->left;
	if (r->bal < 0)
		root->bal = 1;
	else
		root->bal = 0;
	if (r->bal > 0)
		q->bal = -1;
	else
		q->bal = 0;
	r->bal = 0;
	q->left = r->right;
	root->right = r->left;
	r->right = q;
	r->left = root;
	root = r;
}

void AVL_add(word D, tree*& root, bool& rost)
{
	if (root == nullptr || root->size == 0 || root->data.En() == "0")
	{
		root = new tree;
		root->data = D;
		root->size++;
		rost = true;
	}
	else if (root->data.En() > D.En())
	{
		AVL_add(D, root->left, rost);
		if (rost == true) //выросла лева€ ветвь
		{
			if (root->bal > 0) // поддерево сбалансировалось самосто€тельно
			{
				root->bal = 0;
				rost = false;
			}
			else if (root->bal == 0) // добавилс€ нов. эл. слева, но пока все под контролем
			{
				root->bal = -1;
				rost = true;
			}
			else // балансируем поворотами
			{
				if (root->left->bal < 0)
				{
					LL(root);
					rost = false;
				}
				else
				{
					LR(root);
					rost = false;
				}
			}
		}
	}
	else if (root->data.En() <= D.En())
	{
		AVL_add(D, root->right, rost);
		if (rost == true)
		{
			if (root->bal < 0) // поддерево сбалансировалось самосто€тельно
			{
				root->bal = 0;
				rost = false;
			}
			else if (root->bal == 0) // добавилс€ нов. эл. справа, но пока все под контролем
			{
				root->bal = 1;
				rost = true;
			}
			else // балансируем поворотами
			{
				if (root->right->bal > 0)
				{
					RR(root);
					rost = false;
				}
				else
				{
					RL(root);
					rost = false;
				}
			}
		}
	}
	else
		return;
}




void AVL_add(word D, tree*& root)
{
	bool rost = false;
	AVL_add(D, root, rost);
}

void LL1(tree*& root, bool& umen)
{
	tree* q = root->left;
	if (q->bal == 0)
	{
		q->bal = 1;
		root->bal = -1;
		umen = false;
	}
	else
	{
		q->bal = 0;
		root->bal = 0;
	}
	root->left = q->right;
	q->right = root;
	root = q;
}

void RR1(tree*& root, bool& umen)
{
	tree* q = root->right;
	if (q->bal == 0)
	{
		q->bal = 1;
		root->bal = -1;
		umen = false;
	}
	else
	{
		q->bal = 0;
		root->bal = 0;
	}
	root->right = q->left;
	q->left = root;
	root = q;
}

void BL(tree*& root, bool& umen)
{
	if (root->bal == -1)
		root->bal = 0;
	else if (root->bal == 0)
	{
		root->bal = 1;
		umen = false;
	}
	else if (root->bal == 1)
	{
		if (root->right->bal >= 0)
			RR1(root, umen);
		else
			RL(root);
	}
}

void BR(tree*& root, bool& umen)
{
	if (root->bal == 1)
		root->bal = 0;
	else if (root->bal == 0)
	{
		root->bal = -1;
		umen = false;
	}
	else if (root->bal == -1)
	{
		if (root->left->bal <= 0)
			LL1(root, umen);
		else
			LR(root);
	}
}

void DEL(tree*& temp, tree*& root, bool& umen)
{
	if (temp->right != nullptr)
	{
		DEL(temp->right, root, umen);
		if (umen == true)
			BR(temp, umen);
	}
	else
	{
		root->data = temp->data;
		root = temp;
		temp = temp->left;
		umen = true;
	}
}

void AVL_del(word x, tree*& root, bool& umen)
{
	if (root == nullptr)
	{

		cout << "такого слова нет\n";
		return;
	}
	else if (root->data > x)
	{
		AVL_del(x, root->left, umen);
		if (umen == true)
			BL(root, umen);
	}
	else if (root->data < x)
	{
		AVL_del(x, root->right, umen);
		if (umen == true)
			BR(root, umen);
	}
	else if (root->data == x)
	{
		tree* q = root;
		if (q->right == nullptr)
		{
			root = q->left;
			umen = true;
		}
		if (q->left == nullptr)
		{
			root = q->right;
			umen = true;
		}
		else
		{
			DEL(q->left, q, umen);
			if (umen == true)
				BL(root, umen);
		}
	}
}

void AVL_del(word x, tree*& root)
{
	bool umen = false;
	AVL_del(x, root, umen);
}

void printbal(tree*& root, int r)
{
	if (root)
	{
		printbal(root->right, r + 1);
		for (int i = 0; i < r; ++i)
			cout << "\t";
		cout << root->bal << "\n";
		printbal(root->left, r + 1);
	}
}

void printbal(tree*& root)
{
	printbal(root, 0);
}

void printtree(tree*& root, int r)
{
	if (root)
	{
		printtree(root->right, r + 1);
		for (int i = 0; i < r; ++i)
			cout << "\t\t";
		cout << root->data << "\n";
		printtree(root->left, r + 1);
	}
}

void printtree(tree*& root)
{
	printtree(root, 0);
}
#pragma once
#ifndef HEADER_H
#define HEADER_H

#include "tree.h"

using namespace std;

ostream& operator<< (ostream& out, word point);
void AVL_del(word x, tree*& root);
void AVL_add(word D, tree*& root);
void printtree(tree*& root);

#endif




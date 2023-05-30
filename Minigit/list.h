#pragma once
#include"node.h"
class list
{
public:
	node* first;
	node* last;
	string branch_path_1;
	list();
	void build_list(string x);
	void read_locals();
	bool validare(string y);
	void reset();
	void read_commits();
	int get_length();
	bool validare_for_push(string x);
};


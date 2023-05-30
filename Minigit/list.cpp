#include "list.h"
#include<fstream>
using namespace std;

list::list()
{
	this->first = NULL;
	this->last = NULL;
}

void list::build_list(string x)
{
	node* p = new node();
	p->node_name = x;
	p->next=NULL;
	if (this->first == NULL)
	{
		first = p;
		last = p;
	}
	else
	{
		last->next = p;
		last = p;
	}
}

void list::read_locals()
{
	ifstream j;
	j.open("branch_path.txt");
	string text_j;
	text_j.assign((istreambuf_iterator<char>(j)), istreambuf_iterator<char>());
	branch_path_1 = text_j;
	string aux_2= "local_files.txt";
	string aux_3 = branch_path_1 + aux_2;
	ifstream g;
	string file;
	g.open(aux_3, ios::app);
	while (g >> file)
	{
		build_list(file);
	}
}

bool list::validare(string y)
{
	node* p = this->first;
	while (p)
	{
		if (p->node_name == y)
			return true;
		p = p->next;
	}
	return false;
}

void list::reset()
{
	this->first = NULL;
	this->last = NULL;
}

void list::read_commits()
{
	ifstream j;
	j.open("branch_path.txt");
	string text_j;
	text_j.assign((istreambuf_iterator<char>(j)), istreambuf_iterator<char>());
	branch_path_1 = text_j;
	string aux_2 = "commits.txt";
	string aux_3 = branch_path_1 + aux_2;
	ifstream g;
	string file;
	g.open(aux_3, ios::app);
	while (g >> file)
	{
		build_list(file);
	}
}

int list::get_length()
{
	int counter = 0;
	node* p = this->first;
	while (p)
	{
		counter++;
		p = p->next;
	}
	return counter;
}

bool list::validare_for_push(string x)
{
	ifstream f;
	f.open("../remote/commits_remote.txt",ios::app);
	string text;
	text.assign((istreambuf_iterator<char>(f)), istreambuf_iterator<char>());
	size_t found = text.find(x);
	if (found != string::npos)
	{
		return true;
	}
	return false;
	f.close();
}




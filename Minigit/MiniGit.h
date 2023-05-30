#pragma once
#include"list.h"
#include<fstream>
#include<iostream>
#include<string>
#include<cstring>
#include<direct.h>
#include<ctime>
#include<cstring>
#include"singleton.h"
using namespace std;
class MiniGit
{
private:
	list local_sources;
	list local_commits;
	int count = 0;
	string branch_path;
public:
	void init();
	void add(string x);
	void commit(string x);
	void push_origin();
	void log(string file_path);
	void pull(string remote_location, string commit_name);
	void branch(string branch_name);
	void checkout(string branch_name);

};


#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class singleton
{
public:
	static singleton& getInstance();
	static void destroyInstance();
	void print(string);
	
private:
	static singleton* instance;

	singleton() {};
	singleton(const singleton&) {};
	~singleton() {};
};


#include "singleton.h"

singleton* singleton::instance = nullptr;

singleton& singleton::getInstance()
{
	if (!singleton::instance)
	{
		singleton::instance = new singleton();
	}
	return *singleton::instance;
}

void singleton::destroyInstance()
{
	if (singleton::instance)
	{
		delete singleton::instance;
		singleton::instance = nullptr;
	}
}

void singleton::print(string x)
{
	ofstream f;
	f.open("agenda.log",ios::app);//aceasta este agenda in care vreau sa monitorizez tot ce se intampla in Minigit.De ex: adaugari,push-origin etc.
	f << x << endl;
}



#pragma once
class librarie
{
private:
	char nume_autorp[10];
	char nume_carte[10];
	char nume_autors[10];
	int nr_pagini;
	int pret;
public:
	void set_nume_autorp(const char* den_autorp);
	void set_nume_carte( const char* den_numecarte);
	void set_nume_autors(const char* den_autors);
	void set_nr_pagini(int nr);
	void set_pret(int pr);
	void afisare();

};
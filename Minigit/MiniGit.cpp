#include "MiniGit.h"




void MiniGit::init()
{
	singleton::getInstance().print("MiniGit a fost initiat.");
	if (_mkdir("../local") != 0)
		cout << endl << "FISIERUL LOCAL DEJA DESCHIS!"<<endl;
	else
	{
		_mkdir("../local");
		ofstream j;
		j.open("branch_path.txt");
		j << "../local/";
	}
	if (_mkdir("../remote") != 0)
		cout << endl << "FISIER REMOTE DEJA DESCHIS!"<<endl;
	else
		_mkdir("../remote");

}

void MiniGit::add(string x)
{
	ifstream j;
	j.open("branch_path.txt");
	string text_j;
	text_j.assign((istreambuf_iterator<char>(j)), istreambuf_iterator<char>());
	branch_path = text_j;
	singleton::getInstance().print("S-a adaugat un fisier nou.");
	this->local_sources.reset();
	this->local_sources.read_locals();
	if (this->local_sources.validare(x)==0)
	{
		ofstream f;
		string aux_1 = "local.git";
		string aux_2 = branch_path + aux_1;
		f.open(aux_2, ios::app);
		f << x << endl;
		time_t timer = time(nullptr);
		f << timer<<endl;
		ofstream g;
		string aux_3 = "local_files.txt";
		string aux_4 = branch_path + aux_3;
		g.open(aux_4, ios::app);
		g << x<<endl;
	}
}

void MiniGit::commit(string x)
{
	ifstream j;
	j.open("branch_path.txt");
	string text_j;
	text_j.assign((istreambuf_iterator<char>(j)), istreambuf_iterator<char>());
	branch_path = text_j;
	singleton::getInstance().print("S-a creat un commit nou.");
	this->local_commits.reset();
	this->local_commits.read_commits();
	if (this->local_commits.validare(x) == 0)
	{
		ofstream h;
		string aux_5 = "commits.txt";
		string aux_6 = branch_path + aux_5;
		h.open(aux_6, ios::app);
		h << x << endl;
		this->local_sources.reset();
		this->local_sources.read_locals();
		node* p = this->local_sources.first;
		ofstream g;
		string aux = branch_path;
		aux = aux + x;
		aux = aux + ".commit";
		g.open(aux, ios::app);
		g << x << endl;
		g << this->local_sources.get_length() << endl;
		while (p)
		{
			ifstream f;
			f.open(p->node_name, ios::app);
			string text;
			text.assign((istreambuf_iterator<char>(f)), istreambuf_iterator<char>());
			g << p->node_name << endl;
			g << text.size() << endl<<"CONTENT OF FILE"<<endl;
			g << text << endl;
			p = p->next;
		}
	}
}

void MiniGit::push_origin()
{
	singleton::getInstance().print("Functia Push Origin a fost apelata.");
	ofstream c;
	c.open("../remote/commits_remote.txt", ios::app);
	this->local_commits.reset();
	this->local_commits.read_commits();
	node* p = this->local_commits.first;
	while (p)
	{
		if (this->local_commits.validare_for_push(p->node_name) == 0)
		{
			c << p->node_name << endl;
			string aux = "../local/";
			aux = aux + p->node_name;
			aux = aux + ".commit";
			ifstream g;
			g.open(aux, ios::app);
			string text;
			text.assign((istreambuf_iterator<char>(g)), istreambuf_iterator<char>());
			string path_aux = "../remote/";
			path_aux = path_aux + p->node_name;
			path_aux = path_aux + ".commit";
			ofstream h;
			h.open(path_aux, ios::app);
			h << text;
		}
		p = p->next;
	}
}

void MiniGit::log(string filepath)
{
	singleton::getInstance().print("Functia Log a fost apelata.");
	ifstream f;
	filepath = filepath + "/commits_remote.txt";
	f.open(filepath);
	string text;
	text.assign((istreambuf_iterator<char>(f)), istreambuf_iterator<char>());
	cout << text;
}

void MiniGit::pull(string remote_location, string commit_name)
{
	singleton::getInstance().print("Functia Pull a fost apelata.");
	_mkdir("../TemaPOO2");
	string path;
	path = path + remote_location;
	path = path + "/";
	path = path + commit_name;
	path = path + ".commit";
	ifstream f;
	f.open(path);
	string aux_3;
	f >> aux_3;
	int number_of_files;
	f >> number_of_files;
	while ((!f.eof())&&(number_of_files>0))
	{
		string source_name;
		int number_of_characters;
		f >> source_name;
		f >> number_of_characters;
		string aux_1;
		f >> aux_1;
		f >> aux_1;
		f >> aux_1;
		char aux;
		ofstream g;
		string path_aux = "../TemaPOO2/";
		path_aux = path_aux + source_name;
		g.open(path_aux);
		int counter_1 = 0;
		while (counter_1 <= number_of_characters)
		{
			f.get(aux);
			g << aux;
			counter_1++;
		}
		number_of_files--;
	}
}

void MiniGit::branch(string branch_name)
{
	singleton::getInstance().print("Un branch nou a fost creat.");
	string aux_1 = "../";
	string aux_2 = aux_1 + branch_name;
	_mkdir(aux_2.c_str());
	string aux_x = "/";
	string aux_y = aux_2 + aux_x;
	string aux_3 = "local";
	aux_y = aux_y + aux_3;
	aux_y = aux_y + aux_x;
	string aux_4;
	string aux_o = "/";
	aux_4 = aux_2 + aux_o;
	aux_4 = aux_4 + aux_3;
	_mkdir(aux_4.c_str());
	

	ifstream a;
	a.open("../local/local_files.txt");
	string text_a;
	text_a.assign((istreambuf_iterator<char>(a)), istreambuf_iterator<char>());
	ofstream a_prim;
	string a_aux_1 = "local_files.txt";
	string a_aux_2 = aux_y + a_aux_1;
	a_prim.open(a_aux_2);
	a_prim << text_a;

	ifstream b;
	b.open("../local/commits.txt");
	string text_b;
	text_b.assign((istreambuf_iterator<char>(b)), istreambuf_iterator<char>());
	ofstream b_prim;
	string b_aux_1 = "commits.txt";
	string b_aux_2 = aux_y + b_aux_1;
	b_prim.open(b_aux_2);
	b_prim << text_b;
	b.close();


	ifstream c;
	c.open("../local/local.git");
	string text_c;
	text_c.assign((istreambuf_iterator<char>(c)), istreambuf_iterator<char>());
	ofstream c_prim;
	string c_aux_1 = "local.git";
	string c_aux_2 = aux_y + c_aux_1;
	c_prim.open(c_aux_2);
	c_prim << text_c;


	this->local_commits.reset();
	this->local_commits.read_commits();

	ifstream d;
	string d_aux_1 = this->local_commits.last->node_name;
	string d_aux_2 = "../local/";
	string d_aux_3 = d_aux_2 + d_aux_1;
	string d_aux_5 = ".commit";
	string d_aux_6 = d_aux_3 + d_aux_5;
	d.open(d_aux_6);
	string text_d;
	text_d.assign(istreambuf_iterator<char>(d), istreambuf_iterator<char>());
	ofstream d_prim;
	string d_aux_4 = aux_y + d_aux_1;
	string d_aux_4_prim = ".commit";
	string d_aux_4_secund = d_aux_4 + d_aux_4_prim;
	d_prim.open(d_aux_4_secund);
	d_prim << text_d;

}

void MiniGit::checkout(string branch_name)
{
	singleton::getInstance().print("Un checkout a fost realizat.");
	ofstream f;
	f.open("branch_path.txt");
	f.close();
	ofstream g;
	g.open("branch_path.txt");
	string aux_1 = "../";
	string aux_2 = aux_1 + branch_name;
	string aux_x = "/";
	string aux_y = aux_2 + aux_x;
	string aux_3 = "local";
	aux_y = aux_y + aux_3;
	aux_y = aux_y + aux_x;
	g << aux_y;
}



#include "menu.h"

void menu::show_menu()
{
	system("color 75");
	cout << "Bine ati venit in MiniGit!" << endl << "Momentan aveti la dispozitie urmatoarele functii(comenzile trebuie scrise exact ca in exemplele numerotate) :) :" << endl;
	cout << "1) Minigit init " << endl << "2) Minigit add <filename> (with his extension) " << endl << "3) Minigit commit <commit_name> (without any extension after the name) " << endl << "4) Minigit push origin" <<endl<< "5) Minigit log <remote_location>" << endl << "6) Minigit pull <remote_location> <commit_name> (without the extension of the commit) "<<endl<<"7) Minigit branch <branch_name> "<<endl<<"8) Minigit checkout <branch_name> "<<endl<<"9) exit"<<endl<<endl<<"------------------------------------------------"<<endl;

}

void menu::use_menu()
{
	string part_1, part_2, part_3, part_4;
	part_1 = "0";
	part_2 = "0";
	part_3 = "0";
	part_4 = "0";
	cin >> part_1;
	while (part_2 != "exit")
	{
		if (part_2 == "init")
		{
			x.init();
			cin >> part_1;
		}
		if (part_1 == "exit")
		{
			break;
			cout << endl << "Ati inchis functiunile programului.";
		}
		if (part_2 == "add")
		{
			cin >> part_3;
			x.add(part_3);
			cin >> part_1;
		}
		if (part_1 == "exit")
		{
			break;
			cout << endl << "Ati inchis functiunile programului.";
		}
		if (part_2 == "commit")
		{
			cin >> part_3;
			x.commit(part_3);
			cin >> part_1;
		}
		if (part_1 == "exit")
		{
			break;
			cout << endl << "Ati inchis functiunile programului.";
		}
		if (part_2 == "push")
		{
			cin >> part_3;
			x.push_origin();
			cin >> part_1;
		}
		if (part_1 == "exit")
		{
			break;
			cout << endl << "Ati inchis functiunile programului.";
		}
		if (part_2 == "log")
		{
			cin >> part_3;
			x.log(part_3);
			cin >> part_1;
		}
		if (part_1 == "exit")
		{
			break;
			cout << endl << "Ati inchis functiunile programului.";
		}
		if (part_2 == "pull")
		{
			cin >> part_3;
			cin >> part_4;
			x.pull(part_3, part_4);
			cin >> part_1;
		}
		if (part_1 == "exit")
		{
			break;
			cout << endl << "Ati inchis functiunile programului.";
		}
		if (part_2 == "branch")
		{
			cin >> part_3;
			x.branch(part_3);
			cin >> part_1;
		}
		if (part_1 == "exit")
		{
			break;
			cout << endl << "Ati inchis functiunile programului.";
		}
		if (part_2 == "checkout")
		{
			cin >> part_3;
			x.checkout(part_3);
			cin >> part_1;
		}
		if (part_1 == "exit")
		{
			break;
			cout << endl << "Ati inchis functiunile programului.";
		}
		cin >> part_2;
	}
}

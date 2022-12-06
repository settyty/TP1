#include "lib.h"
using namespace std;
void Menu::main_menu()
{
	while (exit == 1)
	{
		switch (show_options())
		{
		case 1:
			show_all_Ships();
			break;
		case 2:
			change_data();
			break;
		case 3:
			add_new();
			break;
		case 4:
			save_to_file();
			break;
		case 5:
			load_from_file();
			break;
		case 6:
			delete_Ship();
			break;
		case 7:
			findSpeedSame();
			break;
		default:
			exit_from_programm();
			break;
		}
	}
}
void Menu::findSpeedSame()
{
	string a;
	cout << "\nEnter the speed" << endl;
	cin >> a;
	if (list.get_size() == 0)
	{
		return;
	}
	for (int i = 0; i < list.get_size(); i++)
	{
		if ((list[i]->SameSpeed(a)) == true) list[i]->show();
	}
	system("pause");
}
int Menu::show_options()
{
	int c1;
	system("cls");
	cout << "\nSelect the menu item" << endl;
	cout << "1 - Show all" << endl;
	cout << "2 - Edit" << endl;
	cout << "3 - Add" << endl;
	cout << "4 - Save to the file" << endl;
	cout << "5 - Load from the file" << endl;
	cout << "6 - Delete" << endl;
	cout << "7 - Search ships with equal speed" << endl;
	cout << "0 - Exit" << endl;
	cout << "-> ";
	cin >> c1;
	return c1;
}
void Menu::show_all_Ships()
{
	system("cls");
	try
	{
		if (list.get_size() == 0)
		{
			throw "There's no ships";
		}
		for (int i = 0; i < list.get_size(); i++)
		{
			cout << "_" << endl;
			cout << i + 1 << "|";
			list[i]->show();
		}
	}
	catch (const char* ex) { cout << ex << endl; }
	system("pause");
}
void Menu::change_data()
{
	int c2, c3;
	system("cls");
	try
	{
		cout << "What do you want to edit? " << list.get_size() << endl;
		cin >> c2;
		if ((c2 < 1) || (c2 > list.get_size()))
		{
			throw "Error!";
		}
		list[c2 - 1]->show();
		cout << "What string do you want to edit?" << endl;
		cout << "-> ";
		cin >> c3;
		cin.ignore(32767, '\n');
		cout << "What do you want to enter here?" << endl;
		cout << "-> ";
		if (c3 == 5)
		{
			bool fl = false;
			while (fl == false)
			{
				try
				{
					getline(cin, redact);
					float f = stof(redact);
					fl = true;
				}
				catch (...)
				{
					cout << "Enter the number" << endl;
				}
			}
			list[c2 - 1]->redact_str(c3, redact);
		}
		else
		{
			getline(cin, redact);
			list[c2 - 1]->redact_str(c3, redact);
			cout << "Edited" << endl;
		}
	}
	catch (const char* ex) { cout << ex << endl; }
	system("pause");
}
void Menu::add_new()
{
	int c2;
	system("cls");
	cout << "\nWhat ship do you want to add?" << endl;
	cout << "1 - Submarine" << endl;
	cout << "2 - Sailboat" << endl;
	cout << "3 - Speedboat" << endl;
	cout << "0 - Cancel" << endl;
	cout << "-> ";
	cin >> c2;
	switch (c2)
	{
	case 1:
		Submarine * sub;
		sub = new Submarine;
		Ships = sub;
		sub->rewrite();
		list.insert(Ships);
		cout << "She has been added" << endl;
		break;
	case 2:
		Sailboat * sail;
		sail = new Sailboat;
		Ships = sail;
		sail->rewrite();
		list.insert(Ships);
		cout << "She has been added" << endl;
		break;
	case 3:
		Speedboat * speedB;
		speedB = new Speedboat;
		Ships = speedB;
		speedB->rewrite();
		list.insert(Ships);
		cout << "She has been added" << endl;
		break;
	default:
		break;
	}
	system("pause");
}
void Menu::save_to_file()
{
	system("cls");
	try
	{
		if (list.get_size() == 0)
		{
			throw "There's nothing to save";
		}
		list.save();
		cout << "It has been saved" << endl;
	}
	catch (const char* ex) { cout << ex << endl; }
	system("pause");
}
void Menu::load_from_file()
{
	system("cls");
	try
	{
		list.load();
		cout << "It has been downloaded" << endl;
	}
	catch (const char* ex) { cout << ex << endl; }
}
void Menu::delete_Ship()
{
	int c2;
	system("cls");
	cout << "What do you want to delete? " << list.get_size() << endl;
	for (int i = 0; i < list.get_size(); i++)
	{
		cout << "_" << endl;
		cout << i + 1 << "|";
		list[i]->show();
	}
	cout << "-> ";
	cin >> c2;
	c2 = list.get_size() - c2 + 1;
	try {
		if ((c2 < 1) || (c2 > list.get_size()))
		{
			throw "Invalid number";
		}
		list.remove(c2 - 1);
		cout << "Wasted" << endl;
		system("pause");
	}
	catch (const char* i)
	{
		cout << i << endl;
	}
}
void Menu::exit_from_programm()
{
	exit = 0;
}
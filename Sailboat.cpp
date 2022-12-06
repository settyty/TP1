#include "lib.h"
using namespace std;
Sailboat::Sailboat()
{
	cout << "Constructor Sailboat without attributes was called." << endl;
}
Sailboat::~Sailboat()
{
	cout << "Destructor Sailboat was called." << endl;
}
Sailboat::Sailboat(const Sailboat& Sailboat_copy)
{
	name = Sailboat_copy.name;
	type = Sailboat_copy.type;
	purpose = Sailboat_copy.purpose;
	length = Sailboat_copy.length;
	crew = Sailboat_copy.crew;
	speed = Sailboat_copy.speed;
}
Sailboat::Sailboat(string name)
{
	this->name = name;
}
string Sailboat::get_name() const { return name; }
void Sailboat::set_name(string name_ch) { name = name_ch; }
string Sailboat::get_type() const { return type; }
void Sailboat::set_type(string type_ch) { type = type_ch; }
string Sailboat::get_purpose() const { return purpose; }
void Sailboat::set_purpose(string purpose_ch) { purpose = purpose_ch; }
string Sailboat::get_length() const { return length; }
void Sailboat::set_length(string length_ch) { length = length_ch; }
string Sailboat::get_crew() const { return crew; }
void Sailboat::set_crew(string crew_ch) { crew = crew_ch; }
string Sailboat::get_speed() const { return speed; }
void Sailboat::set_speed(string speed_ch) { speed = speed_ch; }
bool Sailboat::SameSpeed(string SS_ch) {
	if (SS_ch == (this->get_speed()))
		return true;
	else return false;
}
void Sailboat::show()
{
	cout << "------------------------------------" << endl;
	cout << "Ship: Sailboat" << endl;
	cout << "Name: " << name << endl;
	cout << "Type: " << type << endl;
	cout << "Purpose (mil or civil): " << purpose << endl;
	cout << "Length:" << length << endl;
	cout << "Amount of crew: " << crew << endl;
	cout << "Speed: " << speed << endl;
	cout << "------------------------------------" << endl;
}
void Sailboat::rewrite()
{
	cout << "------------------------------------" << endl;
	cin.ignore(32767, '\n');
	cout << "Ship: Sailboat" << endl;
	cout << "Enter the new name: ";
	getline(cin, name);
	cout << "Enter the new type: ";
	getline(cin, type);
	cout << "Enter the new purpose (mil or civil): ";
	getline(cin, purpose);
	cout << "Enter the new length: ";
	getline(cin, length);
	cout << "Enter the new amount of crew: ";
	getline(cin, crew);
	cout << "Enter the new speed: ";
	getline(cin, speed);
	cout << "------------------------------------" << endl;
}
void Sailboat::saving()
{
	setlocale(LC_ALL, "Russian");
	ofstream outfile;
	string initfile = "Ships.txt";
	outfile.open(initfile, ios_base::app);
	if (!outfile)
	{
		throw "Error of the file";
		system("pause");
		exit(1);
	}
	else
	{
		outfile << 2 << endl << name << endl << type << endl << purpose << endl << length <<
			endl << crew << endl << speed << endl;
		outfile.close();
	}
}
void Sailboat::redact_str(int num_str, string red_str)
{
	switch (num_str)
	{
	case 1:
		this->name = red_str;
		break;
	case 2:
		this->type = red_str;
		break;
	case 3:
		this->purpose = red_str;
		break;
	case 4:
		this->length = red_str;
		break;
	case 5:
		this->crew = red_str;
		break;
	case 6:
		this->speed = red_str;
		break;
	default:
		throw "Invalid menu item";
		break;
	}
}

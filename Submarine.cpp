#include "lib.h"

using namespace std;
Submarine::Submarine()
{
	cout << "Constructor Submarine without attributes was called." << endl;
}
Submarine::~Submarine()
{
	cout << "Destructor Submarine was called." << endl;
}
Submarine::Submarine(const Submarine& Submarine_copy)
{
	length = Submarine_copy.length;
	width = Submarine_copy.width;
	crew = Submarine_copy.crew;
	time = Submarine_copy.time;
	armament = Submarine_copy.armament;
	speed = Submarine_copy.speed;
}
Submarine::Submarine(string length)
{
	this->length = length;
}
string Submarine::get_length() const { return length; }
void Submarine::set_length(string length_ch) { length = length_ch; }
string Submarine::get_width() const { return width; }
void Submarine::set_width(string width_ch) { width = width_ch; }
string Submarine::get_crew() const { return crew; }
void Submarine::set_crew(string crew_ch) { crew = crew_ch; }
string Submarine::get_time() const { return time; }
void Submarine::set_time(string time_ch) { time = time_ch; }
string Submarine::get_armament() const { return armament; }
void Submarine::set_armament(string armament_ch) { armament = armament_ch; }
string Submarine::get_speed() const { return speed; }
void Submarine::set_speed(string speed_ch) { speed = speed_ch; }
bool Submarine::SameSpeed(string SS_ch) {
	if (SS_ch == (this->get_speed()))
		return true;
	else return false;
}
void Submarine::show()
{
	cout << "------------------------------------" << endl;
	cout << "�������: ��������� �����" << endl;
	cout << "�����: " << length << endl;
	cout << "������: " << width << endl;
	cout << "���������� ������ �������: " << crew << endl;
	cout << "������������ ����� ���������� ��� ����� (���): " << time << endl;
	cout << "����������: " << armament << endl;
	cout << "��������: " << speed << endl;
	cout << "------------------------------------" << endl;
}
void Submarine::rewrite()
{
	cout << "------------------------------------" << endl;
	cin.ignore(32767, '\n');
	cout << "�������: ��������� �����" << endl;
	cout << "������� ����� �����: ";
	getline(cin, length);
	cout << "������� ����� ������: ";
	getline(cin, width);
	cout << "������� ����� ���������� ������ �������: ";
	getline(cin, crew);
	cout << "������� ����� ������������ ����� ���������� ��� ����� (���): ";
	getline(cin, time);
	cout << "������� ����� ����������: ";
	getline(cin, armament);
	cout << "������� ����� ��������: ";
	getline(cin, speed);
	cout << "------------------------------------" << endl;
}
void Submarine::saving()
{
	ofstream outfile;
	string initfile = "Ships.txt";
	outfile.open(initfile, ios_base::app);
	if (!outfile)
	{
		throw "������!";
		system("pause");
		exit(1);
	}
	outfile << 1 << endl << length << endl << width << endl << crew << endl << time << endl <<
		armament << endl << speed << endl;
	outfile.close();

}
void Submarine::redact_str(int num_str, string red_str)
{
	switch (num_str)
	{
	case 1:
		this->length = red_str;
		break;
	case 2:

		break;
	case 3:
		this->crew = red_str;

		break;
	case 4:
		this->time = red_str;

		break;
	case 5:
		this->armament = red_str;

		break;
	case 6:
		this->speed = red_str;
		break;
	default:
		throw "������ ������ ����!";
		break;
	}
}
#include "lib.h"
using namespace std;
Speedboat::Speedboat()
{
	cout << "Constructor Speedboat without attributes was called." << endl;
}
Speedboat::~Speedboat()
{
	cout << "Destructor Speedboat was called." << endl;
}
Speedboat::Speedboat(const Speedboat& Speedboat_copy)
{
	capacity = Speedboat_copy.capacity;
	material = Speedboat_copy.material;
	purpose = Speedboat_copy.purpose;
	speed = Speedboat_copy.speed;
}
Speedboat::Speedboat(string type)
{
	this->capacity = type;
}
string Speedboat::get_capacity() const { return capacity; }
void Speedboat::set_capacity(string capacity_ch) { capacity = capacity_ch; }
string Speedboat::get_material() const { return material; }
void Speedboat::set_material(string material_ch) { material = material_ch; }
string Speedboat::get_purpose() const { return purpose; }
void Speedboat::set_purpose(string purpose_ch) { purpose = purpose_ch; }
string Speedboat::get_speed() const { return speed; }
void Speedboat::set_speed(string speed_ch) { material = speed_ch; }
bool Speedboat::SameSpeed(string SS_ch) {
	if (SS_ch == (this->get_speed()))
		return true;
	else return false;
}
void Speedboat::show()
{
	cout << "------------------------------------" << endl;
	cout << "Корабль: Скоростной катер" << endl;
	cout << "Вместимость: " << capacity << endl;
	cout << "Материал: " << material << endl;
	cout << "Цель: " << purpose << endl;
	cout << "Скорость: " << speed << endl;
	cout << "------------------------------------" << endl;
}
void Speedboat::rewrite()
{
	cout << "------------------------------------" << endl;
	cin.ignore(32767, '\n');
	cout << "Корабль: Скоростной катер" << endl;
	cout << "Введите новую вместимость: ";
	getline(cin, capacity);
	cout << "Введите новый материал: ";
	getline(cin, material);
	cout << "Введите новую цель: ";
	getline(cin, purpose);
	cout << "Введите новую скорость: ";
	getline(cin, speed);
	cout << "------------------------------------" << endl;
}
void Speedboat::saving()
{
	ofstream outfile;
	string initfile = "Ships.txt";
	outfile.open(initfile, ios_base::app);
	if (!outfile)
	{
		throw "Error of the file";
		system("pause");
		exit(1);
	}
	outfile << 3 << endl << capacity << endl << material << endl << purpose << endl << speed << endl;
	outfile.close();

}
void Speedboat::redact_str(int num_str, string red_str)
{
	switch (num_str)
	{
	case 1:
		this->capacity = red_str;
		break;
	case 2:
		this->material = red_str;
		break;
	case 3:
		this->purpose = red_str;
		break;
	case 4:
		this->speed = red_str;
		break;
	default:
		throw "Error of the menu item";
		break;
	}
}
#pragma warning( disable : 6386 )
#pragma warning( disable : 26451 )
#include "lib.h"
using namespace std;
Keeper::Keeper() : m_size(0), head(nullptr) {}
Keeper::Keeper(int size) : head(nullptr) { this->m_size = size; }
Keeper::~Keeper()
{
	if (head != NULL)
	{
		Elem* buffer;
		while (head->next != NULL)
		{
			buffer = head;
			head = head->next;
			buffer->m_data->~Ship();
			delete(buffer);
		}
		head->m_data->~Ship();
		delete(head);
	}
}
Ship* Keeper::operator[](const int index)
{
	if ((index >= m_size) || index < 0)
	{
		throw "Invalid index";
	}
	else
	{
		Elem* buffer = head;
		for (int i = 0; i < m_size - index - 1; i++)
		{
			buffer = buffer->next;
		}
		return (buffer->m_data);
	}
}
int Keeper::get_size() { return m_size; }
void Keeper::insert(Ship* new_data)
{
	Elem* tmp;
	tmp = new Elem;
	if (m_size == 0)
	{
		tmp->m_data = new_data;
		tmp->next = 0;
		++m_size;
	}
	else
	{
		tmp->m_data = new_data;
		tmp->next = head;
		++m_size;
	}
	head = tmp;
}
void Keeper::remove(int index)
{
	if ((head != NULL) && (index < m_size) && (index >= 0)) // если по этому номеру что-то лежит и этот элемент внутри списка
	{
		// Mass - объекты, которые хранятся в списке
		Elem* tmonst = head, * helping = head;
		for (int i = 0; i < index; i++)
		{
			helping = tmonst; // предыдущее значение
			tmonst = tmonst->next;
		}
		if (tmonst == head) // если элемент который надо удалить первый
		{
			head = tmonst->next;
		}
		else
		{
			helping->next = tmonst->next;
		}
		tmonst->m_data->~Ship();
		delete(tmonst);
		m_size--; // уменьшаем размер списка
	}
}
void Keeper::save()
{

	ofstream outfile;
	string initfile = "Ships.txt";
	outfile.open(initfile);
	if (!outfile)
	{
		throw "File opening error";
		system("pause");
		exit(1);
	}
	else
	{
		outfile << m_size << endl;
		outfile.close();
	}
	Elem* buffer = head;
	for (int i = 0; i < m_size; i++)
	{
		buffer->m_data->saving();
		buffer = buffer->next;
	}
	system("Ships.txt");
}
void Keeper::load()
{

	if (m_size != 0)
	{
		Elem* buffer;
		while (head->next != NULL)
		{
			buffer = head;
			head = head->next;
			buffer->m_data->~Ship();
			delete(buffer);
		}
		head->m_data->~Ship();
		delete(head);
	}
	ifstream infile;
	int read_size, num_Ship; //переменная читки размера и корабля
	string a, b, c, d, e, f, j; //считываемые строки
	string initfile = "Ships.txt";
	Ship* Ships;
	infile.open(initfile);
	if (!infile)
	{
		throw "File opening error";
		system("pause");
		exit(1);
	}
	infile >> read_size; //читаем кол-во 
	for (int i = 0; i < read_size; i++)
	{
		infile >> num_Ship; //читаем номер
		infile.ignore(32767, '\n');
		if (num_Ship == 1) //перед нами субмарина
		{
			//infile >> a >> b >> c >> d >> e;
			getline(infile, a);
			getline(infile, b);
			getline(infile, c);
			getline(infile, d);
			getline(infile, e);
			Submarine* book;
			book = new Submarine;
			book->set_length(a);
			book->set_width(a);
			book->set_crew(b);
			book->set_time(c);
			book->set_armament(d);
			book->set_speed(e);
			Ships = book;
			insert(Ships);
		}
		if (num_Ship == 2) //перед нами парусник
		{
			//infile >> a >> b >> c >> d >> e >> f;
			getline(infile, a);
			getline(infile, b);
			getline(infile, c);
			getline(infile, d);
			getline(infile, e);
			getline(infile, f);
			Sailboat* sailboat;
			sailboat = new Sailboat;
			sailboat->set_name(a);
			sailboat->set_type(b);
			sailboat->set_purpose(c);
			sailboat->set_length(d);
			sailboat->set_crew(e);
			sailboat->set_speed(f);
			Ships = sailboat;
			insert(Ships);
		}
		if (num_Ship == 3) //перед нами катер
		{
			//infile >> a >> b >> c>>e;
			getline(infile, a);
			getline(infile, b);
			getline(infile, c);
			getline(infile, d);
			Speedboat* speedboat;
			speedboat = new Speedboat;
			speedboat->set_capacity(a);
			speedboat->set_material(b);
			speedboat->set_purpose(c);
			speedboat->set_speed(d);
			Ships = speedboat;
			insert(Ships);
		}
	}
}
#pragma once
#include "lib.h"
class Keeper
{
private:
	int m_size = 0;
	Elem* head = NULL;
public:
	Keeper();
	Keeper(int size);
	~Keeper();
	Ship* operator[] (int index);
	int get_size();
	void insert(Ship* n_data); //���������� � ������ ����� ��������
	void remove(int index);
	void save(); //��������� � ����
	void load(); //������ �� �����
};
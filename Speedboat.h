#pragma once
#include "lib.h"
class Speedboat : public Ship
{
private:
	string capacity;
	string material;
	string purpose;
	string speed;
public:
	Speedboat();
	~Speedboat();
	Speedboat(const Speedboat& Speedboat_copy);
	Speedboat(string name);
	string get_capacity() const;
	void set_capacity(string capacity_ch);
	string get_material() const;
	void set_material(string material_ch);
	string get_purpose() const;
	void set_purpose(string purpose_ch);
	string get_speed() const;
	void set_speed(string speed_ch);
	virtual void show();
	virtual void rewrite();
	virtual void saving();
	virtual void redact_str(int num_str, string red_str);
	virtual bool SameSpeed(string SS_ch);
};
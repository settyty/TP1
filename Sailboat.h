#pragma once
#include "lib.h"
class Sailboat : public Ship
{
private:
	string name;
	string type;
	string purpose;
	string length;
	string crew;
	string speed;
public:
	Sailboat();
	~Sailboat();
	Sailboat(const Sailboat& Sailboat_copy);
	Sailboat(string name);
	string get_name() const;
	void set_name(string name_ch);
	string get_type() const;
	void set_type(string type_ch);
	string get_purpose() const;
	void set_purpose(string purpose_ch);
	string get_length() const;
	void set_length(string length_ch);
	string get_crew() const;
	void set_crew(string crew_ch);
	string get_speed() const;
	void set_speed(string speed_ch);
	virtual void show();
	virtual void rewrite();
	virtual void saving();
	virtual void redact_str(int num_str, string red_str);
	virtual bool SameSpeed(string SS_ch);
};
#pragma once
#include "lib.h"
class Submarine : public Ship
{
private:
	string length;
	string width;
	string crew;
	string time; //under water in days
	string armament;
	string speed;
public:
	Submarine();
	Submarine(string name);
	~Submarine();
	Submarine(const Submarine& Submarine_copy);
	string get_length() const;
	void set_length(string length_ch);
	string get_width() const;
	void set_width(string width_ch);
	string get_crew() const;
	void set_crew(string crew_ch);
	string get_time() const;
	void set_time(string time_ch);
	string get_armament() const;
	void set_armament(string armament_ch);
	string get_speed() const;
	void set_speed(string speed_ch);
	virtual void show();
	virtual void rewrite();
	virtual void saving();
	virtual void redact_str(int num_str, string red_str);
	virtual bool SameSpeed(string SS_ch);
};
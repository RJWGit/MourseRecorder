#ifndef H_Event
#define H_Event
#include <iostream>
#include<string>
#include <chrono>
using namespace std;
using namespace std::chrono;

class Event
{
public:
	Event();

	//Set
	void setname(string name) { _name = name; }
	void settime(nanoseconds time) { _time = time; }
	void setx(int x) { _x = x; }
	void sety(int y) { _y = y; }
	void setkey(int key) { _keyinput = key; }

	//Get
	int getx() { return _x; }
	int gety() { return _y; }
	int getkey() { return _keyinput; }
	nanoseconds gettime() { return _time; }
	string getname() { return _name; }
private:
	string _name;
	nanoseconds _time;
	int _keyinput;
	int _x;
	int _y;


};
#endif

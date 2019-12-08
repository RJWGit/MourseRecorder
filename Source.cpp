#include<iostream>
#include<chrono>
#include<vector>
#include"Event.h"
#include <Windows.h>
using namespace std;
using namespace std::chrono;

vector<Event> tempscript;
vector<vector<Event>> allscript;

void menu();
void record();
void playback();

int main()
{

	char choice;
	bool loop = true;

	while (loop)
	{
		menu();
		cin >> choice;
		
		switch (choice)
		{

			//Play back
			case '1':
			{
				playback();
				break;
			}
			//Record script
			case '2':
			{
				record();
				break;
			}

			case '3':
			{
				loop = false;
				break;
			}

		}

	}
	
	
	

}


void menu()
{
	cout << "(1):Play back a script\n" << endl;
	cout << "(2):Record new script\n" << endl;
	cout << "(3):Quit\n" << endl;

}
void record()
{

	//Prestart loop
	bool loop = true;
	

	//Recording loop
	bool ON = false;

	tempscript.clear();

	cout << "Press * to start recording when ready and press + when you're done recording\n";

	//Get pointer postion
	POINT apoint;
	GetCursorPos(&apoint);

	//set pointer;
	int lastx = apoint.x;
	int lasty = apoint.y;

	//Clocks
	steady_clock::time_point first;
	steady_clock::time_point last;
	steady_clock::duration time;

	//Timers for mouse buttons
	nanoseconds lefttime=steady_clock::duration::zero();
	nanoseconds righttime= steady_clock::duration::zero();
	nanoseconds rightarr= steady_clock::duration::zero();
	nanoseconds leftarr = steady_clock::duration::zero();
	nanoseconds uparr = steady_clock::duration::zero();
	nanoseconds downarr = steady_clock::duration::zero();


	while (loop)
	{

		
		 
		//Start script
		if (GetAsyncKeyState(VK_MULTIPLY))
		{
			system("cls");

			ON = true;
			loop = false;


			//Clocks
			first = steady_clock::now();
			last = steady_clock::now();
			time = steady_clock::duration::zero();
				
			
			//Get pointer postion
			GetCursorPos(&apoint);

			//set pointer;
			lastx = apoint.x;
			lasty = apoint.y;
			
		}



		while (ON)
		{
			Event tempob;
			GetCursorPos(&apoint);
			last = steady_clock::now();
			time = (last - first);

			if (lastx != apoint.x)
			{
				//Update clock
				last = steady_clock::now();
				time = (last - first);
				
				//Set object
				tempob.setx(apoint.x);
				tempob.sety(apoint.y);
				tempob.settime(time);
				tempscript.push_back(tempob);

				//Update 
				lastx = apoint.x;
				lasty = apoint.y;
				GetCursorPos(&apoint);


			}

			if (lasty != apoint.y)
			{
				//Update clock
				last = steady_clock::now();
				time = (last - first);
				

				//Set object
				tempob.setx(apoint.x);
				tempob.sety(apoint.y);
				tempob.settime(time);
				tempscript.push_back(tempob);

				//Update 
				lastx = apoint.x;
				lasty = apoint.y;
				GetCursorPos(&apoint);

			}
			//Left
			if (GetAsyncKeyState(0x25) && ((time.count() - leftarr.count())>40000000))
			{
				//Update clock
				last = steady_clock::now();
				time = (last - first);
				leftarr = time;

				//Set object
				tempob.setx(apoint.x);
				tempob.sety(apoint.y);
				tempob.settime(time);
				tempob.setkey(0x25);
				tempscript.push_back(tempob);

				//Update 
				lastx = apoint.x;
				lasty = apoint.y;
				GetCursorPos(&apoint);
			}
			//Up
			if (GetAsyncKeyState(0x26) && ((time.count() - uparr.count())>40000000))
			{
				//Update clock
				last = steady_clock::now();
				time = (last - first);
				uparr = time;

				//Set object
				tempob.setx(apoint.x);
				tempob.sety(apoint.y);
				tempob.settime(time);
				tempob.setkey(0x26);
				tempscript.push_back(tempob);

				//Update 
				lastx = apoint.x;
				lasty = apoint.y;
				GetCursorPos(&apoint);
			}
			//Right
			if (GetAsyncKeyState(0x27) && ((time.count() - rightarr.count())>40000000))
			{
				//Update clock
				last = steady_clock::now();
				time = (last - first);
				rightarr = time;
				
				//Set object
				tempob.setx(apoint.x);
				tempob.sety(apoint.y);
				tempob.settime(time);
				tempob.setkey(0x27);
				tempscript.push_back(tempob);
				
				//Update 
				lastx = apoint.x;
				lasty = apoint.y;
				GetCursorPos(&apoint);
			}
			//Down
			if (GetAsyncKeyState(0x28) && ((time.count() - downarr.count())>40000000))
			{
				//Update clock
				last = steady_clock::now();
				time = (last - first);
				downarr = time;

				//Set object
				tempob.setx(apoint.x);
				tempob.sety(apoint.y);
				tempob.settime(time);
				tempob.setkey(0x28);
				tempscript.push_back(tempob);

				//Update 
				lastx = apoint.x;
				lasty = apoint.y;
				GetCursorPos(&apoint);
			}

			//Mouse left
			if (GetAsyncKeyState(0X01)&&((time.count()-lefttime.count())>200000000))
			{


				//Update clock
				last = steady_clock::now();
				time = (last - first);
				lefttime = time;

				//Set object
				GetCursorPos(&apoint);
				tempob.setx(apoint.x);
				tempob.sety(apoint.y);
				tempob.settime(time);
				tempob.setkey(0X01);
				tempscript.push_back(tempob);

				//Update 
				lastx = apoint.x;
				lasty = apoint.y;
				GetCursorPos(&apoint);


			}
			//Mouse Right
			if (GetAsyncKeyState(0X02)&&((time.count() - righttime.count())>200000000))
			{
				//Update clock
				last = steady_clock::now();
				time = (last - first);
				righttime = time;
				//Set object
				GetCursorPos(&apoint);

				tempob.setx(apoint.x);
				tempob.sety(apoint.y);
				tempob.settime(time);
				tempob.setkey(0X02);
				tempscript.push_back(tempob);

				//Update 
				lastx = apoint.x;
				lasty = apoint.y;
				GetCursorPos(&apoint);
			}

			if (GetAsyncKeyState(VK_ADD)&&time.count()>3000000000)
			{

				//Set vector name to desired name to 0th element only
				string name;

				cout << "What is the name of this script?(Keep it simple so you can look it up later)\n";
				cin >> name;
				tempscript[0].setname(name);

				ON = false;
			}

		}

	}
}
void playback()
{

	//Clocks
	steady_clock::time_point first;
	steady_clock::time_point last;
	steady_clock::duration time;
	

	//Init clocks
	first = steady_clock::now();
	last = steady_clock::now();
	time = steady_clock::duration::zero();
	
	bool loop;

	for (int i = 0; i < tempscript.size(); i++)
	{
		loop = true;

		if (GetAsyncKeyState(VK_MULTIPLY))
		{
			break;
		}

		while (loop)
		{
			last = steady_clock::now();
			//time = (last - first);
			if (tempscript[i].gettime() <= (last-first))
			{
				loop = false;

				SetCursorPos(tempscript[i].getx(), tempscript[i].gety());

				switch (tempscript[i].getkey())
				{
				case 0x01:
					{
						mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
						break;
					}

				case 0X02:
					{
						mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
						break;
					}
			
				case 0x25:
					{
						keybd_event(VK_LEFT,0,0,0);
						keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);

					}

				case 0x26:
				    {
						keybd_event(VK_UP, 0, 0, 0);
						keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);

					}

				case 0x27:
					{
						keybd_event(VK_RIGHT, 0, 0, 0);
						keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);

					}

				case 0x28:
					{
						keybd_event(VK_DOWN, 0, 0, 0);
						keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);

					}
				}
			}
		}
	}
}
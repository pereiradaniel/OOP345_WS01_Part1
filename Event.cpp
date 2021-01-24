#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>

#include "Event.h"
#include <cstring>

using namespace std;

unsigned int g_sysClock = 0;

namespace sdds {
	Event::Event() {
		secMidnight = 0;
		description = nullptr;
	}

	void Event::display() {
		static int counter = 1;

		int h = 0;
		int m = 0;
		int s = 0;

		h = secMidnight / 3600;
		m = (secMidnight - (h * 3600)) / 60;
		s = (secMidnight - (h * 3600) - (m * 60));
		
		cout << setw(3) << setfill(' ') << counter++ << ".";

		if (description != nullptr && description[0] != ' ')
		{
			cout << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') << m << ":" << setw(2) << setfill('0') << s << " => " << description << endl;
		}
		else
		{
			cout << "| No Event |" << endl;
		}
	}

	void Event::set(const char* src) {
		if (src != nullptr && src[0] != ' ')
		{
			description = new char[strlen(src) + 1];
			strcpy(description, src);
			secMidnight = g_sysClock;
		}
		else
		{
			description = nullptr;
			//delete[] description;
		}
	}

	void Event::set() {
		secMidnight = 0;
		//description = nullptr;
		//delete[] description;
	}

	Event::~Event() {
		delete[] description;
	}
}
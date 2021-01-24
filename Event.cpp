#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "event.h"
#include <cstring>
using namespace std;

unsigned int g_sysClock = 0;

namespace sdds {
	Event::Event() {
		time = 0;
		description = nullptr;
	}

	void Event::display() {
		static int counter = 1;

		int h = 0;
		int m = 0;
		int s = 0;

		h = time / 3600;
		m = (time - (h * 3600)) / 60;
		s = (time - (h * 3600) - (m * 60));

		cout << setw(2) << setfill(' ') << counter++ << ". ";

		if (description != nullptr && description[0] != '\0')
		{
			cout << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') << m << ":" << setw(2) << setfill('0') << s << " => " << description << endl;
		}
		else
		{
			cout << "| No Event |" << endl;
		}
	}

	void Event::set(const char* src) {
		if (src != nullptr && src[0] != '\0')
		{
			description = new char[strlen(src) + 1];
			strcpy(description, src);
			time = g_sysClock;
		}
		else
		{
			delete[] description;
			description = nullptr;
		}
	}

	void Event::set() {
		time = 0;
		if (description != nullptr && description[0] != '\0') {
			description = nullptr;
		}
	}

	Event::~Event() {
		description = nullptr;
		delete[] description;
	}
}

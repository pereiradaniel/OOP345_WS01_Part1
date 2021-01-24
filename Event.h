#ifndef EVENT_H
#define EVENT_H

extern unsigned int g_sysClock;

namespace sdds {
	class Event
	{
		char* description;	// event description
		unsigned int time;	// number of seconds after midnight

	public:
		Event();
		~Event();
		void display();
		void set(const char* src);
		void set();
	};
}
#endif

#ifndef GAME_H
#define GAME_H

#include <chrono>

#include <gtkmm/drawingarea.h>

#include "items.h"


class Game : public Gtk::DrawingArea
{
public:
	Game();
	virtual ~Game();
	
protected:	
	bool on_timeout();
	
	//class creation timestamp
	std::chrono::steady_clock::time_point t;
	//milliseconds elapsed  since class creation
	double get_time();
};

#endif // GAME_H	
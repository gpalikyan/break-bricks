#ifndef GAME_H
#define GAME_H

#include <gtkmm/drawingarea.h>

#include "items.h"

class Game : public Gtk::DrawingArea
{
public:
	Game();
	virtual ~Game();

protected:	
	bool on_timeout();
};

#endif // GAME_H	
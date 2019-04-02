#ifndef BREAK_BRICKS_H
#define BREAK_BRICKS_H

#include "game.h"
#include "items.h"

// BreakBricks
class BreakBricks : public Game
{
private: 
	std::vector<Item *> items;
	bool right_key_pressed;
	bool left_key_pressed;
protected:
	void render();
public:
	BreakBricks();	
	~BreakBricks();
	
	//for platform moving
	void arrow_keys_handler();
	
	//event handlers
	bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
	bool on_key_press_event (GdkEventKey* key_event) override;
	bool on_key_release_event (GdkEventKey* key_event) override;
	
};

#endif // BREAK_BRICKS_H
#ifndef BREAK_BRICKS_H
#define BREAK_BRICKS_H

#include "game.h"
#include "items.h"

// BreakBricks
class BreakBricks : public Game
{
private: 
	std::vector<Item *> items;
protected:
	void render();
public:
	BreakBricks();	
	~BreakBricks();
	
	bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
	/*void key_press(unsigned int keyval);
	void key_release(unsigned int keyval);*/
};

#endif // BREAK_BRICKS_H
#include "break_bricks.h"

#include <iostream>

BreakBricks::BreakBricks():left_key_pressed(false), right_key_pressed(false)
{
	double t = this->get_time();
	this->items.push_back(new Item({0,0,0, t}, {0,0,0, t}, PLATFORM));
}

BreakBricks::~BreakBricks()
{
	for (auto item : this->items)
		delete item;
}

bool BreakBricks::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{	
	double t = this->get_time();
	
	Gtk::Allocation allocation = get_allocation();
	const int width = allocation.get_width();
	const int height = allocation.get_height();

	// scale to unit square and translate (0, 0) to be (0.5, 0.5), i.e.
	// the center of the window
	cr->scale(width, height);
	cr->translate(0.0, 0.0);
	

	for (Item *item : this->items)
	{
		switch (item->get_item_type())
		{
			case PLATFORM:	
		
				cr->set_source_rgb(0, 0, 0);
				cr->set_line_width(0.01);
				cr->rectangle(item->get_x(t), 0.95, 0.2, 0.04);
				cr->stroke();
				
				break;
		}	
	}		
	return true;
}



bool BreakBricks::on_key_press_event(GdkEventKey* key_event)
{	
	switch (key_event->keyval)
	{
		case GDK_KEY_Right:	
			if (right_key_pressed)
				break;
			right_key_pressed = true;
			arrow_keys_handler();
			break;	
		case GDK_KEY_Left:
			if (left_key_pressed)
				break;		
			left_key_pressed = true;
			arrow_keys_handler();
			break;
	}
	return true;
}

bool BreakBricks::on_key_release_event(GdkEventKey* key_event)
{		
	switch (key_event->keyval)
	{
		case GDK_KEY_Right:	
			right_key_pressed = false;
			arrow_keys_handler();
			break;	
		case GDK_KEY_Left:		
			left_key_pressed = false;
			arrow_keys_handler();
			break;
	}	
	return true;
}

void BreakBricks::arrow_keys_handler()
{
	Item *platform;
	motion_vector_t mvx;
	double x;
	double t = this->get_time();
	
	//finding PLATFORM item and storing its motion_vector_x and x coord
	for (Item *item : this->items)
		if (item->get_item_type() == PLATFORM)
		{
			platform = item;
			break;
		}
	//TODO should return calculated V as x calculates by get_x()
	mvx = platform->get_motion_vector_x();
	x = platform->get_x(t);
		
	//some math and kinematics
	mvx.t0 = t;
	mvx.p = x;
		
	
	if (left_key_pressed && right_key_pressed)
		mvx.a = 0;
	else if (left_key_pressed)
		mvx.a = -1e-5;
	else if (right_key_pressed)
		mvx.a = 1e-5;
	else
		mvx.a = 0;
	
	//assign motion vector to platform
	platform->set_motion_vector_x(mvx);
	
}

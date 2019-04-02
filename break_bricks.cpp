#include "break_bricks.h"

#include <iostream>

BreakBricks::BreakBricks():left_key_pressed(false), right_key_pressed(false)
{
	double t = this->get_time();
	this->items.push_back(new Item({0,0,0, t}, {0,0,0, t}, PLATFORM));
	this->items.push_back(new Item({0.5,0,0, t}, {0.5,0.0004,0, t}, CANNONBALL));
}

BreakBricks::~BreakBricks()
{
	for (auto item : this->items)
		delete item;
}

bool BreakBricks::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{	
	double t = this->get_time();
	Item *item_platform = NULL;
	Item *item_cannonball = NULL;
	
	Gtk::Allocation allocation = get_allocation();
	const int    width             = allocation.get_width();
	const int    height			   = allocation.get_height();
	const double cannonball_radius = 0.02;
	const double platform_top      = 0.95;
	const double platform_width    = 0.2;

	// scale to unit square and translate (0, 0) to be (0.5, 0.5), i.e.
	// the center of the window
	cr->scale(width, height);
	cr->translate(0.0, 0.0);
	
	//drawing items
	for (Item *item : this->items)
	{
		switch (item->get_item_type())
		{
			case PLATFORM:	
			
				cr->set_source_rgb(0, 0, 0);
				cr->set_line_width(0.01);
				cr->rectangle(item->get_x(t), platform_top, platform_width, 0.04);
				cr->stroke();
				
				item_platform = item;
				break;
				
			case CANNONBALL:	
		
				cr->set_source_rgb(0, 0, 0);
				cr->set_line_width(0.01);
				cr->arc(item->get_x(t), item->get_y(t), cannonball_radius, 0, 2*G_PI);
				cr->stroke();
				
				item_cannonball = item;
				break;
		}	
	}		
		
	//cannonball collision detection 
	motion_vector_t mvx		 = item_cannonball->get_motion_vector_x();
	motion_vector_t mvy      = item_cannonball->get_motion_vector_y();
	double cannonball_left   = item_cannonball->get_x(t) - cannonball_radius;
	double cannonball_right  = item_cannonball->get_x(t) + cannonball_radius;
	double cannonball_bottom = item_cannonball->get_y(t) + cannonball_radius;
	double cannonball_top    = item_cannonball->get_y(t) - cannonball_radius;
	double platform_left     = item_platform->get_x(t);
	double platform_right    = item_platform->get_x(t) + platform_width;
	
	//with platform
	if (cannonball_bottom >= platform_top)
	{
		//with top section
		if ((cannonball_right >= platform_left)&&(cannonball_left <= platform_right))
		{
			mvy.p = item_cannonball->get_y(t) - 1e-2;
			mvy.t0 = t;
			mvy.v = -mvy.v;
			
			//adding platform vx to cannonball vx
			motion_vector_t platform_mvx = item_platform->get_motion_vector_x();
			if ((platform_mvx.v > 0)&&(abs(mvx.v) <= 0.0005))
				mvx.v += platform_mvx.v/4;
			if ((platform_mvx.v < 0)&&(abs(mvx.v) >= -0.0005))
				mvx.v += platform_mvx.v/4;
			mvx.t0 = t;
			mvx.p = item_cannonball->get_x(t);
			
			item_cannonball->set_motion_vector_y(mvy);
			item_cannonball->set_motion_vector_x(mvx);
		} 		
	}
	//with walls
	//with top wall
	if (cannonball_top <= (double)0.0)
	{
		mvy.p = item_cannonball->get_y(t) + 1e-2;
		mvy.t0 = t;
		mvy.v = -mvy.v;
		
		item_cannonball->set_motion_vector_y(mvy);
	}
	//width left or right wall
	if (cannonball_left <= (double)0.0)
	{
		mvx.p = item_cannonball->get_x(t) + 1e-2;
		mvx.t0 = t;
		mvx.v = -mvx.v;
		
		item_cannonball->set_motion_vector_x(mvx);
	}
	if (cannonball_right >= (double)1.0)
	{
		mvx.p = item_cannonball->get_x(t) - 1e-2;
		mvx.t0 = t;
		mvx.v = -mvx.v;
		
		item_cannonball->set_motion_vector_x(mvx);
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
		mvx.v = 0;
	else if (left_key_pressed)
		mvx.v = -0.001;
	else if (right_key_pressed)
		mvx.v = 0.001;
	else
		mvx.v = 0;
	
	//assign motion vector to platform
	platform->set_motion_vector_x(mvx);
	
}

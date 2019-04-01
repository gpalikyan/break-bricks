#include "break_bricks.h"


BreakBricks::BreakBricks()
{
	this->items.push_back(new Item({0,0,0}, {0,0,0}, PLATFORM));
}

BreakBricks::~BreakBricks()
{
	for (auto item : this->items)
		delete item;
}

//   ---------------------- TODO: add mutex, exit from while by exit event
// --------- TODO зачем нужен surface???
bool BreakBricks::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
	Gtk::Allocation allocation = get_allocation();
	const int width = allocation.get_width();
	const int height = allocation.get_height();

	double m_line_width = 0.05;
	double m_radius = 0.42;
	// scale to unit square and translate (0, 0) to be (0.5, 0.5), i.e.
	// the center of the window
	cr->scale(width, height);
	cr->translate(0.5, 0.5);
	cr->set_line_width(m_line_width);

	for (Item *item : this->items)
	{
		switch (item->get_item_type())
		{
			case PLATFORM:	
		
				//cairo_set_source_rgb (cr, 0.5, 0.4, 1);
				//cairo_paint (cr);
				
				//this->redraw_window();
				int i = 5;
				break;
		}	
	}		
	return true;
}

/*
void BreakBricks::key_press(unsigned int keyval)
{
	std::cout << "pressed keyval n " << keyval << std::endl;
}

void BreakBricks::key_release(unsigned int keyval)
{		
	std::cout << "released keyval n " << keyval << std::endl;
}*/
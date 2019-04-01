#include <ctime>
#include <cmath>
#include <cairomm/context.h>
#include <glibmm/main.h>

#include "game.h"

Game::Game()
{
  Glib::signal_timeout().connect( sigc::mem_fun(*this, &Game::on_timeout), 1000 );
}

Game::~Game()
{
}

bool Game::on_timeout()
{
  // force our program to redraw the entire clock.
    auto win = get_window();
    if (win)
    {
        Gdk::Rectangle r(0, 0, get_allocation().get_width(), get_allocation().get_height());
        win->invalidate_rect(r, false);
    }
    return true;
}
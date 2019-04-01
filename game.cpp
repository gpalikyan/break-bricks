#include <chrono>

#include <cairomm/context.h>
#include <glibmm/main.h>

#include "game.h"

#define GAME_DRAW_TIMEOUT_TIMER_SCALE 10

Game::Game()
{
  Glib::signal_timeout().connect( sigc::mem_fun(*this, &Game::on_timeout), GAME_DRAW_TIMEOUT_TIMER_SCALE);
  this->t = std::chrono::steady_clock::now();
  //needs for recieve key press events
  this->set_can_focus(true);
}

Game::~Game()
{
}

bool Game::on_timeout()
{
  // force our program to redraw the entire window.
    auto win = get_window();
    if (win)
    {
        Gdk::Rectangle r(0, 0, get_allocation().get_width(), get_allocation().get_height());
        win->invalidate_rect(r, false);
    }
    return true;
}

double Game::get_time()
{
	auto t1 = std::chrono::steady_clock::now();
	auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(t1-(this->t));
	return dur.count();
}
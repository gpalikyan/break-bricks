#include <gtkmm/application.h>
#include <gtkmm/window.h>

#include "break_bricks.h"

int main(int argc, char** argv)
{
   auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

   Gtk::Window win;
   win.set_title("Break Bricks");

   BreakBricks bb;
   win.add(bb);
   bb.show();

   return app->run(win);
}
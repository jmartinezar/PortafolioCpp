#include <gtkmm.h>

int main(int argc, char *argv[])
{
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc,argv,"gtkmm tutorial");
  Gtk::Window window;
  window.set_default_size(200,200);
  window.set_title("Hello, World!");

  Gtk::Label label("Hello, World!");
  window.add(label);
  
  return app->run(window);
}

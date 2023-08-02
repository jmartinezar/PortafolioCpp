#include <gtkmm.h>

class Interfaz: public Gtk::Window
{
public:
  Interfaz()
  {
    set_title("Gnuplot");
    set_default_size(400,400);

    cuadroTexto.set_placeholder_text("Ingrese una función a graficar...");

    add(cuadroTexto);

    show_all();
  }

private:
  Gtk::Entry cuadroTexto;
};

int main(int argc, char *argv[])
{
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "gnuplotgui");
  Interfaz interfaz;
  
  return app->run(interfaz);
}

/* ---------------Librerías utilizadas---------------- */

#include <gtkmm.h> //Librería Gtkmm para interfaz gráfica en C++
#include <iostream>
#include <gtkmm/grid.h>

/*Se define la interfaz a crear como un objeto que hereda funciones de la clase Gtk::Window*/

class Interfaz: public Gtk::Window
{
public:
  Interfaz(){
    
    /* ------------Se inicializa la interfaz---------------- */
    
    set_title("Gnuplot"); 
    set_default_size(400,400); 
  
    /* ------------Se crea un cuadro de texto para ingresar funciones a graficar------------ */
    
    cuadroTexto.set_placeholder_text("Plot function"); 
    
    /* ---------Se define un menú desplegable para definir el grosor de la función graficada--------------- */
    
    comboWidth.append("Default"); 
    comboWidth.append("2"); 
    comboWidth.append("3"); 
    comboWidth.append("4"); 

    comboWidth.set_active(0); 
    
    comboWidth.signal_changed().connect(sigc::mem_fun(*this, &Interfaz::on_combo_changed)); 

    /* --------------Se define un botón para graficar----------------------- */
    
    GraphButton.set_label("Graph");
    GraphButton.signal_clicked().connect(sigc::mem_fun(*this, &Interfaz::on_boton_ejecutar_clicked));
    
  /* --------------Se agrupan el cuadro de texto y el menú desplegable en una malla----------- */
    
    Gtk::Grid grid;
    grid.set_row_spacing(5);
    grid.set_column_spacing(5);

    grid.attach(cuadroTexto, 1, 0, 3, 1);
    grid.attach(comboWidth, 1, 2, 2, 1);
    grid.attach(GraphButton, 1, 4, 2, 1);
    
    add(grid);

    show_all_children();
  }
  

private:
  Gtk::Entry cuadroTexto;
  Gtk::ComboBoxText comboWidth;
  Gtk::Button GraphButton;
  
  Glib::ustring SelectedWidth_;

  void on_combo_changed()
  {
    SelectedWidth_ = comboWidth.get_active_text();
    if(SelectedWidth_ == "Default"){
      SelectedWidth_ = ' ';
    } else {
      SelectedWidth_ = "lw "+SelectedWidth_;
    }
  }

  void on_boton_ejecutar_clicked()
  {
    Glib::ustring InputText = cuadroTexto.get_text();
    Glib::ustring ConcText = "plot "+InputText+SelectedWidth_+"| gnuplot";

    std::cout << ConcText << std::endl;
    }
};

int main(int argc, char *argv[])
{
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "gnuplotgui");

  Interfaz interfaz;
  
  return app->run(interfaz);
}

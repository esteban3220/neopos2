#include "proveedor.cpp"
#include "sqlite.hpp"
#include <fstream>

int main(int argc, char *argv[])
{

    /*
    std::ifstream file("etc/database.db");
    if (file.good())
    {
        auto db = std::make_unique<SQLite>();
        if (!db->open())
        {
            std::cout << "Error al abrir la base de datos" << std::endl;
            return EXIT_FAILURE;
        }
    }
    else
    {
        Gtk::Main kit(argc, argv);
        auto app = std::make_unique<Bienvenida>();
        app->run();
        Gtk::Main::run();
        return EXIT_SUCCESS;
    }
    */
    auto app = Gtk::Application::create("org.gtkmm.examples.base");
    return app->make_window_and_run<Pos>(argc, argv);
}
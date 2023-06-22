#include "proveedor.cpp"
#include <fstream>

int main(int argc, char *argv[])
{

    // std::ifstream file("dbase.db");
    // if (file.good())
    // {
    //     auto db = std::make_unique<SQLite>();
    //     if (!db->open())
    //     {
    //         std::cout << "Error al abrir la base de datos" << std::endl;
    //         return EXIT_FAILURE;
    //     }
    //     db->command("SELECT * FROM proveedor");
    //     auto result = db->get_result();
    //     for (auto row : result)
    //     {
    //         for (auto col : row)
    //         {
    //             std::cout << col << " - ";
    //         }
    //         std::cout << std::endl;
    //     }
    // }

    auto app = Gtk::Application::create("org.gtkmm.examples.base");
    return app->make_window_and_run<Pos>(argc, argv);
}
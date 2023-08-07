#include "proveedor.cpp"
#include <fstream>

int main(int argc, char *argv[])
{

    auto app = Gtk::Application::create("Neo Pos");
    return app->make_window_and_run<Pos>(argc, argv,app);
}
#include "builder.hpp"

Builder::Builder()
{
    try
    {
        m_refBuilder = Gtk::Builder::create_from_file("../test/neopos.ui");
    }
    catch (const Glib::FileError &ex)
    {
        std::cerr << "FileError: " << ex.what() << std::endl;
    }
    catch (const Glib::MarkupError &ex)
    {
        std::cerr << "MarkupError: " << ex.what() << std::endl;
    }
    catch (const Gtk::BuilderError &ex)
    {
        std::cerr << "BuilderError: " << ex.what() << std::endl;
    }
}

Builder::Builder(std::string glade_file)
{
    try
    {
        m_refBuilder = Gtk::Builder::create_from_file(glade_file);
    }
    catch (const Glib::FileError &ex)
    {
        std::cerr << "FileError: " << ex.what() << std::endl;
    }
    catch (const Glib::MarkupError &ex)
    {
        std::cerr << "MarkupError: " << ex.what() << std::endl;
    }
    catch (const Gtk::BuilderError &ex)
    {
        std::cerr << "BuilderError: " << ex.what() << std::endl;
    }
}

Builder::~Builder()
{
    std::cout << "Builder destroyed" << std::endl;
}
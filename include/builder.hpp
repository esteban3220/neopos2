#pragma once

#include <gtkmm.h>
#include <iostream>

class Builder
{
public:
    Builder();
    Builder(std::string glade_file);
    ~Builder();
    Glib::RefPtr<Gtk::Builder> m_refBuilder;    
};


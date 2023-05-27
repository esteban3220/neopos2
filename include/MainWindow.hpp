#include <gtkmm.h>

class MainWindow : public Gtk::Window
{   
    public:
        MainWindow();
        virtual ~MainWindow();

    protected:
        //Signal handlers:
        void on_button_clicked();

        //Member widgets:
        Gtk::Button m_button;
};
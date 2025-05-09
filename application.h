#ifndef APPLICATION_H
#define APPLICATION_H

#include <gtkmm/application.h>

class AppWindow;

class Application : public Gtk::Application {
protected:
    Application();

public:
    static Glib::RefPtr<Application> create();
    
    void create_app_window();
    void broadcast_message(const Glib::ustring& message);

protected:
    void on_activate() override;
    void on_startup() override;
};

#endif
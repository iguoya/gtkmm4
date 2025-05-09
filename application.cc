#include "application.h"
#include "app_window.h"
#include <iostream>

Application::Application() 
    : Gtk::Application("org.gtkmm.complex.example", 
                      Gio::Application::Flags::HANDLES_COMMAND_LINE) {
}

Glib::RefPtr<Application> Application::create() {
    return Glib::make_refptr_for_instance<Application>(new Application());
}

void Application::on_startup() {
    Gtk::Application::on_startup();
    
    auto menu = Gio::Menu::create();
    menu->append("New Window", "app.new_window");
    menu->append("Quit", "app.quit");
    
    set_menubar(menu);
    
    add_action("new_window", [this]() { create_app_window(); });
    add_action("quit", [this]() { quit(); });
}

void Application::on_activate() {
    create_app_window();
}

void Application::create_app_window() {
    auto window = new AppWindow(Glib::RefPtr<Gtk::Application>(this));
    add_window(*window);
    window->present();
}

void Application::broadcast_message(const Glib::ustring& message) {
    std::cout << "Broadcasting: " << message << std::endl;
}
#ifndef APP_WINDOW_H
#define APP_WINDOW_H

#include <gtkmm/applicationwindow.h>
#include <gtkmm/builder.h>
#include <gtkmm/button.h>
#include <gtkmm/label.h>
#include "application.h"

class CustomDialog;

class AppWindow : public Gtk::ApplicationWindow {
public:
    explicit AppWindow(const Glib::RefPtr<Gtk::Application>& app);
    virtual ~AppWindow();
    
    void update_status(const Glib::ustring& message);

private:
    Glib::RefPtr<Gtk::Application> m_app;
    std::unique_ptr<CustomDialog> m_dialog;
    
    Gtk::Button* m_btn_open_dialog;
    Gtk::Button* m_btn_broadcast;
    Gtk::Label* m_lbl_status;
    
    void on_open_dialog();
    void on_broadcast();
    void on_dialog_response(int response_id);
};

#endif
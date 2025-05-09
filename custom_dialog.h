#ifndef CUSTOM_DIALOG_H
#define CUSTOM_DIALOG_H

#include <gtkmm/window.h>
#include <gtkmm/builder.h>
#include <gtkmm/button.h>
#include <gtkmm/entry.h>
#include "app_window.h"

class CustomDialog : public Gtk::Window {
public:
    explicit CustomDialog(AppWindow& parent);
    virtual ~CustomDialog();
    
    using type_signal_response = sigc::signal<void(int)>;
    type_signal_response signal_response();

private:
    AppWindow& m_parent;
    type_signal_response m_signal_response;
    
    Gtk::Button* m_btn_ok;
    Gtk::Button* m_btn_cancel;
    Gtk::Entry* m_entry;
    
    void on_ok();
    void on_cancel();
};

#endif
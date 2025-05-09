#include "app_window.h"
#include "custom_dialog.h"
#include <iostream>

AppWindow::AppWindow(const Glib::RefPtr<Gtk::Application>& app)
    : Gtk::ApplicationWindow(app),
      m_app(app) {
    
    auto builder = Gtk::Builder::create_from_file("ui/app_window.ui");
    
    m_btn_open_dialog = builder->get_widget<Gtk::Button>("btn_open_dialog");
    m_btn_broadcast = builder->get_widget<Gtk::Button>("btn_broadcast");
    m_lbl_status = builder->get_widget<Gtk::Label>("lbl_status");
    
    if (m_btn_open_dialog) {
        m_btn_open_dialog->signal_clicked().connect(
            sigc::mem_fun(*this, &AppWindow::on_open_dialog));
    }
    
    if (m_btn_broadcast) {
        m_btn_broadcast->signal_clicked().connect(
            sigc::mem_fun(*this, &AppWindow::on_broadcast));
    }
    
    set_title("Main Application Window");
    set_default_size(600, 400);
    
    auto main_widget = builder->get_widget<Gtk::Widget>("main_box");
    if (main_widget) {
        set_child(*main_widget);
    }
}

AppWindow::~AppWindow() {
    std::cout << "AppWindow destroyed" << std::endl;
}

void AppWindow::on_open_dialog() {
    m_dialog = std::make_unique<CustomDialog>(*this);
    m_dialog->signal_response().connect(
        sigc::mem_fun(*this, &AppWindow::on_dialog_response));
    m_dialog->show();
}

void AppWindow::on_broadcast() {
    // auto app = Glib::RefPtr<Application>(&m_app);
    // if (app) {
    //     app->broadcast_message("Message from window");
    // }
}

void AppWindow::on_dialog_response(int response_id) {
    std::cout << "Dialog response: " << response_id << std::endl;
    m_dialog.reset();
}

void AppWindow::update_status(const Glib::ustring& message) {
    if (m_lbl_status) {
        m_lbl_status->set_text("Last message: " + message);
    }
}
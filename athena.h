#pragma once

#include <gtkmm.h>
#include "mainwindow.h"

class Athena : public Gtk::Application {
  protected:
  Athena() : Gtk::Application("cn.yatiger.athena") {}

  void on_activate() override {
    auto builder = Gtk::Builder::create_from_resource("/app/window.ui");
    // auto window = builder->get_widget<MainWindow>("window");
    auto window = Gtk::Builder::get_widget_derived<MainWindow>(builder, "window");
    if (window) {
      add_window(*window);
      window->present();
    }
  }

public:
  static Glib::RefPtr<Athena> create() {
    // return Glib::RefPtr<Athena>(new Athena());
    return Glib::make_refptr_for_instance<Athena>(new Athena());
  }
};

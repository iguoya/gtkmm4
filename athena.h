#pragma once

#include <gtkmm.h>

class Athena : public Gtk::Application {
  protected:
  Athena() : Gtk::Application("cn.yatiger.athena") {}

  void on_activate() override {
    auto builder = Gtk::Builder::create_from_resource("/cn/yatiger/athena/window.ui");
    auto win = builder->get_widget<Gtk::ApplicationWindow>("window");
    if (win) {
      add_window(*win);
      win->present();
    }
  }

public:
  static Glib::RefPtr<Athena> create() {
    return Glib::RefPtr<Athena>(new Athena());
  }
};

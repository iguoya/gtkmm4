#pragma once

#include <gtkmm.h>

class Athena : public Gtk::Application {
  protected:
  Athena() : Gtk::Application("cn.yatiger.athena") {}

  void on_activate() override;

public:
  static Glib::RefPtr<Athena> create() {
    // return Glib::RefPtr<Athena>(new Athena());
    return Glib::make_refptr_for_instance<Athena>(new Athena());
  }
};

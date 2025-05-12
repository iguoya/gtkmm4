#pragma once

#include <gtkmm.h>

class MainWindow : public Gtk::ApplicationWindow {
public:
  MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder);
  virtual ~MainWindow() = default;

  static Glib::RefPtr<Gtk::Builder> create_builder();
};
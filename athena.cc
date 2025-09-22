#include "athena.h"
#include "mainwindow.h"

void Athena::on_activate() {
  auto builder = Gtk::Builder::create_from_resource("/app/window.ui");
  // auto window = builder->get_widget<MainWindow>("window");
  auto window = Gtk::Builder::get_widget_derived<MainWindow>(builder, "window");
  if (window) {
    add_window(*window);
    window->present();
  }
}